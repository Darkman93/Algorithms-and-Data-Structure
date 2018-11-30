#ifndef __FUNCTION_TYPES_H__
#define __FUNCTION_TYPES_H__

#include "standard_libraries.h"

/**
 * @brief  A function wich compare two elements.
 *
 * @return - an integer greater than 0 if the element pointed by ptr1 is greater than the element pointed by ptr2.
 *         - an integer lesser than 0 if the element pointed by ptr1 is lesser than the element pointed by ptr2.
 *         - 0 otherwise.
 **/
typedef int (*CompareFunction)(void* ptr1, void* ptr2);

/**
 * @brief     A function wich sort a generic array
 *
 * @param[in] array       array to sort
 * @param[in] arraySize   number of elements contained
 * @param[in] elementSize size of an element
 * @param[in] compare     compare function
 */
typedef void (*SortFunction)(void* array, size_t arraySize, size_t elementSize, CompareFunction compare);

/**
 * @brief     Returns the digest of the specified value.
 *
 * @param[in] key   The pointer to the @c input value.
 *
 * @return    The digest of the @c input.
 */
typedef size_t (*HashFunction) (void* key);

#endif
