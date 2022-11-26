#include "parser.h"

#include "utils/queue.h"
#include "utils/tree.h"
#include "utils/stack.h"
#include "utils/error.h"
#include "token.h"
#include "node.h"
#include "command.h"

#include <err.h>
#include <stdlib.h>

struct tree *parser(struct queue *q)
{
    struct token *tok = queue_peek(q);
    struct node *node = node_new(LIST);
    while(!queue_is_empty(q))
    {
        if(first_command(tok))
                node_add_command(node,
                        parse_simple_command(q));
        else if(tok->kind==TS_EOF)
            break;
        else
            errx(1, "unexpected not command");

        tok = queue_peek(q);
    }

    struct tree *res = tree_new(node, sizeof(struct node));
    free(node);
    return res;
}

struct tree *ll_parser(char **string)
{
    struct stack *stack = stack_new();

    struct token *token = token_new(NTS_LIST);
    stack_push(stack, token, sizeof(struct token));

    list_parse(stack, string);

    token = lexer_top(string);

    if(token->kind != TS_NEWLINE && token->kind != TS_EOF)
       send_parse_error(token, TS_NEWLINE);


    struct node *node = node_new(LIST);
    struct tree *tree = tree_new(node, sizeof(struct node));



    stack_free(stack, &node_free);
    return tree;
}
