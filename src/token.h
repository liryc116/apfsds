#ifndef TOKEN_H
#define TOKEN_H

enum token_kind
{
    NONE,
    WORD,
    ASSIGNMENT_WORD,
    IONUMBER,
    HEREDOC,
    NAME,
    KEYWORD,
    OPERATOR,
    OTHER
};

struct token
{
    enum token_kind kind;
    char *value;
};

void token_append_val(struct token *tok, char c);

#endif
