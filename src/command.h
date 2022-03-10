#ifndef COMMAND_H
#define COMMAND_H

#include <stddef.h>

struct command
{
    //enum redirirection *redirections;
    char **argv;
    size_t argc;
};

struct command *command_new(char *name);

void command_add_arg(struct command *c, char *arg);

void command_add_redirection(struct command *c, char *redir);

#endif /* ! COMMAND_H */
