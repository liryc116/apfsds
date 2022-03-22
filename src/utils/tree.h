#ifndef TREE_H
#define TREE_H

#include <stddef.h>

struct tree
{
    void *key;
    struct tree **children;
    size_t nb_children;
};

struct tree *tree_new(void *key, size_t key_size);

void tree_add_children(struct tree *t, struct tree *child);

void tree_free(struct tree *t, void(*free_fun)(void *));

#endif /* ! TREE_H */
