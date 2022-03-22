#include "error.h"

#include "queue.h"
#include "../token.h"

#include <err.h>

void parse_error(struct queue *q, enum token_kind expected)
{
    struct token *tok = queue_peek(q);
    if(tok->kind == expected)
        return;
    warnx("Parse error: expected %s got %s (%s)",
            token_to_str(expected),
            token_to_str(tok->kind), tok->value);

    while(tok->kind != expected)
    {
        token_free(queue_pop(q));
        tok = queue_peek(q);
    }
}
