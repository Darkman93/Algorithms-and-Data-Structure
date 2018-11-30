#include "quick_sort.h"
#include "../utils/swapping.h"

//
// Data Structures
//

/**
 * This structure contains the relevant informations about a tripartition.
 */
typedef struct PartitionData
{
  size_t lesserSize;  // Number of elements lesser than the pivot.
  void* greaterBase;  // Pointer to the first element greater than the pvot.
  size_t greaterSize; // Number fo elements greater than the pivot.
}
PartitionData;


//
// Prototypes
//

/**
 * @brief         Implements in-place quick sort on a generic type array.
 *
 * @param[in,out] basePtr      The pointer to the array.
 * @param[in]     arraySize    The size of the array.
 * @param[in]     elementSize  The size of the records.
 * @param[in]     compare      The compare function.
 */
void q_sort(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare);

/**
 * @brief         Tripartition an array.
 *
 * @param[in,out] basePtr      The pointer to the base of the array.
 * @param[in]     arraySize    The size of the array.
 * @param[in]     elementSize  The size of the records.
 * @param[in]     compare      The compare function.
 *
 * @return        The partition data.
 */
PartitionData tripartition(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare);

/**
 * @brief      Chooses a pivot in an array using the median-of-three method.
 *
 * @param[in]  basePtr      The pointer to th base of th array.
 * @param[in]  arraySize    The size of the array.
 * @param[in]  elementSize  The size of th records.
 * @param[in]  compare      The compare function.
 *
 * @return     The pivot.
 */
void* get_pivot(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare);


//
// Public functions
//

void quick_sort(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare)
{
  if (!basePtr) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  if (arraySize <= 1 || elementSize == 0) return;

  q_sort(basePtr, arraySize,elementSize, compare);
}

//
// Private functions
//

void q_sort(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare)
{
  if (arraySize > 1)
  {
    PartitionData partition = tripartition(basePtr, arraySize, elementSize, compare);

    quick_sort(basePtr, partition.lesserSize, elementSize, compare);
    quick_sort(partition.greaterBase, partition.greaterSize, elementSize, compare);
  }
}

/*

 BasePtr
   v              LesserIndex             EqualIndex                        GreaterIndex
   |                  v                      v                                   v                   |
   |__________________|______________________|___________________________________|___________________|
   ^------------------^----------------------^-----------------------------------^-------------------^
        (< pivot)           (= pivot)                  (to be checked)                 (> pivot)
   ^------------------^                                                          ^-------------------^
       (LesserSize)                                                                   (GreateSize)

*/
PartitionData tripartition(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare)
{
  void* pivot = get_pivot(basePtr, arraySize, elementSize, compare);

  void* lesserIndex  = basePtr;                                 // Pointer to the first position after the last element of the left partition.
  void* equalIndex   = basePtr;                                 // Pointer to the first position after the last element of the central partition.
  void* greaterIndex = basePtr + elementSize * (arraySize - 1); // Pointer to the first position before the first element of the right partition.

  size_t lesserSize  = 0;
  size_t greaterSize = 0;

  //EqualIndex is also teh next element to be compared to the pivot.
  while (equalIndex <= greaterIndex)
  {
    if (compare(equalIndex, pivot) == 0)
    {
      equalIndex += elementSize;
    }

    else if (compare(equalIndex, pivot) < 0)
    {
      bytewise_swap(equalIndex, lesserIndex, elementSize);
      lesserIndex += elementSize;
      equalIndex  += elementSize;
      ++lesserSize;
    }

    else
    {
      // Decrement GreaterIndex while possible in order to not swap twice a greater-than-the-pivot element.
      while (equalIndex < greaterIndex && compare(greaterIndex, pivot) > 0)
      {
        greaterIndex -= elementSize;
        ++greaterSize;
      }

      bytewise_swap(equalIndex, greaterIndex, elementSize);
      greaterIndex -= elementSize;
      ++greaterSize;
    }
  }

  free(pivot);

  PartitionData partition = {lesserSize, greaterIndex + elementSize, greaterSize};
  return partition;
}

void* get_pivot(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare)
{
  void* first  = basePtr;                                  // Firts element of the array.
  void* middle = basePtr + elementSize * (arraySize >> 1); // Central element of the array.
  void* last   = basePtr + elementSize * (arraySize - 1);  // Last element of the array.

  // Swap the 3 elements so they are ordered in a not-decrescent way.
  if (compare(middle, first ) < 0) bytewise_swap(middle, first,  elementSize);
  if (compare(last,   middle) < 0) bytewise_swap(last,   middle, elementSize);
  if (compare(middle, first ) < 0) bytewise_swap(middle, first,  elementSize);

  // The central element is the pivot.
  // It is the median among the 3 elements.
  void* pivot = malloc(elementSize);
  memcpy(pivot, middle, elementSize);
  return pivot;
}


























//
// CORMEN'S IMPLEMENTATION
//

size_t partition(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare);

void quick_sort_cormen(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare)
{
  if (arraySize > 1)
  {
    size_t lesserEqualNumber = partition(basePtr, arraySize, elementSize, compare);
    size_t greaterNumber     = arraySize - lesserEqualNumber;
    void*  greaterPtr        = basePtr + elementSize * lesserEqualNumber;
    quick_sort_cormen(basePtr, lesserEqualNumber - 1, elementSize, compare);
    quick_sort_cormen(greaterPtr, greaterNumber, elementSize, compare);
  }
}


size_t partition(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare)
{
  void* pivot = basePtr + elementSize * (arraySize - 1);
  void* current = basePtr;
  size_t lesserEqualNumber = 0;
  while (current < pivot)
  {
    if (compare(current, pivot) <= 0)
    {
      bytewise_swap(current, basePtr, elementSize);
      basePtr += elementSize;
      ++lesserEqualNumber;
    }
    current += elementSize;
  }
  bytewise_swap(pivot, basePtr, elementSize);
  return lesserEqualNumber + 1;
}
