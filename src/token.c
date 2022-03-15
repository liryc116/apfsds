#include "token.h"

#include <string.h>

#include "utils/xmalloc.h"


void token_append_val(struct token *tok, char c)
{
    tok->value = xreallocarray(tok->value, strlen(tok->value)+1, sizeof(char));
}
