#ifndef STACK_H
#define STACK_H

#include <stddef.h>

struct stack
{
    int data;
    struct stack *next;
};

void stack_push(struct stack **s, int e);
int stack_pop(struct stack **s);

#endif /* !STACK_H */
