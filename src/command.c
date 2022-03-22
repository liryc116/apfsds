#include "command.h"

#include "utils/xmalloc.h"
#include "utils/queue.h"
#include "utils/error.h"
#include "token.h"
#include "redir.h"

#include <string.h>
#include <stdlib.h>
#include <err.h>
#include <sys/types.h>
#include <unistd.h>

int first_command(struct token *tok)
{
    // Check if not a fundec
    return tok->kind==ASSIGNMENT_WORD || tok->kind==WORD ||
        first_redir(tok);
}

struct command *command_new()
{
    struct command *c = xcalloc(1, sizeof(struct command));
    c->argv = xmalloc(sizeof(char *));

    return c;
}

void command_free(void *command)
{
    struct command *c = command;
    for(size_t i = 0; i<c->argc; i++)
        free(c->argv[i]);
    free(c->argv);
    free(c->redir);
    free(c);
}

void command_add_arg(struct command *c, struct token *tok)
{
    char *arg = tok->value;
    if(c->argv==NULL)
        c->argv = xmalloc(sizeof(char *));
    else
        c->argv = xreallocarray(c->argv, c->argc+1, sizeof(char *));
    size_t len = strlen(arg);
    c->argv[c->argc] = xcalloc(len+1, sizeof(char));
    strncpy(c->argv[c->argc], arg, len);
    c->argc+=1;
}

void command_add_redir(struct command *c, struct token *tok)
{
    if(!is_redir(tok))
        errx(1, "expected to add a redirection");
    c->redir = xreallocarray(c->redir, c->n_redir, sizeof(enum token_kind));
}

struct command *parse_simple_command(struct queue *q)
{
    struct token *tok = queue_peek(q);
    struct command *comm = command_new();
    int can_aword = 1;

    while(!queue_is_empty(q) && first_command(tok))
    {
        if(first_redir(tok) || tok->value==NULL)
            parse_redir(q, comm);
        else
        {
            can_aword = can_aword && tok->kind==ASSIGNMENT_WORD;
            if(!can_aword && tok->kind==ASSIGNMENT_WORD)
                parse_error(q, WORD);
            struct token *t = queue_pop(q);
            command_add_arg(comm, t);
            token_free(t);
        }

        tok = queue_peek(q);
    }

    return comm;
}

char **split_command(struct command *comm, size_t n)
{
    char **argv = xcalloc(1, sizeof(char *));
    size_t len = 1;
    char *tmp = strtok(comm->argv[n], " \t\v");
    while(tmp!=NULL)
    {
        argv = xreallocarray(argv, len+1, sizeof(char *));
        argv[len] = NULL;
        argv[len-1] = tmp;
        len+=1;
        tmp = strtok(NULL, " \t\v");
    }

    return argv;
}

void eval_command(struct command *comm, size_t n)
{
    pid_t pid = fork();
    if(pid==-1)
        errx(1, "Could not fork");
    else if(pid==0)
    {
        char **argv = split_command(comm, n);
        execvp("echo", argv);
        errx(1, "command execution failed");
    }
    else
    {
        if(n+1<comm->argc)
            eval_command(comm, n+1);
    }
}
