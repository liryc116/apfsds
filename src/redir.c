#include "redir.h"

#include "command.h"
#include "utils/queue.h"
#include "utils/error.h"

#include <string.h>

int is_redir(struct token *tok)
{
    enum token_kind k = tok->kind;
    return k==DLESS || k==DGREAT || k==GREATAND || k==LESSAND ||
        k==LESSGREAT || k==DLESSDASH || k==CLOBBER ||
        (k==OTHER &&
         (strcmp(tok->value, ">")==0 || strcmp(tok->value, "<")==0));
}

int first_redir(struct token *tok)
{
    return tok->kind==IO_NUMBER || is_redir(tok);
}

void parse_redir(struct queue *q, struct command *c)
{
    struct token *t = queue_peek(q);
    if(t->kind == IO_NUMBER)
    {
        command_add_arg(c, queue_pop(q));
        t = queue_peek(q);
    }
    if(!is_redir(t))
        parse_error(q, DLESS);

    struct token *tok = queue_pop(q);
    command_add_redir(c, tok);
    token_free(tok);

    t = queue_peek(q);

    if(t->kind != WORD)
        parse_error(q, WORD);
    command_add_arg(c, queue_pop(q));
}
