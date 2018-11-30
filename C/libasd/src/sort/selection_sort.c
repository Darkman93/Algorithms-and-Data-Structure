#include "selection_sort.h"
#include "../utils/swapping.h"

/*
 * Prototypes
 */

/**
 * @brief      Selects the least element in an array.
 *
 * @param[in]  basePtr      The pointer to the array.
 * @param[in]  arraySize    The size of the array.
 * @param[in]  elementSize  The size of the records.
 * @param[in]  compare      The compare functions.
 *
 * @return     The pointer to the least element.
 */
void* select(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare);

/*
 * Public functions
 */

void selection_sort(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare)
{
  if (!basePtr) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  if (arraySize <= 1 || elementSize == 0) return;

  void* current = basePtr;                              // Pointer to the current position.
  void* last = basePtr + elementSize * (arraySize - 1); // Pointer to the last element.
  size_t subArraySize = arraySize;                      // Size of the sub array where to search for the least element.

  while(current < last)
  {
    void* min = select(current, subArraySize, elementSize, compare);
    bytewise_swap(current, min, elementSize);
    current += elementSize;
    --subArraySize;
  }
}

/*
 * Private functions
 */

void* select(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare)
{
  void* current = basePtr + elementSize;         // Pointer to the current position.
  void* end = basePtr + elementSize * arraySize; // Pointer to the en of the array.
  void* min = basePtr;                           // Pointer to the least element.

  while(current < end)
  {
    if(compare(current, min) < 0) min = current;
    current += elementSize;
  }

  return min;
}