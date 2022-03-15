#ifndef TOKEN_H
#define TOKEN_H

enum token_kind
{
    WORD,
    ASSIGNMENT_WORD,
    NAME,
    NEWLINE,
    IO_NUMBER,
    AND_IF,
    OR_IF,
    DSEMI,
    DLESS,
    DGREAT,
    GREATAND,
    LESSAND,
    LESSGREAT,
    DLESSDASH,
    CLOBBER,
    EOF,
    OTHER, // may include '(' ')' '[' ']'
};

struct token
{
    enum token_kind kind;
    char *value;
};

struct token *token_new(enum token_kind kind);


void token_append_val(struct token *tok, char c);

struct token *token_free(struct token *tok);

#endif
