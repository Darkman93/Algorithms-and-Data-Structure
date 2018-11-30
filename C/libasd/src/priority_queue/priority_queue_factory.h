#ifndef __PRIORITY_QUEUE_FACTORY_H__
#define __PRIORITY_QUEUE_FACTORY_H__

#include "../standard_libraries.h"
#include "../function_types.h"
#include "../unsigned_types.h"
#include "priority_queue.h"

/**
 * @brief      Creates a Priority Queue with default initial capacity.
 *
 * @param[in]  compareValue     The function used to compare values.
 * @param[in]  comparePriority  The function used to compare priorityes.
 *
 * @return     The new Priority Queue.
 */
PriorityQueue create_priority_queue(CompareFunction compareValue, CompareFunction comparePriority);

/**
 * @brief      Creates a Priority Queue.
 *
 * @param[in]  initialCapacity  The initial capacity.
 * @param[in]  compareValue     The function used to compare values.
 * @param[in]  comparePriority  The function used to compare priorityes.
 *
 * @return     The new Priority Queue.
 */
PriorityQueue create_priority_queue_customized(size_t initialCapacity, CompareFunction compareValue, CompareFunction comparePriority);

// @todo altre factory

#endif