#include "heap_sort.h"
#include "../unsigned_types.h"
#include "../utils/arrays.h"
#include "../utils/swapping.h"

/*
 * Prototypes
 */

/**
 * @brief         Transforms an array in a max-heap in-place.
 *
 * @param[in,out] basePtr      The poiter to the array.
 * @param[in]     arraySize    The size of the array.
 * @param[in]     elementSize  The size of the records.
 * @param[in]     compare      The compare function.
 */
void max_heapify(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare);

/**
 * @brief         Sifts-down an element in a heap.
 *
 * @param[in]     index        The index of the node to be moved-down.
 * @param[in,out] basePtr      The poiter to the array.
 * @param[in]     heapSize     The size of the heap.
 * @param[in]     elementSize  The size of the records.
 * @param[in]     compare      The compare function.
 */
void moveDown(size_t index, void* basePtr, size_t heapSize, size_t elementSize, CompareFunction compare);

/**
 * @brief      Gets the index of the left child of a node in a heap.
 *
 * @param[in]  fatherIndex  The inde of the father node.
 *
 * @return     The index of the left child.
 */
size_t heap_left_child_index(size_t fatherIndex);

/*
 * Public functions
 */

/*

 Root                            LastNode
  v                                 v
  |_|_______________________________|_|_______________________|
  ^-----------------------------------^-----------------------^
                (heap)                         (sorted)
  ^-----------------------------------^
               HeapSize

*/
void heap_sort(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare)
{
  if (!basePtr) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  if (arraySize <= 1 || elementSize == 0) return;

  max_heapify (basePtr, arraySize, elementSize, compare);

  void*  lastNode = array_at(arraySize - 1, basePtr, elementSize); // Pointer to the last node.
  void*  root     = basePtr;                                       // Pointer to the root.
  size_t heapSize = arraySize;                                     // Size of the heap.

  while (lastNode > root)
  {
    bytewise_swap (root, lastNode, elementSize);
    moveDown (0, root, --heapSize, elementSize, compare);
    lastNode -= elementSize;
  }
}

/*
 * Private functions
 */

/*

 BasePointer
     v                 i          LastInternalNode
     |_|______________|_|_______________|_|_________________|
     ^------------------^-----------------------------------^
        (to be moved)                 (heap)

*/
void max_heapify(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare)
{
  size_t lastInternalNodeIndex = (arraySize - 1) >> 1; // Index of the last not-leaf node.
  size_t i = lastInternalNodeIndex;                    // Index of the current node.

  while(i != SIZE_T_LEFT_ZERO) moveDown(i--, basePtr, arraySize, elementSize, compare);
}

/*

BasePtr
   v            Current               MaxChild
   |              v                      v                |
   |______________|_|____________________|_|_|____________|
   ^------------------------------------------------------^
                          (HeapSize)

*/
void moveDown(size_t index, void* basePtr, size_t heapSize, size_t elementSize, CompareFunction compare)
{
  void*   current       = array_at(index, basePtr, elementSize);         // Pointer to the current node.
  size_t  maxChildIndex = heap_left_child_index(index);                  // The index of the greatest child.
  void*   maxChild      = array_at(maxChildIndex, basePtr, elementSize); // Pointer to the greatest child.

  void* pivot = malloc(elementSize);
  memcpy(pivot, current, elementSize);

  while (maxChildIndex < heapSize)
  {
    // Check if the right child is greater than the left child.
    if (maxChildIndex + 1 < heapSize && compare(maxChild + elementSize, maxChild) > 0)
    {
      ++maxChildIndex;
      maxChild += elementSize;
    }

    // If the pivot is grater or equal than the childs stop sift-down.
    if (compare(pivot, maxChild) >= 0) break;

    // Move up the max-child.
    memcpy(current, maxChild, elementSize);

    index         = maxChildIndex;
    current       = maxChild;
    maxChildIndex = heap_left_child_index (index);
    maxChild      = array_at (maxChildIndex, basePtr, elementSize);
  }

  memcpy(current, pivot, elementSize);
  free(pivot);
}

size_t heap_left_child_index(size_t fatherIndex)
{
  return 2 * fatherIndex + 1;
}