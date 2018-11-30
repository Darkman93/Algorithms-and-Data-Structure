#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "../standard_libraries.h"
#include "../function_types.h"

#define PRIORITY_QUEUE_MIN_CAPACITY 8
#define PRIORITY_QUEUE_MAX_CAPACITY (SIZE_T_MAX_VALUE - 1)

// @todo Dare una controllata ai commenti se sono giusti.

/*
 * Types
 */

typedef struct priority_queue* PriorityQueue;

/*
 * Functions
 */

/**
 * @brief      Creates a new Priority Queue
 *
 * @param[in]  initialCapacity  The initial capacity.
 * @param[in]  compareValue     The function to compare values.
 * @param[in]  comparePriority  The function to compare priority.
 *
 * @return     The new Priority Queue.
 */
PriorityQueue new_priority_queue(size_t initialCapacity, CompareFunction compareValue, CompareFunction comparePriority);

/**
 * @brief      Destroy a Priority Queue.
 *
 * @param[in]  queue  The Priority Queue.
 */
void destroy_priority_queue(PriorityQueue* queue);


/**
 * @brief      Changes the priority of an element in a Priority Queue.
 *
 * @param[in]  queue        The Priority Queue.
 * @param[in]  value        The value of the element.
 * @param[in]  newPriority  The new priority of the element.
 *
 * @return     @c true if the operation succed. @c false otherwise.
 */
bool priority_queue_change_priority(PriorityQueue queue, void* value, void* newPriority);

/**
 * @brief      Check if a value is contained in a Priority Queue.
 *
 * @param[in]  queue  The Priority Queue.
 * @param[in]  value  The value.
 *
 * @return     @c true if the value is in the Priority Queue. @c false
 *             otherwise.
 */
bool priority_queue_contains(PriorityQueue queue, void* value);

/**
 * @brief      Check if a Prioriti Queue is empty.
 *
 * @param[in]  queue  The Prioirty Queue.
 *
 * @return     @c 0 if the Stack is not empty. Another @c int otherwise.
 */
bool priority_queue_is_empty(PriorityQueue queue);

/**
 * @brief      Puts some data into a Priority Queue.
 *
 * @param[in]  queue     The Priority Queue.
 * @param[in]  value     The data.
 * @param[in]  priority  The priority of the data.
 *
 * @return     @c true if the operation succed. @c false otherwise.
 */
bool priority_queue_offer(PriorityQueue queue, void* value, void* priority);

/**
 * @brief      Gets the value of the first element of a Priority Queue without
 *             removing it.
 *
 * @param[in]  queue  The Priority Queue.
 *
 * @return     @c NULL if the Priority Queue is empty. The value of the first
 *             element otherwise.
 */
void* priority_queue_peek(PriorityQueue queue);

/**
 * @brief      Gets the value of the first element of a Priority Queue removing
 *             it.
 *
 * @param[in]  queue  The Priority Queue.
 *
 * @return     @c NULL if the Priority Queue is empty. The value of the first
 *             element otherwise.
 */
void* priority_queue_poll(PriorityQueue queue);

/**
 * @brief      Removes an element from a Priority Queue.
 *
 * @param[in]  queue  The Priority Queue.
 * @param[in]  value  The value of the element.
 *
 * @return     @c NULL if the value is not in the Priority Queue. The value of
 *             the first element otherwise.
 */
void* priority_queue_remove(PriorityQueue queue, void* value);

/**
 * @brief      Check the size of a Priority Queue.
 *
 * @param[in]  queue  The Priority Queue.
 *
 * @return     The size.
 */
size_t priority_queue_size(PriorityQueue queue);

#endif