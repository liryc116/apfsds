#include "parser.h"

#include "utils/queue.h"
#include "utils/tree.h"
#include "token.h"
#include "node.h"
#include "command.h"

#include <err.h>
#include <stdlib.h>

struct tree *parser(struct queue *q)
{
    struct token *tok = queue_peek(q);
    struct node *node = node_new(LIST);
    while(!queue_is_empty(q))
    {
        if(first_command(tok))
                node_add_command(node,
                        parse_simple_command(q));
        else if(tok->kind==T_EOF)
            break;
        else
            errx(1, "unexpected not command");

        tok = queue_peek(q);
    }

    struct tree *res = tree_new(node, sizeof(struct node));
    free(node);
    return res;
}
