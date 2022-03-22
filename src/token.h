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
    T_EOF,
    OTHER, // '>' '<' may include '(' ')' '[' ']'
};

struct token
{
    enum token_kind kind;
    char *value;
};

char *token_to_str(enum token_kind kind);

struct token *token_new(enum token_kind kind);

void token_append_val(struct token *tok, char c);

void token_free(void *token);

#endif
