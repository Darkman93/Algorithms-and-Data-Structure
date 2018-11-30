#include <assert.h>
#include "../../src/standard_libraries.h"
#include "../../include/test.h"
#include "../../include/utils.h"
#include "../../include/list_map.h"
#include "../../src/list_map/list_map_debug.h"
#include "../../include/sort.h"


ListMap init_list(ListMap list, int keys[], char* values[], int size)
{
  for (int i=0; i < size; ++i)
  {
    list_map_put(list, &(keys[i]), values[i]);
    assert(list_map_size(list) == i+1);
  }
  return list;
}


//
// list_map_is_empty
//
void test_list_map_is_empty()
{
  ListMap list = new_list_map(compare_int);
  int key = 0;
  assert(list_map_is_empty(list));
  list_map_put(list, &key, NULL);
  assert(!list_map_is_empty(list));
  destroy_list_map(&list);
}


//
// list_map_get
//
void test_list_map_get_empty()
{
  ListMap list = new_list_map(compare_int);
  int key = 0;
  assert(!list_map_get(list, &key));
  destroy_list_map(&list);
}

void test_list_map_get()
{
  ListMap list = new_list_map(compare_int);
  int            size = 8;
  int          keys[] = {6, 7, 1, 2, 8, 4, 3, 5};
  int*     sortedKeys = (int*) array_clone(keys, 8, sizeof(int));
  char*      values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-"};
  char** sortedValues = (char**) array_clone(values, 8, sizeof(char*));
  insertion_sort(sortedKeys, list_map_count(list), sizeof(int), compare_int);
  insertion_sort(sortedValues, list_map_count(list), sizeof(char*), compare_string_ptr);
  list = init_list(list, keys, values, size);

  for (int i=0; i < size; ++i)
  {
    char* result = (char*) list_map_get(list, &(keys[i]));
    assert(!strcmp(result, sortedValues[i]));
  }

  destroy_list_map(&list);
}

//
// list_map_put
//
void test_list_map_put_some_element()
{
  ListMap list = new_list_map(compare_int);
  int            size = 8;
  int          keys[] = {6, 7, 1, 2, 8, 4, 3, 5};
  int*     sortedKeys = (int*) array_clone(keys, 8, sizeof(int));
  char*      values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-"};
  char** sortedValues = (char**) array_clone(values, 8, sizeof(char*));
  insertion_sort(sortedKeys, list_map_count(list), sizeof(int), compare_int);
  insertion_sort(sortedValues, list_map_count(list), sizeof(char*), compare_string_ptr);

  for (int i=0; i < size; ++i)
  {
    assert(!list_map_put(list, &(keys[i]), values[i]));
    assert(list_map_size(list) == i+1);
  }
  for (int i=0; i < size; ++i)
  {
    char* result = (char*) list_map_get(list, &(keys[i]));
    assert(!strcmp(result, sortedValues[i]));
  }
  assert(list_map_size(list) == 8);

  destroy_list_map(&list);
}

void test_list_map_put_with_replace()
{
  ListMap list = new_list_map(compare_int);
  int            size = 8;
  int          keys[] = {6, 7, 1, 2, 8, 4, 3, 5};
  int*     sortedKeys = (int*) array_clone(keys, 8, sizeof(int));
  char*      values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-", "9-"};
  char** sortedValues = (char**) array_clone(values, 8, sizeof(char*));
  insertion_sort(sortedKeys, list_map_count(list), sizeof(int), compare_int);
  insertion_sort(sortedValues, list_map_count(list), sizeof(char*), compare_string_ptr);
  list = init_list(list, keys, values, size);

  char* result = (char*) list_map_put(list, &(sortedKeys[3]), values[8]);
  assert(!strcmp(result, sortedValues[3]));
  result = (char*) list_map_get(list, &sortedKeys[3]);
  assert(!strcmp(result, values[8]));
  assert(list_map_size(list) == 8);
  for (int i=0; i < size; ++i)
  {
    char* result = (char*) list_map_get(list, &(sortedKeys[i]));
    if(i == 3) assert(!strcmp(result, values[8]));
    else assert(!strcmp(result, sortedValues[i]));
  }

  destroy_list_map(&list);
}


//
// list_map_remove
//
void test_list_map_remove_on_empty_list()
{
  ListMap list = new_list_map(compare_int);
  int key = 0;
  assert(!list_map_remove(list, &key));

  destroy_list_map(&list);
}

