#ifndef __SELECTION_SORT_H__
#define __SELECTION_SORT_H__

#include "../standard_libraries.h"
#include "../function_types.h"

/**
 * @brief         Implement in-place selection sort on a generic type array.
 *
 * @param[in,out] basePtr      The pointer to the array.
 * @param[in]     arraySize    The size of the array.
 * @param[in]     elementSize  The size of the records.
 * @param[in]     compare      The compare function.
 */
void selection_sort(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare);

#endif
