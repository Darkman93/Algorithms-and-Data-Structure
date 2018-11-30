#include "comparators.h"

int compare_int(void* ptr1, void* ptr2)
{
  if (!ptr1 || !ptr2) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  int el1 = *(int*) ptr1;
  int el2 = *(int*) ptr2;
  if (el1  < el2) return -1;
  if (el1 == el2) return 0;
  return 1;
}

int compare_int_ptr(void* ptr1, void* ptr2)
{
  if (!ptr1 || !ptr2) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  int i1 = **(int**) ptr1;
  int i2 = **(int**) ptr2;
  if (i1  < i2) return -1;
  if (i1 == i2) return 0;
  return 1;
}

int compare_long_int(void* ptr1, void* ptr2)
{
  if (!ptr1 || !ptr2) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  long int el1 = (long int) ptr1;
  long int el2 = (long int) ptr2;
  if (el1  < el2) return -1;
  if (el1 == el2) return 0;
  return 1;
}

int compare_string(void* ptr1, void* ptr2)
{
  if (!ptr1 || !ptr2) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  return strcmp((char*) ptr1, (char*) ptr2);
}

int compare_string_ptr(void* ptr1, void* ptr2)
{
  if (!ptr1 || !ptr2) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  char* i1 = *(char**) ptr1;
  char* i2 = *(char**) ptr2;
  return strcmp(i1, i2);
}

int compare_double(void* ptr1, void* ptr2)
{
  if (!ptr1 || !ptr2) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  double el1 = *(double*) ptr1;
  double el2 = *(double*) ptr2;
  if (el1  < el2) return -1;
  if (el1 == el2) return 0;
  return 1;
}

int compare_double_pointer(void* ptr1, void* ptr2)
{
  if (!ptr1 || !ptr2) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  double el1 = **(double**) ptr1;
  double el2 = **(double**) ptr2;
  if (el1  < el2) return -1;
  if (el1 == el2) return 0;
  return 1;
}

int compare_float(void* ptr1, void* ptr2)
{
  if (!ptr1 || !ptr2) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  float el1 = *(float*) ptr1;
  float el2 = *(float*) ptr2;
  if (el1  < el2) return -1;
  if (el1 == el2) return 0;
  return 1;
}

int min_int(int a, int b)
{
  return a < b ? a : b;
}