void test_list_map_remove_first()
{
  ListMap list = new_list_map(compare_int);
  int            size = 8;
  int          keys[] = {6, 7, 1, 2, 8, 4, 3, 5};
  int*     sortedKeys = (int*) array_clone(keys, 8, sizeof(int));
  char*      values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-", "9-"};
  char** sortedValues = (char**) array_clone(values, 8, sizeof(char*));
  insertion_sort(sortedKeys, list_map_count(list), sizeof(int), compare_int);
  insertion_sort(sortedValues, list_map_count(list), sizeof(char*), compare_string_ptr);
  list = init_list(list, keys, values, size);

  char* result = (char*) list_map_remove(list, &(sortedKeys[0]));
  assert(!strcmp(result, sortedValues[0]));
  assert(list_map_size(list) == 7);
  assert(!list_map_get(list, &sortedKeys[0]));

  destroy_list_map(&list);
}

void test_list_map_remove_last()
{
  ListMap list = new_list_map(compare_int);
  int            size = 8;
  int          keys[] = {6, 7, 1, 2, 8, 4, 3, 5};
  int*     sortedKeys = (int*) array_clone(keys, 8, sizeof(int));
  char*      values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-", "9-"};
  char** sortedValues = (char**) array_clone(values, 8, sizeof(char*));
  insertion_sort(sortedKeys, list_map_count(list), sizeof(int), compare_int);
  insertion_sort(sortedValues, list_map_count(list), sizeof(char*), compare_string_ptr);
  list = init_list(list, keys, values, size);

  char* result = (char*) list_map_remove(list, &(sortedKeys[7]));
  assert(!strcmp(result, sortedValues[7]));
  assert(list_map_size(list) == 7);
  assert(!list_map_get(list, &sortedKeys[7]));

  destroy_list_map(&list);
}

void test_list_map_remove_middle()
{
  ListMap list = new_list_map(compare_int);
  int            size = 8;
  int          keys[] = {6, 7, 1, 2, 8, 4, 3, 5};
  int*     sortedKeys = (int*) array_clone(keys, 8, sizeof(int));
  char*      values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-", "9-"};
  char** sortedValues = (char**) array_clone(values, 8, sizeof(char*));
  insertion_sort(sortedKeys, list_map_count(list), sizeof(int), compare_int);
  insertion_sort(sortedValues, list_map_count(list), sizeof(char*), compare_string_ptr);
  list = init_list(list, keys, values, size);

  char* result = (char*) list_map_remove(list, &(sortedKeys[3]));
  assert(!strcmp(result, sortedValues[3]));
  assert(list_map_size(list) == 7);
  assert(!list_map_get(list, &sortedKeys[3]));

  destroy_list_map(&list);
}


//
// list_map_size
//
void test_list_map_size_on_empty_list()
{
  ListMap list = new_list_map(compare_int);
  assert(!list_map_size(list));
  assert(list_map_size(list) == list_map_count(list));

  destroy_list_map(&list);
}

void test_list_map_size_on_list_with_one_element()
{
  ListMap list = new_list_map(compare_int);
  int     keys[] = {1};
  char* values[] = {"1-"};
  list_map_put(list, &(keys[0]), &(values[0]));

  assert(list_map_size(list) == 1);
  assert(list_map_size(list) == list_map_count(list));

  destroy_list_map(&list);
}


void test_list_map_size_generic()
{
  ListMap list = new_list_map(compare_int);
  int size = 9;
  int     keys[] = {6, 7, 1, 2, 8, 4, 3, 5, 9};
  char* values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-", "9-"};

  list = init_list(list, keys, values, size);

  assert(list_map_size(list) == size);
  assert(list_map_size(list) == list_map_count(list));

  destroy_list_map(&list);
}


//
// Main
//
int main(int argc, char  *argv[])
{
  start_tests("List Map");

  test(test_list_map_is_empty);
  //end_tests();

  //start_tests("list_map_get");
  test(test_list_map_get_empty);
  test(test_list_map_get);
  //end_tests();

  //start_tests("list_map_put");
  test(test_list_map_put_some_element);
  test(test_list_map_put_with_replace);
  //end_tests();

  //start_tests("list_map_remove");
  test(test_list_map_remove_on_empty_list);
  test(test_list_map_remove_first);
  test(test_list_map_remove_last);
  test(test_list_map_remove_middle);
  //end_tests();

  //start_tests("list_map_size");
  test(test_list_map_size_on_empty_list);
  test(test_list_map_size_on_list_with_one_element);
  test(test_list_map_size_generic);
  end_tests();

  exit(EXIT_SUCCESS);
}
