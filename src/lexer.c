#include "lexer.h"

#include "utils/vector.h"
#include "token.h"

struct vector *lexer(char *str)
{
    char *s = str;
    struct vector *v = vector_new();
    struct token tok = {NONE, "\0"};
    //int in_quote = 0;

    while(*s!='\0')
    {
        tok.kind = WORD;
        token_append_val(&tok, *s);
        s++;
    }

    vector_append(v, &tok, sizeof(struct token));

    return v;
}
