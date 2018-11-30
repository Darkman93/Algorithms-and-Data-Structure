#include <assert.h>
#include "../../src/standard_libraries.h"
#include "../../include/test.h"
#include "../../include/utils.h"
#include "../../include/sort.h"

void test_insertion_sort_on_null_array()
{
  int* array = NULL;
  insertion_sort(array , 0 , sizeof(NULL) , compare_int);
  assert(array == NULL);
}

void test_insertion_sort_on_empty_array()
{
  int array[0] = {};
  insertion_sort(array , 0 , sizeof(int) , compare_int);
  assert(1);
}

void test_insertion_sort_on_int_array_with_single_element()
{
  size_t size = 1;
  size_t elementSize = sizeof(int);
  int array[] = {11};
  insertion_sort(array, size, elementSize, compare_int);
  assert(array_sorted(array, size, elementSize, compare_int));
}

void test_insertion_sort_on_int_array_with_two_elements()
{
  size_t size = 2;
  size_t elementSize = sizeof(int);
  int array[] = {11, 1};
  insertion_sort(array, size, elementSize, compare_int);
  assert(array_sorted(array, size, elementSize, compare_int));
}

void test_insertion_sort_on_int_array_with_two_elements_sorted()
{
  size_t size = 2;
  size_t elementSize = sizeof(int);
  int array[] = {1, 11};
  insertion_sort(array, size, elementSize, compare_int);
  assert(array_sorted(array, size, elementSize, compare_int));
}

void test_insertion_sort_on_int_array()
{
  size_t size = 5;
  size_t elementSize = sizeof(int);
  int array[] = { 11, 4, 1, 8, 10 };
  insertion_sort(array, size, elementSize, compare_int);
  assert(array_sorted(array, size, elementSize, compare_int));
}

void test_insertion_sort_on_int_sorted_array()
{
  size_t size = 5;
  size_t elementSize = sizeof(int);
  int array[] = { 0, 3, 4, 10, 13 };
  insertion_sort(array, size, elementSize, compare_int);
  assert(array_sorted(array, size, elementSize, compare_int));
}

void test_insertion_sort_on_int_equal_array()
{
  size_t size = 5;
  size_t elementSize = sizeof(int);
  int array[] = { 1, 1, 1, 1, 1 };
  insertion_sort(array, size, elementSize, compare_int);
  assert(array_sorted(array, size, elementSize, compare_int));
}

void test_insertion_sort_on_struct_array()
{
  size_t size = 5;
  size_t elementSize = sizeof(TestStruct);
  TestStruct array[] = { {11,1} , {4,2} , {1,3} , {8,4} , {10,5} };
  insertion_sort(array, size, elementSize, compare_test_struct);
  assert(array_sorted(array, size, elementSize, compare_int));
}

void test_insertion_sort_on_ptr_array()
{
  size_t size = 5;
  size_t elementSize = sizeof(int*);
  int* array[size];
  array[0] = new_int(11);
  array[1] = new_int(4);
  array[2] = new_int(1);
  array[3] = new_int(8);
  array[4] = new_int(10);

  insertion_sort(array, size, sizeof(int*), compare_int_ptr);
  assert(array_sorted(array, size, elementSize, compare_int_ptr));
  for(int i=0; i < size; ++i) free(array[i]);
}

//
// Main
//
int main(int argc, char  *argv[])
{
  start_tests("insertion sort");
  //test(test_insertion_sort_on_null_array);
  test(test_insertion_sort_on_empty_array);
  test(test_insertion_sort_on_int_array_with_single_element);
  test(test_insertion_sort_on_int_array_with_two_elements);
  test(test_insertion_sort_on_int_array_with_two_elements_sorted);
  test(test_insertion_sort_on_int_array);
  test(test_insertion_sort_on_int_sorted_array);
  test(test_insertion_sort_on_int_equal_array);
  test(test_insertion_sort_on_struct_array);
  test(test_insertion_sort_on_ptr_array);
  end_tests();
  return EXIT_SUCCESS;
}