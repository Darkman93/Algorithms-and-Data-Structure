#include <assert.h>
#include "../../src/standard_libraries.h"
#include "../../include/test.h"
#include "../../include/utils.h"
#include "../../include/list_map.h"

//
// list_map_iterator_current_key
// list_map_iterator_current_value
//

void test_list_map_iterator_current_key_value_on_empty_list()
{
  ListMap list = new_list_map(compare_int);
  ListMapIterator iterator = new_list_map_iterator(list);

  assert(!list_map_iterator_current_key(iterator));

  destroy_list_map_iterator(&iterator);
  destroy_list_map(&list);
}

void test_list_map_iterator_current_key()
{
  ListMap list = new_list_map(compare_int);
  int        size = 8;
  int      keys[] = {6, 7, 1, 2, 8, 4, 3, 5};
  char*  values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-"};
  for (int i=0; i < size; ++i) list_map_put(list, &(keys[i]), values[i]);
  ListMapIterator iterator = new_list_map_iterator(list);

  for (int i = 0; i < 3; ++i) list_map_iterator_next(iterator);
  int key = *(int*) list_map_iterator_current_key(iterator);
  assert(key == keys[6]);

  destroy_list_map_iterator(&iterator);
  destroy_list_map(&list);
}

void test_list_map_iterator_current_value()
{
  ListMap list = new_list_map(compare_int);
  int        size = 8;
  int      keys[] = {6, 7, 1, 2, 8, 4, 3, 5};
  char*  values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-"};
  for (int i=0; i < size; ++i) list_map_put(list, &(keys[i]), values[i]);
  ListMapIterator iterator = new_list_map_iterator(list);

  for (int i = 0; i < 3; ++i) list_map_iterator_next(iterator);
  char* value = (char*) list_map_iterator_current_value(iterator);
  assert(!strcmp(value, values[6]));

  destroy_list_map_iterator(&iterator);
  destroy_list_map(&list);
}

//
// list_map_iterator_has_next
//
void test_list_map_iterator_has_next_on_empty_list()
{
  ListMap list = new_list_map(compare_int);
  ListMapIterator iterator = new_list_map_iterator(list);

  assert(!list_map_iterator_has_next(iterator));

  destroy_list_map_iterator(&iterator);
  destroy_list_map(&list);
}

void test_list_map_iterator_has_next_on_first()
{
  ListMap list = new_list_map(compare_int);
  int        size = 8;
  int      keys[] = {6, 7, 1, 2, 8, 4, 3, 5};
  char*  values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-"};
  for (int i=0; i < size; ++i) list_map_put(list, &(keys[i]), values[i]);
  ListMapIterator iterator = new_list_map_iterator(list);

  list_map_iterator_next(iterator);
  assert(list_map_iterator_has_next(iterator));

  destroy_list_map_iterator(&iterator);
  destroy_list_map(&list);
}

void test_list_map_iterator_has_next_on_middle()
{
  ListMap list = new_list_map(compare_int);
  int        size = 8;
  int      keys[] = {6, 7, 1, 2, 8, 4, 3, 5};
  char*  values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-"};
  for (int i=0; i < size; ++i) list_map_put(list, &(keys[i]), values[i]);
  ListMapIterator iterator = new_list_map_iterator(list);

  for (int i = 0; i < 3; ++i) list_map_iterator_next(iterator);
  assert(list_map_iterator_has_next(iterator));

  destroy_list_map_iterator(&iterator);
  destroy_list_map(&list);
}

void test_list_map_iterator_has_next_on_last()
{
  ListMap list = new_list_map(compare_int);
  int        size = 8;
  int      keys[] = {6, 7, 1, 2, 8, 4, 3, 5};
  char*  values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-"};
  for (int i=0; i < size; ++i) list_map_put(list, &(keys[i]), values[i]);
  ListMapIterator iterator = new_list_map_iterator(list);

  for (int i = 0; i < size; ++i) list_map_iterator_next(iterator);
  assert(!list_map_iterator_has_next(iterator));

  destroy_list_map_iterator(&iterator);
  destroy_list_map(&list);
}

