#include "priority_queue_factory.h"

PriorityQueue create_priority_queue(CompareFunction compareValue, CompareFunction comparePriority)
{
  return new_priority_queue(PRIORITY_QUEUE_MIN_CAPACITY, compareValue, comparePriority);
}

PriorityQueue create_priority_queue_customized(size_t initialCapacity, CompareFunction compareValue, CompareFunction comparePriority)
{
  if (initialCapacity < PRIORITY_QUEUE_MIN_CAPACITY && initialCapacity > PRIORITY_QUEUE_MAX_CAPACITY)
  	error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  return new_priority_queue(initialCapacity, compareValue, comparePriority);
}
