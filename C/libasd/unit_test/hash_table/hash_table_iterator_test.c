#include <assert.h>
#include "../../src/standard_libraries.h"
#include "../../include/test.h"
#include "../../include/utils.h"
#include "../../include/hash_table.h"

//
// Has Next
//
void test_hash_table_iterator_has_next_on_empty()
{
  HashTable htable = new_hash_table(4, 2.0f, compare_int, hash_int);
  HashTableIterator iterator = new_hash_table_iterator(htable);

  assert(!hash_table_iterator_has_next(iterator));

  destroy_hash_table_iterator(&iterator);
  destroy_hash_table(&htable);
}

void test_hash_table_iterator_has_next_on_first()
{
  HashTable htable = new_hash_table(4, 2.0f, compare_int, hash_int);
  HashTableIterator iterator = new_hash_table_iterator(htable);
  int size = 5;
  int keys[] = {0, 2, 3, 4, 7};
  char* values[] = {"0", "2", "3", "4", "7"};
  for(int i = 0; i < size; ++i) hash_table_put(htable, &keys[i], values[i]);

  assert(!hash_table_iterator_current_key(iterator));
  assert(hash_table_iterator_has_next(iterator));

  destroy_hash_table_iterator(&iterator);
  destroy_hash_table(&htable);
}

void test_hash_table_iterator_has_next_on_middle_internal()
{
  HashTable htable = new_hash_table(4, 2.0f, compare_int, hash_int);
  HashTableIterator iterator = new_hash_table_iterator(htable);
  int size = 5;
  int keys[] = {0, 2, 3, 4, 7};
  char* values[] = {"0", "2", "3", "4", "7"};
  for(int i = 0; i < size; ++i) hash_table_put(htable, &keys[i], values[i]);

  hash_table_iterator_next(iterator);
  int key = *(int*) hash_table_iterator_current_key(iterator);
  assert(key == keys[0]);
  assert(hash_table_iterator_has_next(iterator));

  destroy_hash_table_iterator(&iterator);
  destroy_hash_table(&htable);
}

void test_hash_table_iterator_has_next_on_middle_edge_with_gap()
{
  HashTable htable = new_hash_table(4, 2.0f, compare_int, hash_int);
  HashTableIterator iterator = new_hash_table_iterator(htable);
  int size = 5;
  int keys[] = {0, 2, 3, 4, 7};
  char* values[] = {"0", "2", "3", "4", "7"};
  for(int i = 0; i < size; ++i) hash_table_put(htable, &keys[i], values[i]);

  hash_table_iterator_next(iterator);
  hash_table_iterator_next(iterator);
  int key = *(int*) hash_table_iterator_current_key(iterator);
  assert(key == keys[3]);
  assert(hash_table_iterator_has_next(iterator));

  destroy_hash_table_iterator(&iterator);
  destroy_hash_table(&htable);
}

void test_hash_table_iterator_has_next_on_middle_edge_without_gap()
{
  HashTable htable = new_hash_table(4, 2.0f, compare_int, hash_int);
  HashTableIterator iterator = new_hash_table_iterator(htable);
  int size = 5;
  int keys[] = {0, 2, 3, 4, 7};
  char* values[] = {"0", "2", "3", "4", "7"};
  for(int i = 0; i < size; ++i) hash_table_put(htable, &keys[i], values[i]);

  hash_table_iterator_next(iterator);
  hash_table_iterator_next(iterator);
  hash_table_iterator_next(iterator);
  int key = *(int*) hash_table_iterator_current_key(iterator);
  assert(key == keys[1]);
  assert(hash_table_iterator_has_next(iterator));

  destroy_hash_table_iterator(&iterator);
  destroy_hash_table(&htable);
}

void test_hash_table_iterator_has_next_on_last()
{
  HashTable htable = new_hash_table(4, 2.0f, compare_int, hash_int);
  HashTableIterator iterator = new_hash_table_iterator(htable);
  int size = 5;
  int keys[] = {0, 2, 3, 4, 7};
  char* values[] = {"0", "2", "3", "4", "7"};
  for(int i = 0; i < size; ++i) hash_table_put(htable, &keys[i], values[i]);

  for(int i = 0; i < 5; ++i) hash_table_iterator_next(iterator);
  int key = *(int*) hash_table_iterator_current_key(iterator);
  assert(key == keys[4]);
  assert(!hash_table_iterator_has_next(iterator));

  destroy_hash_table_iterator(&iterator);
  destroy_hash_table(&htable);
}

//
// Next
//
void test_hash_table_iterator_next_on_empty()
{
  HashTable htable = new_hash_table(4, 2.0f, compare_int, hash_int);
  HashTableIterator iterator = new_hash_table_iterator(htable);

  assert(!hash_table_iterator_next(iterator));

  destroy_hash_table_iterator(&iterator);
  destroy_hash_table(&htable);
}

