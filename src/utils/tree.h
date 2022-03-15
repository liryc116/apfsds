#ifndef TREE_H
#define TREE_H

#include <stddef.h>

struct tree
{
    void *key;
    void **children;
    size_t nb_children;
};

#endif /* ! TREE_H */
