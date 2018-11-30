#ifndef __PRIORITY_QUEUE_DEFS_H__
#define __PRIORITY_QUEUE_DEFS_H__

#include "../standard_libraries.h"
#include "../unsigned_types.h"
#include "../function_types.h"
#include "priority_queue_element.h"
#include "priority_queue.h"

#define PRIORITY_QUEUE_NULL_INDEX SIZE_T_NULL

// @todo Dare una controllata ai commenti se sono giusti.

/*
 * Data Structures
 */

struct priority_queue
{
  CompareFunction compareValue;		 // The function to compare values.
  CompareFunction comparePriority; // The function to compare priorityes.
  size_t capacity;								 // The capacity.
  size_t size;										 // The number of elements.
  PriorityQueueElement* heap;			 // The heap.
};

/*
inline void priority_queue_allocated(PriorityQueue queue)
{
  if (!queue) {
    printf("The priority queue not allocated\n");
    exit(EXIT_FAILURE);
  }
}
*/

/*
 * Functions
 */

/**
 * @brief      Creates a new Priority Queue implemented as an heap.
 *
 * @param[in]  capacity  The initial capacity of the Priority Queue.
 *
 * @return     The new Priority Queue.
 */
PriorityQueueElement* new_priority_queue_heap(size_t capacity);

/**
 * @brief      Destroy a Priority Queue.
 *
 * @param      heap  The Priority Queue.
 */
void destroy_priority_queue_heap(PriorityQueueElement* heap);

/**
 * @brief      Search a value in a Priority Queue.
 *
 * @param[in]  queue  The Priority Queue.
 * @param      value  The value.
 *
 * @return     The index of the element.
 */
size_t priority_queue_reach(PriorityQueue queue, void* value);

/**
 * @brief      Removes an element from a Priority Queue.
 *
 * @param[in]  queue       The Priority Queue.
 * @param[in]  elementPtr  The pointer to the element.
 * @param[in]  index       The index of the element.
 *
 * @return     The value of the element.
 */
void* priority_queue_remove_element(PriorityQueue queue, PriorityQueueElement* elementPtr, size_t index);

/**
 * @brief      Sifts up an element in a Priority Queue.
 *
 * @param[in]  queue  The Priority Queue.
 * @param[in]  index  The index of the element.
 */
void priority_queue_move_up(PriorityQueue queue, size_t index);

/**
 * @brief      Sifts down an element in a Priority Queue.
 *
 * @param[in]  queue  The Priority Queue.
 * @param[in]  index  The index of the element.
 */
void priority_queue_move_down(PriorityQueue queue, size_t index);

/**
 * @brief      Check how a Priority Queue has to be resized an resizes it.
 *
 * @param[in]  queue  The Priority Queue.
 *
 * @return     @c true if the Priority Queue has been successfully resized. @
 *             false otherwise.
 */
bool priority_queue_check_and_resize(PriorityQueue queue);

/**
 * @brief      Resize a Priority Queue.
 *
 * @param[in]  queue        The Priority Queue.
 * @param[in]  newCapacity  The new capacity.
 */
void priority_queue_resize(PriorityQueue queue, size_t newCapacity);

#endif