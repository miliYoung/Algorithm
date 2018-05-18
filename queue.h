#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdlib.h>
#include "list.h"

typedef List Queue;

#define queue_init list_init
#define queue_destroy list_destroy
#define queue_size	list_size
#define queue_peek(queue) (queue)->head == NULL? NULL:(queue)->head->data

int queue_dequeue(Queue *queue, const void* data);
int queue_enqueue(Queue *queue, void** data);

#endif