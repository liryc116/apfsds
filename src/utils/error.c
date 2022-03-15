#include "error.h"

#include "queue.h"
#include "../token.h"

#include <err.h>

void parse_error(struct queue *q, enum token_kind expected)
{
    struct token *tok = queue_peek(q);
    if(tok->kind == expected)
        return;
    errx(1, "Parse error: expected x_token got y_token");

    while(tok->kind != expected)
    {
        token_free(queue_pop(q));
        tok = queue_peek(q);
    }
}
