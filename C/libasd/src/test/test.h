#ifndef __TEST_H__
#define __TEST_H__

#include "../standard_libraries.h"

/**
 * A simple struct for tests.
 */
typedef struct TestStruct {int x; int y;} TestStruct;

/*
 * Functions
 */

/**
 * @brief      Starts a testing session.
 */
void start_tests();

/**
 * @brief      Ends a test session.
 */
void end_tests();

/**
 * @brief      Calls a testing function wich should exit the program with an
 *             error if the test does not succeed.
 *
 * @param[in]  test_fun  The test function
 */
void test(void (*testFunction)());

/**
 * @brief      Compares two @c TestStruct.
 *
 * @param[in]  ptr1  The pointer to the first @c TestStruct.
 * @param[in]  ptr2  The pointer to the second @c TestStruct.
 *
 * @return     1 if the @c TestStruct pointed by @c ptr1 is greater than the @c
 *             TestStruct pointed by @c ptr2. -1 if the @c TestStruct pointed
 *             by@c ptr1 is lesser than the @c TestStruct pointed by ptr2. 0
 *             otherwise.
 */
int compare_test_struct(void* ptr1, void* ptr2);

#endif
