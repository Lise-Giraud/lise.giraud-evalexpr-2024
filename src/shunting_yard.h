#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include "fifo.h"
#include "my_evalexpr.h"
#include "stack.h"

int infix(char *exp, size_t n);
int parse(struct queue *q);
int precedence(char a, struct stack **s);

#endif /*!SHUNTING_YARD_H*/
