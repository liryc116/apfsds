#include "list.h"

#include "token.h"
#include "node.h"
#include "and_or.h"

#include <err.h>
#include <string.h>

struct tree *list_parse(struct stack *stack, char **string)
{
    struct token *token = stack_pop(stack);
    if(token->kind != NTS_LIST)
    {
        err(1, "list_parse: stack_top!=NTS_LIST\n");
        return NULL;
    }
    token_free(token);

    struct node *node = node_new(LIST);
    struct tree *final = tree_new(node, sizeof(struct node));

    struct tree *child = NULL;

    do
    {
        token = token_new(NTS_AND_OR);
        stack_push(stack, token, sizeof(struct token));
        token_free(token);
        child = and_or_parse(stack, string);
        token = lexer_top(string);
        tree_add_children(final, child);
    }
    while(child != NULL && token->kind == TS_OTHER &&
            (strcmp(token->value, "|") || strcmp(token->value, ";")));


    return final;
}
