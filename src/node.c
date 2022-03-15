#include "node.h"

#include "utils/xmalloc.h"

struct node *node_new(enum node_kind kind)
{
    struct node *node = xcalloc(1, sizeof(struct node));

    node->kind = kind;

    return node;
}

void node_add_command(struct node *node, struct command *com)
{
    node->commands =
        xreallocarray(node->commands, node->n, sizeof(struct command *));
    node->commands[node->n] = com;
    node->n+=1;
}
