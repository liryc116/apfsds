#ifndef AND_OR_H
#define AND_OR_H

#include "utils/tree.h"
#include "utils/stack.h"

struct tree *and_or_parse(struct stack *stack, char **string);

#endif /* ! AND_OR_H */
