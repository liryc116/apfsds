#include <iostream>
#include <gtest/gtest.h>

extern "C" {
    #include "../src/command.h"
    #include "../src/token.h"
}

TEST(first_command, word)
{
    struct token tok = {.kind=WORD, .value=""};
    ASSERT_NE(0, first_command(&tok));
}
