#include "shunting_yard.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int precedence(char a, struct stack **s) // return 1 if a's precedence is
                                         // greater
{
    if (!*s)
        return -2;
    char b = stack_pop(s);
    if (a == '^')
        return 1;
    if (a == '*' || a == '/' || a == '%')
    {
        if (b == '^')
            return -1;
        if (b == '*' || b == '/' || b == '%')
            return 0;
        return 1;
    }
    if (a == '+' || a == '-')
    {
        if (b == '*' || b == '/' || b == '%' || b == '^')
            return -1;
        if (b == '+' || b == '-')
            return 0;
    }
    return -2;
}

int parse(struct queue *q)
{
    struct stack *s = NULL;
    size_t i = 0;
    while (q->size)
    {
        if (q->is_op[i])
        {
            char op = dequeue(q);
            operand(op);
            stack_push(&s, eval(op, &s));
        }
        else
            stack_push(&s, dequeue(q));
        i++;
    }
    if (!s)
        exit(2);
    printf("%d\n", s->data);
    return 0;
}

int infix(char *exp, size_t n)
{
    struct stack *s = NULL;
    struct queue *q = createQueue(n);
    char *token = strtok(exp, " \t\n\v\f\r");
    size_t i = 0;
    while (token != NULL)
    {
        char op;
        if (check(token)) // valid number
            enqueue(q, atoi(token), 0);
        else // operator
        {
            while (s)
            {
                if (precedence(token[i], &s) == 1)
                    op = stack_pop(&s);
                int p = precedence(token[i], &s);
                if (p == 0 || p == -1)
                {
                    op = stack_pop(&s);
                    enqueue(q, op, 1);
                }
            }
            stack_push(&s, *token);
        }
        i++;
        token = strtok(NULL, " \t\n\v\f\r");
    }
    while (s)
        enqueue(q, stack_pop(&s), 1);
    parse(q);
    free(q);
    free(s);
    return 0;
}
