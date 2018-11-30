#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

#include "../standard_libraries.h"
#include "../function_types.h"

/**
 * @brief         Implements in-place quick sort on a generic type array.
 *
 * @param[in,out] basePtr      The pointer to the array.
 * @param[in]     arraySize    The size of the array.
 * @param[in]     elementSize  The size of the records.
 * @param[in]     compare      The compare function.
 */
void quick_sort(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare);

/**
 * @brief      It implements version of quicksort of Cormen
 *
 * @param      basePtr      The base pointer
 * @param[in]  arraySize    The array size
 * @param[in]  elementSize  The element size
 * @param[in]  compare      The compare
 */
void quick_sort_cormen(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare);

#endif