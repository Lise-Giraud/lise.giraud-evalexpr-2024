#ifndef MY_EVALEXPR_H
#define MY_EVALEXPR_H

#include "stack.h"

int my_pow(int a, int b);

int eval(char op, struct stack **s);

size_t operand(char op);

int check(char *number);

int rpn(char *exp);

#endif /*!MY_EVALEXPR_H*/
