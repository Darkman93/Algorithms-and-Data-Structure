#ifndef __COMPARATORS_H__
#define __COMPARATORS_H__

#include "../standard_libraries.h"
#include "../function_types.h"

/**
 * @brief      Compares two @c int.
 *
 * @param[in]  ptr1  The pointer to the first @c int.
 * @param[in]  ptr2  The pointer to the second @c int.
 *
 * @return     1 if the @c int pointed by @c ptr1 is greater than the @c int
 *             pointed by @c ptr2. -1 if the @c int pointed by @c ptr1 is lesser
 *             than the @c int pointed by ptr2. 0 otherwise.
 */
int compare_int(void* ptr1, void* ptr2);

/**
 * @brief      Compares two @c *int.
 *
 * @param[in]  ptr1  The pointer to the first @c *int.
 * @param[in]  ptr2  The pointer to the second @c *int.
 *
 * @return     1 if the @c int pointed by @c *ptr1 is greater than the @c int
 *             pointed by @c *ptr2. -1 if the @int pointed by @c *ptr1 is lesser
 *             than the @c int pointed by @c *ptr2. 0 otherwise.
 */
int compare_int_ptr(void* ptr1, void* ptr2);

/**
 * @brief      Compares two @c long @c int.
 *
 * @param[in]  ptr1  The pointer to the first @c long @c int.
 * @param[in]  ptr2  The pointer to the second @c long @c int.
 *
 * @return     1 if the @c long @c int pointed by @c ptr1 is greater than the @c
 *             long @c int pointed by @c ptr2. -1 if the @c long @c int pointed
 *             by @c ptr1 is lesser than the @c long @c int pointed by @c ptr2.
 *             0 otherwise.
 */
int compare_long_int(void* ptr1, void* ptr2);

/**
 * @brief      Compares two strings lexicographically.
 *
 * @param[in]  ptr1  The pointer to the first string.
 * @param[in]  ptr2  The pointer to the second string.
 *
 * @return     An @c int > 0 if the string pointed by @c ptr1 is
 *             lexicographically greater than the string pointed by @c ptr2.
 *             An@c int < 0 if the string pointed by @c ptr1 is
 *             lexicographically lesser than the string pointed by @c ptr2. 0
 *             otherwise.
 */
int compare_string(void* ptr1, void* ptr2);

/**
 * @brief      Compares two pointers to string.
 *
 * @param[in]  ptr1  The pointer to the first pointer to string.
 * @param[in]  ptr2  The pointer to the second pointer to string.
 *
 * @return     An @c int > 0 if the string pointed by @c *ptr1 is
 *             lexicographically greater than the string pointed by @c *ptr2.
 *             An@c int < 0 if the string pointed by @c *ptr1 is
 *             lexicographically lesser than the string pointed by @c *ptr2. 0
 *             otherwise.
 */
int compare_string_ptr(void* ptr1, void* ptr2);

/**
 * @brief      Compares two @c double.
 *
 * @param[in]  ptr1  The pointer to the first @c double.
 * @param[in]  ptr2  The pointer to the second @c double.
 *
 * @return     1 if the @double pointed by @c ptr1 is greater than the @c double
 *             pointed by @c ptr2. -1 if the @c double pointed by @c ptr1 is
 *             lesser than the @c double pointed by @c ptr2. 0 otherwise.
 */
int compare_double(void* ptr1, void* ptr2);

/**
 * @brief      Compares two @c *double.
 *
 * @param[in]  ptr1  The pointer to the first @c *double.
 * @param[in]  ptr2  The pointer to the second @c *double.
 *
 * @return     1 if the @double pointed by @c ptr1 is greater than the @c double
 *             pointed by @c ptr2. -1 if the @c double pointed by @c ptr1 is
 *             lesser than the @c double pointed by @c ptr2. 0 otherwise.
 */
int compare_double_pointer(void* ptr1, void* ptr2);

/**
 * @brief      Compares two @c float.
 *
 * @param[in]  ptr1  The pointer to the first @c float.
 * @param[in]  ptr2  The pointer to the second @c float.
 *
 * @return     1 if the @c float pointed by @c ptr1 is greater than the @c float
 *             pointed by @c ptr2. -1 if the @c float pointed by @c ptr1 is
 *             lesser than the @c float pointed by @c ptr2. 0 otherwise.
 */
int compare_float(void* ptr1, void* ptr2);

/**
 * @brief      Selects the minimum between two @c int.
 *
 * @param[in]  a     The first @c int.
 * @param[in]  b     The second @c int.
 *
 * @return     The minimum between the two numbers.
 */
int min_int(int a, int b);

#endif