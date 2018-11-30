#include "test.h"

/*
 * Global variables
 */

static clock_t startTime;
static unsigned int numTests;

/*
 * Functions
 */

void start_tests()
{
  numTests  = 0;
  startTime = clock();
}

void end_tests()
{
  double elapsedTime = (clock() - startTime) / (double)CLOCKS_PER_SEC;
  printf("\n%d tests passed in %4.5f seconds\n", numTests, elapsedTime);
}

void test(void (*testFunction)())
{
  numTests += 1;
  printf(".");
  testFunction();
}

int compare_test_struct(void* ptr1,  void* ptr2)
{
  TestStruct* s1 = (TestStruct*) ptr1;
  TestStruct* s2 = (TestStruct*) ptr2;
  if(s1->x < s2->x) return -1;
  if(s1->x == s2->x) return 0;
  return 1;
}