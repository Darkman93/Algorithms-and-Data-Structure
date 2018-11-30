#include "swapping.h"

void bytewise_swap(void* ptr1, void* ptr2, size_t elementSize)
{
  if(!ptr1 || !ptr2) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  char *a = ptr1;
  char *b = ptr2;
  do
  {
    char tmp = *a;
    *a++ = *b;
    *b++ = tmp;
  }
  while(--elementSize > 0);
}