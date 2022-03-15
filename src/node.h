#ifndef NODE_H
#define NODE_H

#include "command.h"

#include <stddef.h>

enum node_kind
{
    LIST,
    AND,
    OR,
    IF,
    ELIF,
    FUNCTION,
};

struct node{
    enum node_kind kind;

    struct command **commands;
    size_t n;
};

struct node *node_new(enum node_kind kind);

void node_add_command(struct node *node, struct command *com);

#endif /* ! NODE_H */
