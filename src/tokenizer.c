#include "tokenizer.h"

#include "utils/vector.h"
#include "token.h"

void tokenizer(struct vector *v)
{
    for(size_t i = 0; i<v->size; i++)
    {
        struct token *tok = v->data[i];
        if(tok->kind == NONE)
            tok->kind = WORD;
    }
}
