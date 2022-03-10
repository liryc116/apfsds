#ifndef NODE_H
#define NODE_H

#include "command.h"

#include <stddef.h>

enum kind
{
    OR,
    ELSE,
    IF,
};

struct node{
    enum kind node_kind;
    struct command *commands;
    size_t n;
};

struct node *node_new(enum kind node_kind);

void node_add_command(struct node *node, struct command *com);

#endif /* ! NODE_H */
