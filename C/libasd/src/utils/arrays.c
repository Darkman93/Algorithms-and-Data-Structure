#include "arrays.h"

void* array_at(size_t index, void* basePtr, size_t elementSize)
{
  if (!basePtr) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  return basePtr + elementSize * index;
}

void* array_end(void* basePtr, size_t arraySize, size_t elementSize)
{
  if (!basePtr) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  return array_at(arraySize, basePtr, elementSize);
}

void* array_clone(void* basePtr, size_t arraySize, size_t elementSize)
{
  if (!basePtr) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  size_t size   = arraySize*elementSize;
  void*  newPtr = malloc(size);
  memcpy(newPtr, basePtr, size);
  return newPtr;
}

bool array_sorted(void* basePtr, size_t arraySize, size_t elementSize, CompareFunction compare)
{
  if (!basePtr || !compare) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  for (size_t i=1; i < arraySize; ++i)
  {
    void* current  = array_at(i, basePtr, elementSize);
    void* previous = current - elementSize;
    if (compare(previous, current) > 0) return false;
  }
  return true;
}