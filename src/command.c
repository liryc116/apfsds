#include "command.h"

#include "utils/xmalloc.h"

#include <string.h>

struct command *command_new(char *name)
{
    struct command *c = xmalloc(sizeof(struct command));

    c->argc = 1;
    c->argv = xmalloc(sizeof(char *));

    size_t len = strlen(name)+1;
    c->argv[0] = xmalloc(len*sizeof(char));
    strncpy(c->argv[0], name, len);

    return c;
}

void command_add_arg(struct command *c, char *arg)
{
    size_t len = strlen(arg)+1;
    c->argv[c->argc] = xmalloc(len*sizeof(char));
    strncpy(c->argv[c->argc], arg, len);
    c->argc++;
}
