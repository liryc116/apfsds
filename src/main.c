
#include "parser.h"
#include "lexer.h"
#include "eval.h"
#include "token.h"
#include "node.h"
#include "utils/xmalloc.h"
#include "utils/queue.h"
#include "utils/tree.h"

#include <err.h>
#include <stdio.h>
#include <stdlib.h>

void do_command(char *str)
{
    struct queue *q = lexer(str);
    struct tree *t = parser(q);
    eval_tree(t);

    queue_free(q, &token_free);
    tree_free(t, &node_free);
}

int main(int argc, char *argv[])
{
    if(argc>2)
        errx(1, "Usage: %s *optional command*", argv[0]);
    else if(argc==2)
        do_command(argv[1]);
    else
    {
        char *str = xcalloc(256, sizeof(char));
        while(1)
        {
            printf("$> ");
            scanf("%s", str);
            do_command(str);
        }
        free(str);
    }

    return 0;
}
