#ifndef __INTEGERS_H__
#define __INTEGERS_H__

#include "../standard_libraries.h"

/**
 * @brief      Initialize an @c *int.
 *
 * @param[in]  value  The value to be stored in the pointed record.
 *
 * @return     The pointer to the record.
 */
int* new_int(int value);

/**
 * @brief      Delete an @c *int.
 *
 * @param[in]  ptr   The pointer to be deleted.
 */
void destroy_int_ptr(int** ptr);

/**
 * @brief      Initialize an @c *int.
 *
 * @param[in]  value  The value to be stored in the pointed record.
 *
 * @return     The pointer to the record.
 */
double* new_double(double value);

/**
 * @brief      Delete an @c *int.
 *
 * @param[in]  ptr   The pointer to be deleted.
 */
void destroy_double_ptr(double** ptr);

#endif