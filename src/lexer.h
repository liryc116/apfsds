#ifndef LEXER_H
#define LEXER_H

#include "utils/queue.h"

// returns a token queue
struct queue *lexer(char *str);

#endif
