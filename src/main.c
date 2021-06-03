#include <stdio.h>
#include <stdlib.h>
#include "parsing/tokens.h"

char* code[] = {
    "$var variable1;",
    "$var variable2 = \"asdf\";"
};

int main() {
    Parse(code);
}