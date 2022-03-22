#include "token.h"

#include <string.h>
#include <stdlib.h>

#include "utils/xmalloc.h"

char *token_to_str(enum token_kind kind)
{
    switch(kind)
    {
    case WORD:
        return "WORD";
    case ASSIGNMENT_WORD:
        return "ASSIGNMENT_WORD";
    case NAME:
        return "NAME";
    case NEWLINE:
        return "NEWLINE";
    case IO_NUMBER:
        return "IO_NUMBER";
    case AND_IF:
        return "AND_IF ('&&')";
    case OR_IF:
        return "OR_IF ('||')";
    case DSEMI:
        return "DSEMI (';;')";
    case DLESS:
        return "DLESS ('<<')";
    case DGREAT:
        return "DGREAT ('>>')";
    case GREATAND:
        return "GREATAND ('>&')";
    case LESSAND:
        return "LESSAND ('<&')";
    case LESSGREAT:
        return "LESSGREAT ('<>')";
    case DLESSDASH:
        return "DLESSDASH ('<<-')";
    case CLOBBER:
        return "CLOBBER ('>|')";
    case T_EOF:
        return "EOF";
    case OTHER: // default
        return "OTHER";
    }

    return "";
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
    free(t->value);
    free(t);
}
