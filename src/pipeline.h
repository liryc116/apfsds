#ifndef PIPELINE_H
#define PIPELINE_H

#include "utils/stack.h"
#include "utils/tree.h"

struct tree *pipeline_parse(struct stack *stack, char **string);

#endif /* ! PIPELINE_H */
