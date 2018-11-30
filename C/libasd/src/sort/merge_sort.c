#include "merge_sort.h"
#include "../utils/arrays.h"

/*
 * Prototypes
 */

/**
 * @brief         Implements merge sort on a generic type array.
 *
 * @param[in,out] basePtr      The pointer to the array.
 * @param[in]     arraySize    The size of the array.
 * @param[in]     elementSize  The size of the records.
 * @param[in]     compare      The compare function.
 * @param         auxBasePtr   The pointer to the auxiliary array.
 */
void m_sort(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare, void* auxBasePtr);

/**
 * @brief        Merges two ordered parts of an array.
 *
 * @param[in,ou] basePtr      The pointer to the first part of the array.
 * @param[in]    middlePtr    The pointer to the second part of the array.
 * @param[in]    arraySize    The size of the entire array.
 * @param[in]    elementSize  The size of the elements.
 * @param[in]    compare      The compare function.
 * @param        auxBasePtr   The pointer to the auxiliary array.
 */
void merge(void* basePtr, void* middlePtr, size_t arraySize, size_t elementSize, CompareFunction compare, void* auxBasePtr);

/*
 * Public functions
 */

void merge_sort(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare)
{
  if (!basePtr) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  if (arraySize <= 1 || elementSize == 0) return;

  void* auxBasePtr = malloc(arraySize * elementSize); // Auxiliary array.

  m_sort(basePtr, arraySize, elementSize, compare, auxBasePtr);

  free(auxBasePtr);
}

/*
 * Private functions
 */

void m_sort(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare, void* auxBasePtr)
{
  if (arraySize <= 1) return;

  size_t firstHalfSize  = arraySize >> 1;                                // Size of the first part of the array.
  size_t secondHalfSize = arraySize - firstHalfSize;                     // Size of the second part of the array.
  void*  firstHalfPtr   = basePtr;                                       // Pointer to the first part of the array.
  void*  secondHalfPtr  = array_at(firstHalfSize, basePtr, elementSize); // Pointer to the second part of the array.

  m_sort(firstHalfPtr,  firstHalfSize,  elementSize, compare, auxBasePtr);
  m_sort(secondHalfPtr, secondHalfSize, elementSize, compare, auxBasePtr);

  merge(firstHalfPtr, secondHalfPtr, arraySize, elementSize, compare, auxBasePtr);
}

/*

  BasePtr                           MiddlePtr                         EndPtr
    v       LeftPointer                v        RightPtr                  v
    |           v                      |           v                      |
    |___________|______________________|___________|______________________|
    ^-----------^----------------------^-----------^----------------------^
      (merged)     (to be merged)        (merged)      (to be merged)
    ^----------------------------------^----------------------------------^
                (sorted)                           (sorted)


 AuxBasePtr
    v                    AuxPtr
    |                      v                                              |
    |______________________|______________________________________________|
    ^----------------------^----------------------------------------------^
            (filled)                        (to be filled)
    ^----------------------^
            (sorted)

*/
void merge(void* basePtr, void* middlePtr, size_t arraySize, size_t elementSize, CompareFunction compare, void* auxBasePtr)
{
  size_t arrayDimension = arraySize * elementSize; // Size of the array in bytes.

  void* leftPtr  = basePtr;                  // Ponter to the current element of the first half of the array.
  void* rightPtr = middlePtr;                // Ponter to the current element of the second half of the array.
  void* endPtr   = basePtr + arrayDimension; // Pointer to the end of the array.
  void* auxPtr   = auxBasePtr;               // Pointer to the first free position of the auxiliary array.

  while (leftPtr < middlePtr && rightPtr < endPtr)
  {
    if (compare(leftPtr, rightPtr) <= 0)
    {
      memcpy(auxPtr, leftPtr, elementSize);
      auxPtr  += elementSize;
      leftPtr += elementSize;
    }
    else
    {
      memcpy(auxPtr, rightPtr, elementSize);
      auxPtr   += elementSize;
      rightPtr += elementSize;
    }
  }

  while (leftPtr < middlePtr)
  {
    memcpy(auxPtr, leftPtr, elementSize);
    auxPtr  += elementSize;
    leftPtr += elementSize;
  }

  while (rightPtr < endPtr)
  {
    memcpy(auxPtr, rightPtr, elementSize);
    auxPtr   += elementSize;
    rightPtr += elementSize;
  }

  memcpy(basePtr, auxBasePtr, arrayDimension);
}