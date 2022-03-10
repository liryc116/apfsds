#include "node.h"

#include "utils/xmalloc.h"

#include <string.h>

struct node *node_new(enum kind node_kind)
{
    struct node *node = xmalloc(sizeof(struct node));

    node->node_kind = node_kind;
    node->n = 0;
    node->commands = NULL;

    return node;
}

void node_add_command(struct node *node, struct command *com)
{
    node->commands[node->n] = *com;
    node->n+=1;
}
