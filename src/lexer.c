#include "lexer.h"

#include "utils/queue.h"
#include "utils/xmalloc.h"
#include "token.h"
#include "operator.h"

#include <stdlib.h>

void add_token(struct queue *q, struct token *tok)
{
    tok->value = NULL;
    queue_push(q, tok, sizeof(struct token));
    tok->kind = WORD;
}

struct queue *lexer(char *str)
{
    char *s = str;
    struct queue *q = queue_new();
    struct token tok = {WORD, NULL};
    //int in_quote = 0;

    while(*s!='\0')
    {
        if(start_op(*s))
        {
            queue_push(q, &tok, sizeof(struct token));
            lex_op(&s, &tok);
            add_token(q, &tok);
        }
        else
        {
            if(*s=='=' && tok.value!=NULL && tok.value[0]!='\0')
                tok.kind = ASSIGNMENT_WORD;
            token_append_val(&tok, *s);
            s++;
        }
    }

    queue_push(q, &tok, sizeof(struct token));

    return q;
}
