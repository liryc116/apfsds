#include "node.h"

#include "utils/xmalloc.h"

#include <stdlib.h>

struct node *node_new(enum node_kind kind)
{
    struct node *node = xcalloc(1, sizeof(struct node));

    node->kind = kind;

    return node;
}

void node_add_command(struct node *node, struct command *com)
{
    if(node->commands==NULL)
        node->commands = xmalloc(sizeof(struct command *));
    else
        node->commands = xreallocarray(node->commands,
                node->n+1, sizeof(struct command *));
    node->commands[node->n] = com;
    node->n+=1;
}

void node_free(void *node)
{
    struct node *no = node;

    for(size_t i = 0; i<no->n; i++)
        command_free(no->commands[i]);
    free(no->commands);
    free(no);
}
