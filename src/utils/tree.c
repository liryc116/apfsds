#include "tree.h"

#include "xmalloc.h"

#include <stdlib.h>
#include <string.h>

struct tree *tree_new(void *key, size_t key_size)
{
    struct tree *t = xcalloc(1, sizeof(struct tree));
    t->key = xmalloc(key_size);
    memcpy(t->key, key, key_size);
    return t;
}

void tree_add_children(struct tree *t, struct tree *child)
{
    t->children = xreallocarray(t->children,
            t->nb_children, sizeof(struct tree *));
    t->children[t->nb_children] = child;
    t->nb_children+=1;
}

void tree_free(struct tree *t, void(*free_fun)(void *))
{
    for(size_t i = 0; i<t->nb_children; i++)
        tree_free(t->children[i], free_fun);
    free_fun(t->key);
    free(t);
}
