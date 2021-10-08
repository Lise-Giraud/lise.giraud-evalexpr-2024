#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "my_evalexpr.h"
#include "stack.h"

int eval(char op, struct stack **s)
{
    int tmp;
    switch (op)
    {
        case '+':
            return stack_pop(s) + stack_pop(s);
            break;
        case '*':
            return stack_pop(s) * stack_pop(s);
            break;
        case '-':
            tmp = stack_pop(s);
            return stack_pop(s) - tmp;
            break;
        case '/':
            tmp = stack_pop(s);
            if (!tmp)
                exit(3);
            return stack_pop(s) / tmp;
            break;
        case '%':
            tmp = stack_pop(s);
            if (!tmp)
                exit(3);
            return stack_pop(s) % tmp;
            break;
    }
    return 0;
}

size_t operand(char op)
{
    switch (op)
    {
        case '+':
        case '*':
        case '-':
        case '/':
        case '^':
        case '%':
        case '(':
        case ')':
            return 1;
        default :
            exit(2);
    }
}

int check(char number)
{
    for (; number; number++)
    {
        if (number < '0' || number > '9')
            return 0;
    }
    return 1;
}

int rpn(char *exp)
{
    struct stack *s = NULL;
    int tmp = 0;
    for (size_t i = 0; i < strlen(exp); i++)
    {
        size_t op;
        if (check(exp[i])) //valid number
        {
            tmp = atoi(exp);
            stack_push(&s, tmp);
        }
        else //operand
        {
            op = operand(exp[0]);
            if (strlen(exp) != 1 || op)
                exit(2);
            stack_push(&s, eval(op, &s));
        }
    }
    if (!s)
        exit(2);
    printf("%d\n", s->data);
    return 0;
}


int main(int argc, char *argv[])
{
    if (argc < 1)
        exit(0);
    if (argc > 1 && strcmp(argv[1], "-rpn") != 0)
        exit(4);
    if (argc == 2 && !strcmp(argv[1], "-rpn"))
    {
        char *lineptr;
        size_t n;
        ssize_t line = getline(&lineptr, &n, stdin);
        if (line == -1)
            return 4;
        return rpn(lineptr);
    }
    return 0;
}
