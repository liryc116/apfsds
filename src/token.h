#ifndef TOKEN_H
#define TOKEN_H

enum token_kind
{
    NTS_INPUT,
    NTS_LIST,
    NTS_AND_OR,
    NTS_PIPELINE,
    NTS_COMMAND,
    NTS_SIMPLE_COMMAND,
    NTS_REDIRECTIONS,
    NTS_PREFIX,
    NTS_ELEMENT,

    // Lexer/litteral tokens
    TS_WORD,
    TS_ASSIGNMENT_WORD,
    TS_NAME,
    TS_NEWLINE, // '\n'
    TS_IO_NUMBER,
    TS_AND_IF, // &&
    TS_OR_IF, // ||
    TS_DSEMI, // ;;
    TS_DLESS, // <<
    TS_DGREAT, // >>
    TS_GREATAND, // >&
    TS_LESSAND, // <&
    TS_LESSGREAT, // <>
    TS_DLESSDASH, // <<-
    TS_CLOBBER, // >|
    TS_EOF, // $ '\0'
    TS_OTHER, // '>' '<' may include '(' ')' '[' ']' '|' '&'
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
