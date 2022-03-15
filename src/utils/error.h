#ifndef ERROR_H
#define ERROR_H

#include "queue.h"
#include "../token.h"

void parse_error(struct queue *q, enum token_kind expected);

#endif /* ! ERROR_H */