void test_hash_table_iterator_next_on_first()
{
  HashTable htable = new_hash_table(4, 2.0f, compare_int, hash_int);
  HashTableIterator iterator = new_hash_table_iterator(htable);
  int size = 5;
  int keys[] = {0, 2, 3, 4, 7};
  char* values[] = {"0", "2", "3", "4", "7"};
  for(int i = 0; i < size; ++i) hash_table_put(htable, &keys[i], values[i]);

  assert(!hash_table_iterator_current_key(iterator));
  assert(hash_table_iterator_next(iterator));
  int key = *(int*) hash_table_iterator_current_key(iterator);
  assert(key == keys[0]);

  destroy_hash_table_iterator(&iterator);
  destroy_hash_table(&htable);
}

void test_hash_table_iterator_next_on_middle_internal()
{
  HashTable htable = new_hash_table(4, 2.0f, compare_int, hash_int);
  HashTableIterator iterator = new_hash_table_iterator(htable);
  int size = 5;
  int keys[] = {0, 2, 3, 4, 7};
  char* values[] = {"0", "2", "3", "4", "7"};
  for(int i = 0; i < size; ++i) hash_table_put(htable, &keys[i], values[i]);

  hash_table_iterator_next(iterator);
  int key = *(int*) hash_table_iterator_current_key(iterator);
  assert(key == keys[0]);
  assert(hash_table_iterator_next(iterator));
  key = *(int*) hash_table_iterator_current_key(iterator);
  assert(key == keys[3]);

  destroy_hash_table_iterator(&iterator);
  destroy_hash_table(&htable);
}

void test_hash_table_iterator_next_on_middle_edge_with_gap()
{
  HashTable htable = new_hash_table(4, 2.0f, compare_int, hash_int);
  HashTableIterator iterator = new_hash_table_iterator(htable);
  int size = 5;
  int keys[] = {0, 2, 3, 4, 7};
  char* values[] = {"0", "2", "3", "4", "7"};
  for(int i = 0; i < size; ++i) hash_table_put(htable, &keys[i], values[i]);

  hash_table_iterator_next(iterator);
  hash_table_iterator_next(iterator);
  int key = *(int*) hash_table_iterator_current_key(iterator);
  assert(key == keys[3]);
  assert(hash_table_iterator_next(iterator));
  key = *(int*) hash_table_iterator_current_key(iterator);
  assert(key == keys[1]);

  destroy_hash_table_iterator(&iterator);
  destroy_hash_table(&htable);
}

void test_hash_table_iterator_next_on_middle_edge_without_gap()
{
  HashTable htable = new_hash_table(4, 2.0f, compare_int, hash_int);
  HashTableIterator iterator = new_hash_table_iterator(htable);
  int size = 5;
  int keys[] = {0, 2, 3, 4, 7};
  char* values[] = {"0", "2", "3", "4", "7"};
  for(int i = 0; i < size; ++i) hash_table_put(htable, &keys[i], values[i]);

  hash_table_iterator_next(iterator);
  hash_table_iterator_next(iterator);
  hash_table_iterator_next(iterator);
  int key = *(int*) hash_table_iterator_current_key(iterator);
  assert(key == keys[1]);
  assert(hash_table_iterator_next(iterator));
  key = *(int*) hash_table_iterator_current_key(iterator);
  assert(key == keys[2]);

  destroy_hash_table_iterator(&iterator);
  destroy_hash_table(&htable);
}

void test_hash_table_iterator_next_on_last()
{
  HashTable htable = new_hash_table(4, 2.0f, compare_int, hash_int);
  HashTableIterator iterator = new_hash_table_iterator(htable);
  int size = 5;
  int keys[] = {0, 2, 3, 4, 7};
  char* values[] = {"0", "2", "3", "4", "7"};
  for(int i = 0; i < size; ++i) hash_table_put(htable, &keys[i], values[i]);

  for(int i = 0; i < 5; ++i) hash_table_iterator_next(iterator);
  int key = *(int*) hash_table_iterator_current_key(iterator);
  assert(key == keys[4]);
  assert(!hash_table_iterator_next(iterator));
  key = *(int*) hash_table_iterator_current_key(iterator);
  assert(key == keys[4]);

  destroy_hash_table_iterator(&iterator);
  destroy_hash_table(&htable);
}

//
// Gets
//

void test_hash_table_iterator_get_current_key_on_empty()
{
  HashTable htable = new_hash_table(4, 2.0f, compare_int, hash_int);
  HashTableIterator iterator = new_hash_table_iterator(htable);

  assert(!hash_table_iterator_current_key(iterator));

  destroy_hash_table_iterator(&iterator);
  destroy_hash_table(&htable);
}

