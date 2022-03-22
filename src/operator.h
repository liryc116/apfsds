#ifndef OPERATOR_H
#define OPERATOR_H

#include "token.h"

int start_op(char c);

void lex_op(char **str_ptr, struct token *tok);

#endif /* ! OPERATOR_H */
