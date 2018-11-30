#include "numbers.h"

int* new_int(int value)
{
  int* result = (int*) malloc(sizeof(int));
  if(!result) error(EXIT_FAILURE, 0, "Malloc error in function %s", __func__);
  *result = value;
  return result;
}

void destroy_int_ptr(int** ptr)
{
	if(!ptr) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  free(*ptr);
  *ptr = NULL;
}

double* new_double(double value)
{
  double* result = (double*) malloc(sizeof(double));
  if(!result) error(EXIT_FAILURE, 0, "Malloc error in function %s", __func__);
  *result = value;
  return result;
}

void destroy_double_ptr(double** ptr)
{
	if(!ptr) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  free(*ptr);
  *ptr = NULL;
}