void test_hash_table_iterator_get_current_key()
{
  HashTable htable = new_hash_table(4, 2.0f, compare_int, hash_int);
  HashTableIterator iterator = new_hash_table_iterator(htable);
  int size = 5;
  int keys[] = {0, 2, 3, 4, 7};
  char* values[] = {"0", "2", "3", "4", "7"};
  for(int i = 0; i < size; ++i) hash_table_put(htable, &keys[i], values[i]);

  hash_table_iterator_next(iterator);
  hash_table_iterator_next(iterator);

  int key = *(int*) hash_table_iterator_current_key(iterator);
  assert(key == keys[3]);

  destroy_hash_table_iterator(&iterator);
  destroy_hash_table(&htable);
}

void test_hash_table_iterator_get_current_value_on_empty()
{
  HashTable htable = new_hash_table(4, 2.0f, compare_int, hash_int);
  HashTableIterator iterator = new_hash_table_iterator(htable);

  assert(!hash_table_iterator_current_value(iterator));

  destroy_hash_table_iterator(&iterator);
  destroy_hash_table(&htable);
}

void test_hash_table_iterator_get_current_value()
{
  HashTable htable = new_hash_table(4, 2.0f, compare_int, hash_int);
  HashTableIterator iterator = new_hash_table_iterator(htable);
  int size = 5;
  int keys[] = {0, 2, 3, 4, 7};
  char* values[] = {"0", "2", "3", "4", "7"};
  for(int i = 0; i < size; ++i) hash_table_put(htable, &keys[i], values[i]);

  hash_table_iterator_next(iterator);
  hash_table_iterator_next(iterator);

  char* value = (char*) hash_table_iterator_current_value(iterator);
  assert(!strcmp(value, values[3]));

  destroy_hash_table_iterator(&iterator);
  destroy_hash_table(&htable);
}

void test_hash_table_iterator_reset_on_empty()
{
  HashTable htable = new_hash_table(4, 2.0f, compare_int, hash_int);
  HashTableIterator iterator = new_hash_table_iterator(htable);


  assert(!hash_table_iterator_current_key(iterator));
  hash_table_iterator_reset(iterator);
  assert(!hash_table_iterator_current_key(iterator));

  destroy_hash_table_iterator(&iterator);
  destroy_hash_table(&htable);
}

void test_hash_table_iterator_reset()
{
  HashTable htable = new_hash_table(4, 2.0f, compare_int, hash_int);
  HashTableIterator iterator = new_hash_table_iterator(htable);
  int size = 5;
  int keys[] = {0, 2, 3, 4, 7};
  char* values[] = {"0", "2", "3", "4", "7"};
  for(int i = 0; i < size; ++i) hash_table_put(htable, &keys[i], values[i]);

  hash_table_iterator_next(iterator);
  hash_table_iterator_next(iterator);
  int key = *(int*) hash_table_iterator_current_key(iterator);
  assert(key == keys[3]);
  hash_table_iterator_reset(iterator);
  assert(!hash_table_iterator_current_key(iterator));
  hash_table_iterator_next(iterator);
  hash_table_iterator_next(iterator);
  key = *(int*) hash_table_iterator_current_key(iterator);
  assert(key == keys[3]);

  destroy_hash_table_iterator(&iterator);
  destroy_hash_table(&htable);
}

int main()
{
  start_tests("Hash Table Iterator");

  test(test_hash_table_iterator_has_next_on_empty);
  test(test_hash_table_iterator_has_next_on_first);
  test(test_hash_table_iterator_has_next_on_middle_internal);
  test(test_hash_table_iterator_has_next_on_middle_edge_with_gap);
  test(test_hash_table_iterator_has_next_on_middle_edge_without_gap);
  test(test_hash_table_iterator_has_next_on_last);
  test(test_hash_table_iterator_next_on_empty);
  test(test_hash_table_iterator_next_on_first);
  test(test_hash_table_iterator_next_on_middle_internal);
  test(test_hash_table_iterator_next_on_middle_edge_with_gap);
  test(test_hash_table_iterator_next_on_middle_edge_without_gap);
  test(test_hash_table_iterator_next_on_last);
  test(test_hash_table_iterator_get_current_key_on_empty);
  test(test_hash_table_iterator_get_current_key);
  test(test_hash_table_iterator_get_current_value_on_empty);
  test(test_hash_table_iterator_get_current_value);
  test(test_hash_table_iterator_reset_on_empty);
  test(test_hash_table_iterator_reset);
  end_tests();
}
