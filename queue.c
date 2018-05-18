#include "queue.h"


int queue_dequeue(Queue *queue, const void* data);
{
	return list_rem_next(queue, NULL,data);
}

int queue_enqueue(Queue *queue, void** data)
{
	return list_ins_next(queue,list_queue(queue), data);
}