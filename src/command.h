#ifndef COMMAND_H
#define COMMAND_H

#include <stddef.h>

#include "token.h"
#include "utils/queue.h"

struct command
{
    enum token_kind *redir;
    size_t n_redir;
    char **argv;
    size_t argc;
};

struct command *command_new(void);

void command_add_arg(struct command *c, struct token *tok);

void command_add_redir(struct command *c, struct token *tok);

struct command *parse_simple_command(struct queue *q);

#endif /* ! COMMAND_H */
