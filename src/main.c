#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_evalexpr.h"
#include "stack.h"

int main(int argc, char *argv[])
{
    if (argc < 1)
        exit(0);
    if (argc > 1 && strcmp(argv[1], "-rpn") != 0)
        exit(4);
    if (argc == 2 && !strcmp(argv[1], "-rpn"))
    {
        char *lineptr = malloc(sizeof(char));
        if (!lineptr)
            exit(4);
        size_t n = 1;
        ssize_t line = getline(&lineptr, &n, stdin);
        if (line == -1)
            return 4;
        int res = rpn(lineptr);
        free(lineptr);
        return res;
    }
    return 0;
}
