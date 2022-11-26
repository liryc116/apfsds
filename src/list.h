#ifndef LIST_H
#define LIST_H

#include "utils/stack.h"
#include "utils/tree.h"
#include "token.h"

struct tree *parse_list(struct stack *stack, char **string);

#endif /* ! LIST_H */
