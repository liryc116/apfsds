#include "eval.h"

#include "node.h"
#include "command.h"

#include <stddef.h>

void eval_tree(struct tree *t)
{
    struct node *node = t->key;
    if(node->kind == LIST)
    {
        for(size_t i = 0; i<node->n; i++)
        {
            eval_command(node->commands[i], 0);
        }
    }
}
