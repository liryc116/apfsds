#include "pipeline.h"

#include "pipeline.h"
#include "token.h"
#include "node.h"

#include <err.h>
#include <string.h>

struct tree *pipeline_parse(struct stack *stack, char **string)
{
    struct token *token = stack_pop(stack);
    if(token->kind != NTS_PIPELINE)
    {
        err(1, "and_or_parse: stack_top!=NTS_PIPELINE\n");
        return NULL;
    }
    token_free(token);

    struct node *node = node_new(PIPELINE);
    struct tree *final = tree_new(node, sizeof(struct node));

    struct tree *child = NULL;

    do
    {
        token = token_new(NTS_COMMAND);
        child = pipeline_parse(stack, string);
        token_free(token);
        token = lexer_top(string);
        tree_add_children(final, child);
    }
    while(child != NULL && (token->kind==TS_AND_IF || token->kind==TS_OR_IF));

}
