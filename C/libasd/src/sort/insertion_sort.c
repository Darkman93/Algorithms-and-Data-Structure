#include "insertion_sort.h"
#include "../utils/arrays.h"

/*
 * Prototypes
 */

/**
 * @brief         Inserts an element in the right place in the preceding ordered part of the array.
 *
 * @param[in]     elementPtr   The pointer to the element.
 * @param[in,out] basePtr      The pointer to th array.
 * @param[in]     elementSize  The size of th records.
 * @param[in]     compare      The compare function.
 */
void insert(void* elementPtr, void* basePtr, size_t elementSize, CompareFunction compare);


/*
 * Public functions
 */

/*

BasePtr                                ArrayEnd
  v              Iterator                  v
  |                 v                      |
  |_________________|______________________|
  ^-----------------^----------------------^
       (sorted)           (not sorted)

*/
void insertion_sort(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare)
{
  if (!basePtr) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  if (arraySize <= 1 || elementSize == 0) return;

  void* arrayEnd = array_end(basePtr, arraySize, elementSize); // Pointer to the end of the array.
  void* iterator = basePtr + elementSize;                      // Pointer to the element to be inserted.

  while(iterator < arrayEnd)
  {
    insert(iterator, basePtr, elementSize, compare);
    iterator += elementSize;
  }
}

/*
 * Private functions
 */

/*

BasePtr                            ElementPointer
  v                Gap                   v
  |                 v                    |             |
  |_________________|____________________|_____________|
  ^-----------------^--------------------^
    (to be checked)       ( > pivot)

*/
void insert(void* elementPtr, void* basePtr, size_t elementSize, CompareFunction compare)
{
  void* pivot = malloc(elementSize); // Contains the element to be inserted.
  void* gap   = elementPtr;          // Pointer to the free position.
  memcpy(pivot, elementPtr, elementSize);

  while (gap > basePtr && compare(gap - elementSize, pivot) > 0)
  {
    memcpy(gap, gap - elementSize, elementSize);
    gap -= elementSize;
  }

  memcpy(gap, pivot, elementSize);
  free(pivot);
}