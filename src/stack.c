#include "stack.h"

#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

void stack_push(struct stack **s, int e)
{
    struct stack *first = malloc(sizeof(struct stack));
    if (!first)
        return;
    first->data = e;
    first->next = *s;
    *s = first;
}

int stack_pop(struct stack **s)
{
    if (!s)
        exit(4);
    struct stack *new = *s;
    int value = new->data;
    *s = new->next;
    free(new);
    return value;
}
