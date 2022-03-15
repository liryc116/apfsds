#include "parser.h"

#include "utils/queue.h"
#include "token.h"
#include "command.h"

int eat(struct token *expected, struct token *have)
{
    return expected==have;
}

struct tree *parser(struct queue *q)
{
    struct tree *res = tree_new();
    struct token *tok = queue_pop(q);
    struct command comm;
    while(tok!=NULL)
    {
        if(tok->kind==WORD)
            command_add_arg(&comm, tok);
        else if(is_redir(tok))
            command_add_redir(&comm, tok);
        else
            tree_add_child();
        if(tok->kind==EOF)
                return NULL;
        else
        {
            parser(q)
        }

        tok = queue_pop(q);
    }

    return res;
}
