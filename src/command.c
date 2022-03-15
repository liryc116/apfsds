#include "command.h"

#include "utils/xmalloc.h"
#include "utils/queue.h"
#include "token.h"
#include "redir.h"

#include <string.h>
#include <err.h>

int is_first_command(struct token *tok)
{
    // Check if not a fundec
    return tok->kind==ASSIGNMENT_WORD || tok->kind==WORD ||
        first_redir(tok);
}

struct command *command_new()
{
    struct command *c = xcalloc(1, sizeof(struct command));

    return c;
}

void command_add_arg(struct command *c, struct token *tok)
{
    char *arg = tok->value;
    size_t len = strlen(arg)+1;
    c->argv = xreallocarray(c->argv, c->argc+1, sizeof(char *));
    c->argv[c->argc] = xmalloc(len*sizeof(char));
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
    struct command *comm = NULL;

    while(is_first_command(tok))
    {
        if(tok->kind==IO_NUMBER)
        {
            command_add_arg(comm, tok);
        }
        else if(first_redir(tok))
            parse_redir(q, comm);
        else
            command_add_arg(comm, tok);
    }

    return comm;
}
