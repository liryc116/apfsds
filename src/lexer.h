#ifndef LEXER_H
#define LEXER_H

#include "utils/queue.h"

// returns a token queue
struct queue *lexer(char *str);


// returns a token of the beginning of the string
// moves str
struct token *top_lexer(char **str);

#endif
