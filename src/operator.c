#include "operator.h"

#include "token.h"

int start_op(char c)
{
    return c=='<' || c=='>' || c=='|' || c=='&' || c==';';
}

void lex_op(char **str_ptr, struct token *tok)
{
    char *str = *str_ptr;
    enum token_kind k = OTHER;
    if(!start_op(str[0]))
        return;

    switch(str[0])
    {
    case ';':
        if(str[1]==';')
            k = DSEMI;
        break;
    case '&':
        if(str[1]=='&')
            k = AND_IF;
        break;
    case '|':
        if(str[1]=='|')
            k = OR_IF;
        break;
    case '<':
        if(str[1]=='<')
        {
            k = DLESS;
            if(str[2]=='-')
                k = DLESSDASH;
        }
        else if(str[1]=='&')
            k = LESSAND;
        else if(str[1]=='>')
            k = LESSGREAT;
        break;
    case '>':
        if(str[1]=='>')
            k = DGREAT;
        else if(str[1]=='&')
            k = GREATAND;
        else if(str[1]=='|')
            k = CLOBBER;
        break;
    }

    tok->kind = k;
    if(k==OTHER)
    {
        token_append_val(tok, *str);
        str-=1;
    }
    else if(k==DLESSDASH)
        str+=1;
    str+=2;

    *str_ptr = str;
}
