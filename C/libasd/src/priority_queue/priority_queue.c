#include "priority_queue.h"
#include "priority_queue_element.h"
#include "priority_queue_defs.h"


PriorityQueue new_priority_queue(size_t initialCapacity, CompareFunction compareValue, CompareFunction comparePriority)
{
  if (!initialCapacity || !comparePriority || !compareValue) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  PriorityQueue queue = (PriorityQueue) malloc(sizeof(struct priority_queue));
  if (!queue) error(EXIT_FAILURE, 0, "Malloc error in function %s", __func__);
  queue->compareValue    = compareValue;
  queue->comparePriority = comparePriority;
  queue->capacity        = initialCapacity;
  queue->size            = 0;
  queue->heap            = new_priority_queue_heap(initialCapacity);
  return queue;
}

void destroy_priority_queue(PriorityQueue* queue)
{
  if (!*queue) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  destroy_priority_queue_heap((*queue)->heap);
  free(*queue);
  *queue = NULL;
}

bool priority_queue_change_priority(PriorityQueue queue, void* value, void* newPriority)
{
  if (!queue || !newPriority) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  size_t index = priority_queue_reach(queue, value);
  //printf("out\n");
  //printf("%zu\n", index);
  if (index != PRIORITY_QUEUE_NULL_INDEX)
  {
    //printf("%lf\n", *(double*) newPriority);
    //printf("in\n");
    //printf("%lf\n", *(double*) newPriority);
    queue->heap[index]->priority = newPriority;

    //printf("%lf\n", *(double*) queue->heap[index]->priority);

    priority_queue_move_up(queue, index);
    priority_queue_move_down(queue, index);

    //printf("%lf\n", *(double*) queue->heap[index]->priority);

    return true;
  }
  return false;
}

bool priority_queue_contains(PriorityQueue queue, void* value)
{
  if (!queue) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  size_t index = priority_queue_reach(queue, value);
  return index != PRIORITY_QUEUE_NULL_INDEX;
}

bool priority_queue_is_empty(PriorityQueue queue)
{
  if (!queue) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  return !queue->size;
}

bool priority_queue_offer(PriorityQueue queue, void* value, void* priority)
{
  if (!queue || !priority) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  if (priority_queue_check_and_resize(queue))
  {
    queue->heap[ queue->size++ ] = new_priority_queue_element(value, priority);
    priority_queue_move_up(queue, queue->size - 1);
    return true;
  }
  return false;
}

void* priority_queue_peek(PriorityQueue queue)
{
  if (!queue) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  return queue->size ? queue->heap[0]->value : NULL;
}

void* priority_queue_poll(PriorityQueue queue)
{
  if (!queue) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  return queue->size > 0 ? priority_queue_remove_element(queue, &queue->heap[0], 0) : NULL;
}

void* priority_queue_remove(PriorityQueue queue, void* value)
{
  if (!queue || !value) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  size_t index = priority_queue_reach(queue, value);
  return index != PRIORITY_QUEUE_NULL_INDEX ? priority_queue_remove_element(queue, &queue->heap[index], index) : NULL;
}

size_t priority_queue_size(PriorityQueue queue)
{
  if (!queue) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  return queue->size;
}