#include "priority_queue_defs.h"

//extern inline void priority_queue_allocated(PriorityQueue queue);

PriorityQueueElement* new_priority_queue_heap(size_t capacity)
{
  PriorityQueueElement* heap = (PriorityQueueElement*) malloc(sizeof(PriorityQueueElement) * capacity);
  if (!heap) error(EXIT_FAILURE, 0, "Malloc error in function %s", __func__);
  return heap;
}

void destroy_priority_queue_heap(PriorityQueueElement* heap)
{
  // @todo free all elements
  free(*heap);
  *heap = NULL;
}

size_t priority_queue_reach(PriorityQueue queue, void* value)
{
  //printf("searching: %s\n", (char*) value);
  CompareFunction compare = queue->compareValue;
  for (size_t i = 0; i < queue->size; ++i)
    if (!compare(queue->heap[i]->value, value))
      return i;

  //error(EXIT_FAILURE, 0, "Error in function %s: value not found", __func__);
  return PRIORITY_QUEUE_NULL_INDEX;
}

void* priority_queue_remove_element(PriorityQueue queue, PriorityQueueElement* elementPtr, size_t index)
{
  void* value = (*elementPtr)->value;
  destroy_priority_queue_element(elementPtr);
  *elementPtr = queue->heap[ --queue->size ];
  priority_queue_move_down(queue, index);
  priority_queue_check_and_resize(queue);
  return value;
}

void priority_queue_move_up(PriorityQueue queue, size_t index)
{
  //printf("%lf\n", *(double*) queue->heap[index]->priority);
  if (index < queue->size)
  {
    CompareFunction compare = queue->comparePriority;
    size_t iFather = (index - 1) >> 1;
    PriorityQueueElement* heap  = queue->heap;
    PriorityQueueElement  pivot = heap[index];
    while (index != 0 && compare(pivot->priority, heap[iFather]->priority) < 0)
    {
      heap[index] = heap[iFather];
      index = iFather;
      iFather = (index - 1) >> 1;
    }
    heap[index] = pivot;
  }
}

void priority_queue_move_down(PriorityQueue queue, size_t index)
{
  if (index < queue->size)
  {
    CompareFunction compare = queue->comparePriority;
    size_t iChild = (index << 1) + 1;
    size_t size = queue->size;
    PriorityQueueElement* heap  = queue->heap;
    PriorityQueueElement  pivot = heap[index];
    while((iChild) < size)
    {
      if (iChild + 1 < size && compare(heap[iChild]->priority, heap[iChild + 1]->priority) > 0) ++iChild;
      if (compare(pivot->priority, heap[iChild]->priority) <= 0) break;
      heap[index] = heap[iChild];
      index = iChild;
      iChild = (index << 1) + 1;
    }
    heap[index] = pivot;
  }
}

bool priority_queue_check_and_resize(PriorityQueue queue)
{
  size_t newCapacity = 0;

  if (queue->size >= queue->capacity)
  {
    if (queue->size > PRIORITY_QUEUE_MAX_CAPACITY) return false;

    newCapacity = queue->capacity << 1;
    if(newCapacity < queue->capacity) newCapacity = PRIORITY_QUEUE_MAX_CAPACITY;
    //if (size_t_overflowed(queue->capacity, newCapacity)) newCapacity = PRIORITY_QUEUE_MAX_CAPACITY;

  }
  else if (queue->capacity > PRIORITY_QUEUE_MIN_CAPACITY && queue->size <= (queue->capacity >> 2))
  {
    newCapacity = queue->capacity >> 1;
    if (newCapacity < PRIORITY_QUEUE_MIN_CAPACITY)
      newCapacity = PRIORITY_QUEUE_MIN_CAPACITY;
  }

  if (newCapacity > 0)
    priority_queue_resize(queue, newCapacity);

  return true;
}

void priority_queue_resize(PriorityQueue queue, size_t newCapacity)
{
  if (queue->capacity > PRIORITY_QUEUE_MAX_CAPACITY)
  {
    printf("priority_queue_resize: heap oversized\n");
    exit(EXIT_FAILURE);
  }

  size_t capacityBytes = newCapacity * sizeof(PriorityQueueElement);
  queue->capacity = newCapacity;
  queue->heap     = realloc(queue->heap, capacityBytes);
  if (!queue->heap) {
    printf("priority_queue_resize: impossible reallocate heap\n");
    exit(EXIT_FAILURE);
  }
}
