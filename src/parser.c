#include "parser.h"

#include "utils/queue.h"
#include "token.h"

struct tree *parser(struct queue *q)
{
    struct tree *res = tree_new();
    struct token *tok = queue_pop(q);
    struct command comm;
    while(tok!=NULL)
    {
        if(tok->kind==WORD)
            command_add_arg();
        else if(tok->kind==REDIR)
            command_add_redir();
        else
            tree_add_res();
    }

    return res;
}
