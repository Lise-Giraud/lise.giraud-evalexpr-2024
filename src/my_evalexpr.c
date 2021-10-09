#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "my_evalexpr.h"
#include "stack.h"

int my_pow(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    int pow = a;
    for (int i = 1; i < b / 2; i++)
    {
        pow *= a;
    }
    if (b % 2 == 0)
        return pow * pow;
    else
        return pow * pow * a;
}

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
        case '^':
            return my_pow(stack_pop(s), stack_pop(s));
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
           exit(1);
    }
}

int check(char *number)
{
    for (; *number; number++)
    {
        if (*number < '0' || *number > '9')
            return 0;
    }
    return 1;
}

int rpn(char *exp)
{
    struct stack *s = NULL;
    int tmp = 0;
    char *token = strtok(exp, " ");
    while (token != NULL)
    {
        size_t op;
        if (check(token)) //valid number
        {
            tmp = atoi(token);
            stack_push(&s, tmp);
        }
        else //operand
        {
            size_t l = strlen(token) - 1;
            if (l > 1)
                exit(2);
            op = token[0];

            operand(op);
            stack_push(&s, eval(op, &s));
        }
        token = strtok(NULL, " ");
    }
    if (!s)
        exit(2);
    printf("%d\n", s->data);
    free(s);
    return 0;
}