//
// list_map_iterator_next
//
void test_list_map_iterator_next_on_empty_list()
{
  ListMap list = new_list_map(compare_int);
  ListMapIterator iterator = new_list_map_iterator(list);

  assert(!list_map_iterator_next(iterator));

  destroy_list_map_iterator(&iterator);
  destroy_list_map(&list);
}

void test_list_map_iterator_next_on_first()
{
  ListMap list = new_list_map(compare_int);
  int        size = 8;
  int      keys[] = {6, 7, 1, 2, 8, 4, 3, 5};
  char*  values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-"};
  for (int i=0; i < size; ++i) list_map_put(list, &(keys[i]), values[i]);
  ListMapIterator iterator = new_list_map_iterator(list);

  // Check before first position
  assert(!list_map_iterator_current_key(iterator));
  assert(!list_map_iterator_current_value(iterator));

  assert(list_map_iterator_next(iterator));

  // Check first position
  int key = *(int*) list_map_iterator_current_key(iterator);
  char* value = (char*) list_map_iterator_current_value(iterator);
  assert(key == keys[2]);
  assert(!strcmp(value, values[2]));

  destroy_list_map_iterator(&iterator);
  destroy_list_map(&list);
}

void test_list_map_iterator_next_on_last()
{
  ListMap list = new_list_map(compare_int);
  int        size = 8;
  int      keys[] = {6, 7, 1, 2, 8, 4, 3, 5};
  char*  values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-"};
  for (int i=0; i < size; ++i) list_map_put(list, &(keys[i]), values[i]);
  ListMapIterator iterator = new_list_map_iterator(list);

  // Check last
  for (int i = 0; i < size; ++i) assert(list_map_iterator_next(iterator));
  int key = *(int*) list_map_iterator_current_key(iterator);
  char* value = (char*) list_map_iterator_current_value(iterator);
  assert(key == keys[4]);
  assert(!strcmp(value, values[4]));

  assert(!list_map_iterator_next(iterator));

  destroy_list_map_iterator(&iterator);
  destroy_list_map(&list);
}


void test_list_map_iterator_next_on_middle()
{
  ListMap list = new_list_map(compare_int);
  int        size = 8;
  int      keys[] = {6, 7, 1, 2, 8, 4, 3, 5};
  char*  values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-"};
  for (int i=0; i < size; ++i) list_map_put(list, &(keys[i]), values[i]);
  ListMapIterator iterator = new_list_map_iterator(list);

  // Check before the step
  for (int i = 0; i < 3; ++i) assert(list_map_iterator_next(iterator));
  int key = *(int*) list_map_iterator_current_key(iterator);
  char* value = (char*) list_map_iterator_current_value(iterator);
  assert(key == keys[6]);
  assert(!strcmp(value, values[6]));

  assert(list_map_iterator_next(iterator));

  // Check after the step
  key = *(int*) list_map_iterator_current_key(iterator);
  value = (char*) list_map_iterator_current_value(iterator);
  assert(key == keys[5]);
  assert(!strcmp(value, values[5]));

  destroy_list_map_iterator(&iterator);
  destroy_list_map(&list);
}

//
// list_map_iterator_remove
//
void test_list_map_iterator_remove_on_empty_list()
{
  ListMap list = new_list_map(compare_int);
  ListMapIterator iterator = new_list_map_iterator(list);

  assert(!list_map_iterator_remove(iterator));

  destroy_list_map_iterator(&iterator);
  destroy_list_map(&list);
}

void test_list_map_iterator_remove_on_first()
{
  ListMap list = new_list_map(compare_int);
  int        size = 8;
  int      keys[] = {6, 7, 1, 2, 8, 4, 3, 5};
  char*  values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-"};
  for (int i=0; i < size; ++i) list_map_put(list, &(keys[i]), values[i]);
  ListMapIterator iterator = new_list_map_iterator(list);

  assert(!list_map_iterator_current_key(iterator));
  assert(!list_map_iterator_remove(iterator));

  destroy_list_map_iterator(&iterator);
  destroy_list_map(&list);
}

