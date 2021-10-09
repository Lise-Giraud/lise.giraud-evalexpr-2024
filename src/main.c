#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fifo.h"
#include "my_evalexpr.h"
#include "shunting_yard.h"
#include "stack.h"

int main(int argc, char *argv[])
{
    int res = 0;
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
        res = rpn(lineptr);
        free(lineptr);
        return res;
    }
    else
    {
        char *line = malloc(sizeof(char));
        if (!line)
            exit(4);
        size_t size = 1;
        ssize_t l = getline(&line, &size, stdin);
        if (l == -1)
            return 4;
        res = infix(line, size);
        free(line);
    }
    return res;
}
