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

/*void push( struct stack **head, int value )
{
	struct stack* node = malloc( sizeof(struct stack) );

	if( node == NULL ) {
		exit(4);
	} else {
		node->data = value;
		node->next = *head;
		*head = node;
        head->size++;
	}
}*/


/*int pop( stack **head )
{
	if( *head == NULL ) {
		exit(4);
	} else {
		stack* top = *head;
		int value = top->data;
		*head = top->next;
		free( top );
        head->size--;
		return value;
	}
}*/

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
