#ifndef __ARRAYS_H__
#define __ARRAYS_H__

#include "../standard_libraries.h"
#include "../function_types.h"

/**
 * @brief      Get a pointer to the i-th record of an array.
 *
 * @param[in]  index        The record index.
 * @param[in]  basePtr      The pointer to the base of the array.
 * @param[in]  elementSize  The size of the records.
 *
 * @return     The pointer to the i-th record of the array.
 */
void* array_at(size_t index, void* basePtr, size_t elementSize);

/**
 * @brief      Get a pointer to the end of an array.
 *
 * @param[in]  basePtr      The pointer to the base of the array.
 * @param[in]  arraySize    The size of the array.
 * @param[in]  elementSize  The size of the records.
 *
 * @return     The pointer to the first memory address after the last record of
 *             the array.
 */
void* array_end(void* basePtr, size_t arraySize, size_t elementSize);

/**
 * @brief      Clone an array.
 *
 * @param[in]  basePtr      The pointer to the base of the array.
 * @param[in]  arraySize    The size of the array.
 * @param[in]  elementSize  The size of the records.
 *
 * @return     The pointer to the copy of the original array.
 */
void* array_clone(void* basePtr, size_t arraySize, size_t elementSize);

/**
 * @brief      Verify if an array is sorted.
 *
 * @param[in]  basePtr      The pointer to the base of the array.
 * @param[in]  arraySize    The size of the array.
 * @param[in]  elementSize  The size of the records.
 * @param[in]  compare      The function to compare two elements.
 *
 * @return     @c true if array is sorted, @c false otherwise.
 */
bool array_sorted(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare);

#endif