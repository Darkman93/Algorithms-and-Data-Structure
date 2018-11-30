#include "priority_queue_element.h"

PriorityQueueElement new_priority_queue_element(void* value, void* priority)
{
  PriorityQueueElement element = malloc(sizeof(struct priority_queue_element));
  if (!element) error(EXIT_FAILURE, 0, "Malloc error in function %s", __func__);
  element->value    = value;
  element->priority = priority;
  return element;
}

void destroy_priority_queue_element(PriorityQueueElement* element)
{
  free(*element);
  *element = NULL;
}
