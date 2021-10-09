#include "fifo.h"

#include <stdio.h>
#include <stdlib.h>

struct queue *createQueue(size_t capacity)
{
    struct queue *q = malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->head = 0;
    q->size = 0;

    q->tail = capacity - 1;
    q->data = malloc(q->capacity * sizeof(int));
    q->is_op = malloc(q->capacity * sizeof(int));
    return q;
}

void enqueue(struct queue *q, int item, int op)
{
    if (q->size == q->capacity)
        return;
    q->tail = (q->tail + 1) % q->capacity;
    q->data[q->tail] = item;
    q->is_op[q->tail] = op;
    q->size = q->size + 1;
}

int dequeue(struct queue *q)
{
    if (!q->size)
        exit(2);
    int item = q->data[q->head];
    q->head = (q->head + 1) % q->capacity;
    q->size = q->size - 1;

    return item;
}
