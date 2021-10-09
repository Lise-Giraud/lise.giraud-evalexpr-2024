#ifndef FIFO_H
#define FIFO_H

#include <stddef.h>
#include <stdlib.h>

struct queue {
    int head;
    int tail;
    size_t size;
    size_t capacity;
    int * data;
    int * is_op;
};

struct queue* createQueue(size_t capacity);
void enqueue(struct queue* q, int item, int op);
int dequeue(struct queue* q);

#endif /*!FIFO_H*/
