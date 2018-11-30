#include "priority_queue_debug.h"
#include "priority_queue_defs.h"
#include "priority_queue_element.h"
#include "../graph/vertex.h"

size_t priority_queue_get_capacity(PriorityQueue queue)
{
  return queue->capacity;
}

void priority_queue_print_priority(PriorityQueue queue, void* value)
{
	size_t i = priority_queue_reach(queue, value);
	printf("Priority: %d\n", *(int*) (queue->heap[i]->priority));
}