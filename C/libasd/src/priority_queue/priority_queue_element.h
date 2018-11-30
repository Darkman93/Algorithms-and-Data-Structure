#ifndef __PRIORITY_QUEUE_ELEMENT_H__
#define __PRIORITY_QUEUE_ELEMENT_H__

#include "../standard_libraries.h"

/*
 * Types
 */

typedef struct priority_queue_element* PriorityQueueElement;

/*
 * Data structures
 */

struct priority_queue_element
{
  void* value;		// The value of the node.
  void* priority; // The priority of the node.
};

/*
 * Functions
 */

/**
 * @brief      Cretes a new Priority-Queue element.
 *
 * @param[in]  value     The value of the element.
 * @param[in]  priority  The priority of the element.
 *
 * @return     The new element.
 */
PriorityQueueElement new_priority_queue_element(void* value, void* priority);

/**
 * @brief      Destroy a Priority-Queue element.
 *
 * @param[in]  element  The Priority-Queue element.
 */
void destroy_priority_queue_element(PriorityQueueElement* element);

#endif