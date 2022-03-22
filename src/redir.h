#ifndef REDIR_H
#define REDIR_H

#include "token.h"

int start_op(char c);

enum token_kind lex_redir(char **str_ptr);

int is_redir(struct token *tok);

int first_redir(struct token *tok);

#include "command.h"
#include "utils/queue.h"

void parse_redir(struct queue *q, struct command *c);

#endif /* ! REDIR_H */