void test_list_map_iterator_remove_on_middle()
{
  ListMap list = new_list_map(compare_int);
  int        size = 8;
  int      keys[] = {6, 7, 1, 2, 8, 4, 3, 5};
  char*  values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-"};
  for (int i=0; i < size; ++i) list_map_put(list, &(keys[i]), values[i]);
  ListMapIterator iterator = new_list_map_iterator(list);

  // Check before remove
  for (int i = 0; i < 3; ++i) list_map_iterator_next(iterator);
  int key = *(int*) list_map_iterator_current_key(iterator);
  char* value = (char*) list_map_iterator_remove(iterator);
  assert(key == keys[6]);
  assert(!strcmp(value, values[6]));

  // Check after remove
  key = *(int*) list_map_iterator_current_key(iterator);
  value = (char*) list_map_iterator_current_value(iterator);
  assert(key == keys[5]);
  assert(!strcmp(value, values[5]));

  destroy_list_map_iterator(&iterator);
  destroy_list_map(&list);
}

void test_list_map_iterator_remove_on_last()
{
  ListMap list = new_list_map(compare_int);
  int        size = 8;
  int      keys[] = {6, 7, 1, 2, 8, 4, 3, 5};
  char*  values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-"};
  for (int i=0; i < size; ++i) list_map_put(list, &(keys[i]), values[i]);
  ListMapIterator iterator = new_list_map_iterator(list);

  for (int i = 0; i < size; ++i) list_map_iterator_next(iterator);
  int key = *(int*) list_map_iterator_current_key(iterator);
  char* value = (char*) list_map_iterator_remove(iterator);
  assert(key == keys[4]);
  assert(!strcmp(value, values[4]));

  destroy_list_map_iterator(&iterator);
  destroy_list_map(&list);
}

//
// list_map_iterator_reset
//
void test_list_map_iterator_reset_on_empty_list()
{
  ListMap list = new_list_map(compare_int);
  ListMapIterator iterator = new_list_map_iterator(list);

  list_map_iterator_reset(iterator); // @todo questo cosa testa?

  destroy_list_map_iterator(&iterator);
  destroy_list_map(&list);
}

void test_list_map_iterator_reset()
{
  ListMap list = new_list_map(compare_int);
  int        size = 8;
  int      keys[] = {6, 7, 1, 2, 8, 4, 3, 5};
  char*  values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-"};
  for (int i=0; i < size; ++i) list_map_put(list, &(keys[i]), values[i]);
  ListMapIterator iterator = new_list_map_iterator(list);

  // Check before reset
  for (int i = 0; i < 3; ++i) list_map_iterator_next(iterator);
  int key = *(int*) list_map_iterator_current_key(iterator);
  char* value = (char*) list_map_iterator_current_value(iterator);
  assert(key == keys[6]);
  assert(!strcmp(value, values[6]));

  list_map_iterator_reset(iterator);

  // Check after reset
  assert(!list_map_iterator_current_key(iterator));
  assert(!list_map_iterator_current_value(iterator));

  destroy_list_map_iterator(&iterator);
  destroy_list_map(&list);
}

//
// Main
//
int main(int argc, char  *argv[])
{
  start_tests("List Map Iterator");

  test(test_list_map_iterator_current_key_value_on_empty_list);
  test(test_list_map_iterator_current_key);
  test(test_list_map_iterator_current_value);
  //end_tests();

  //start_tests("list_map_iterator_has_next");
  test(test_list_map_iterator_has_next_on_empty_list);
  test(test_list_map_iterator_has_next_on_first);
  test(test_list_map_iterator_has_next_on_middle);
  test(test_list_map_iterator_has_next_on_last);
  //end_tests();

  //start_tests("list_map_iterator_next");
  test(test_list_map_iterator_next_on_empty_list);
  test(test_list_map_iterator_next_on_first);
  test(test_list_map_iterator_next_on_middle);
  test(test_list_map_iterator_next_on_last);
  //end_tests();

  //start_tests("list_map_iterator_remove");
  test(test_list_map_iterator_remove_on_empty_list);
  test(test_list_map_iterator_remove_on_first);
  test(test_list_map_iterator_remove_on_middle);
  test(test_list_map_iterator_remove_on_last);
  //end_tests();

  //start_tests("list_map_iterator_reset");
  test(test_list_map_iterator_reset_on_empty_list);
  test(test_list_map_iterator_reset);
  end_tests();

  return EXIT_SUCCESS;
}
