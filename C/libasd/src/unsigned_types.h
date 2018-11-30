#ifndef __UNSIGNED_TYPES_H__
#define __UNSIGNED_TYPES_H__

#include "standard_libraries.h"

/**
 * This constant represent the @c size_t max value.
 */
#define SIZE_T_MAX_VALUE ((size_t) -1)

/**
 * This constant is used to simulate the -1 value of size_t.
 */
#define SIZE_T_LEFT_ZERO SIZE_T_MAX_VALUE

 /**
 * This constant is used to simulate the NULL value of size_t.
 */
#define SIZE_T_NULL SIZE_T_LEFT_ZERO

/*
bool size_t_overflowed(size_t base, size_t result)
{
  return base > result;
}
*/

#endif
