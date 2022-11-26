#include "token.h"

#include <string.h>
#include <stdlib.h>

#include "utils/xmalloc.h"

char *token_to_str(enum token_kind kind)
{
    switch(kind)
    {
    case TS_WORD:
        return "WORD";
    case TS_ASSIGNMENT_WORD:
        return "ASSIGNMENT_WORD";
    case TS_NAME:
        return "NAME";
    case TS_NEWLINE:
        return "NEWLINE";
    case TS_IO_NUMBER:
        return "IO_NUMBER";
    case TS_AND_IF:
        return "AND_IF ('&&')";
    case TS_OR_IF:
        return "OR_IF ('||')";
    case TS_DSEMI:
        return "DSEMI (';;')";
    case TS_DLESS:
        return "DLESS ('<<')";
    case TS_DGREAT:
        return "DGREAT ('>>')";
    case TS_GREATAND:
        return "GREATAND ('>&')";
    case TS_LESSAND:
        return "LESSAND ('<&')";
    case TS_LESSGREAT:
        return "LESSGREAT ('<>')";
    case TS_DLESSDASH:
        return "DLESSDASH ('<<-')";
    case TS_CLOBBER:
        return "CLOBBER ('>|')";
    case TS_EOF:
        return "EOF";
    case TS_OTHER: // default
        return "OTHER";
    }

    return "";
}

struct token *token_new(enum token_kind kind)
{
    struct token *token = xcalloc(1, sizeof(struct token));
    token->kind = kind;

    return token;
}

void token_append_val(struct token *tok, char c)
{
    if(tok->value==NULL)
    {
        tok->value = xcalloc(2, sizeof(char));
        tok->value[0] = c;
        return ;
    }

    size_t len = strlen(tok->value);
    tok->value = xreallocarray(tok->value, len+2, sizeof(char));
    tok->value[len] = c;
    tok->value[len+1] = '\0';
}

void token_free(void *token)
{
    struct token *t = token;
    if(t->value!=NULL)
        free(t->value);
    free(t);
}
