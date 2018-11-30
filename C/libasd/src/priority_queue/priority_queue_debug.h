#ifndef __PRIORITY_QUEUE_DEBUG_H__
#define __PRIORITY_QUEUE_DEBUG_H__

#include "../standard_libraries.h"
#include "priority_queue.h"

size_t priority_queue_get_capacity(PriorityQueue queue);

void priority_queue_print_priority(PriorityQueue queue, void* value);

#endif