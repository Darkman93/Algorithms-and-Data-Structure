#include <assert.h>
#include "../../src/standard_libraries.h"
#include "../../include/test.h"
#include "../../include/utils.h"
#include "../../include/hash_table.h"
#include "../../src/hash_table/hash_table_debug.h"


void init_hash(HashTable htable, int keys[], char* values[], int size)
{
  for (int i=0; i < size; ++i)
  {
    hash_table_put(htable, &keys[i], values[i]);
    assert(hash_table_size(htable) == i+1);
  }
}


//
// hash_table_contains_key
//
void test_hash_table_contains_on_empty()
{
  int key = 1;
  HashTable htable = create_hash_table(compare_int, hash_int);
  assert(hash_table_is_empty(htable));
  assert(!hash_table_contains_key(htable, &key));
  destroy_hash_table(&htable);
}

void test_hash_table_contains_passing_null_key()
{
  HashTable htable = create_hash_table(compare_int, hash_int);
  assert(hash_table_is_empty(htable));
  int key = 50;
  assert(!hash_table_contains_key(htable, &key));
  destroy_hash_table(&htable);
}

void test_hash_table_contains_key()
{
  int       size = 8;
  int     keys[] = {6, 7, 1, 2, 8, 4, 3, 5, 2};
  char* values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-", "2-2"};

  HashTable htable = create_hash_table(compare_int, hash_int);
  init_hash(htable, keys, values, size);

  assert(hash_table_contains_key(htable, &keys[6]));
  destroy_hash_table(&htable);
}

void test_hash_table_not_contains_key()
{
  int       size = 8;
  int       key = 39;
  int     keys[] = {6, 7, 1, 2, 8, 4, 3, 5, 2};
  char* values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-", "2-2"};

  HashTable htable = create_hash_table(compare_int, hash_int);
  init_hash(htable, keys, values, size);

  assert(!hash_table_contains_key(htable, &key));
  destroy_hash_table(&htable);
}


//
// hash_table_is_empty
//
void test_hash_table_is_empty()
{
  HashTable htable = create_hash_table(compare_int, hash_int);
  assert(hash_table_is_empty(htable));
  destroy_hash_table(&htable);
}


//
// hash_table_get
//
void test_hash_table_get_empty()
{
  HashTable htable = create_hash_table(compare_int, hash_int);
  assert(hash_table_is_empty(htable));
  int key = 5;
  assert(!hash_table_get(htable, &key));
  destroy_hash_table(&htable);
}

void test_hash_table_get()
{
  int       size = 8;
  int     keys[] = {6, 7, 1, 2, 8, 4, 3, 5, 2};
  char* values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-", "2-2"};

  HashTable htable = create_hash_table(compare_int, hash_int);
  init_hash(htable, keys, values, size);

  for (int i=0; i < size; ++i)
  {
    char* result = (char*) hash_table_get(htable, &keys[i]);
    assert(!strcmp(result, values[i]));
  }

  destroy_hash_table(&htable);
}

//
// hash_table_put
//
void test_hash_table_put_on_empty_table()
{
  int     keys[] = {1};
  char* values[] = {"1-"};

  HashTable htable = create_hash_table(compare_int, hash_int);
  void* result = hash_table_put(htable, &keys[0], values[0]);

  assert(!result);
  assert(hash_table_size(htable) == 1);
  assert(hash_table_contains_key(htable, &(keys[0])));

  destroy_hash_table(&htable);
}

void test_hash_table_put_with_table_increasing_resize()
{
  int       size = 4;
  int     keys[] = {6, 7, 1, 2};
  char* values[] = {"six", "seven", "one", "two"};

  HashTable htable = create_hash_table_customized(2, 2, compare_int, hash_int);

  void* result;
  for (int i=0; i < 4; ++i)
  {
    result = hash_table_put(htable, &keys[i], values[i]);
    assert(!result);
    assert(hash_table_size(htable) == i+1);
  }

  for (int i=0; i < size; ++i)
    assert(hash_table_contains_key(htable, &keys[i]));


  int   key   = 3;
  char* value = "tree";
  result = hash_table_put(htable, &key, value);
  assert(!result);
  assert(hash_table_size(htable) == size + 1);
  assert(hash_table_get_capacity(htable) == 4);

  destroy_hash_table(&htable);
}

void test_hash_table_put_some_element_with_replace()
{
  int       size = 8;
  int     keys[] = {6, 7, 1, 2, 8, 4, 3, 5, 2};
  char* values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-", "2-2"};

  HashTable htable = create_hash_table(compare_int, hash_int);

  for (int i=0; i < size; ++i)
  {
    hash_table_put(htable, &keys[i], values[i]);
    assert(hash_table_size(htable) == i+1);
  }

  // replace "two" with "two-two"
  void* result = hash_table_put(htable, &keys[8], values[8]);
  assert(!strcmp(result, values[3]));

  for (int i=0; i < size; ++i)
    assert(hash_table_contains_key(htable, &keys[i]));

  destroy_hash_table(&htable);
}


//
// hash_table_remove
//
void test_hash_table_remove_on_empty_list()
{
  HashTable htable = create_hash_table(compare_int, hash_int);
  int key = 5;
  assert(!hash_table_remove(htable, &key));
  destroy_hash_table(&htable);
}

void test_hash_table_remove_with_table_decreasing_resize()
{
  int       size = 8;
  int     keys[] = {6, 7, 1, 2, 8, 4, 3, 5};
  char* values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-"};

  HashTable htable = create_hash_table_customized(2, 2, compare_int, hash_int);

  for (int i=0; i < size; ++i)
    hash_table_put(htable, &keys[i], values[i]);

  for (int i=size; i < 4; ++i)
  {
    char* result = (char*) hash_table_remove(htable, &keys[i]);
    assert(!strcmp(result, values[i]));
    assert(hash_table_size(htable) == size - (i+1));
  }

  destroy_hash_table(&htable);
}

void test_hash_table_remove_first()
{
  int       size = 8;
  int     keys[] = {6, 7, 1, 2, 8, 4, 3, 5};
  char* values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-"};

  HashTable htable = create_hash_table(compare_int, hash_int);
  init_hash(htable, keys, values, size);

  //HashTable htable = create_hash_table_customized(2, 2, compare_int, hash_int);

  //for (int i=0; i < size; ++i)
    //hash_table_put(htable, &keys[i], values[i]);

  char* result = (char*) hash_table_remove(htable, &keys[0]);

  //assert(!strcmp(result, (char*) hash_table_get(htable, &keys[0])));
  assert(!strcmp(result, values[0]));

  destroy_hash_table(&htable);
}


void test_hash_table_remove_middle()
{
  int       size = 8;
  int     keys[] = {6, 7, 1, 2, 8, 4, 3, 5};
  char* values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-"};

  HashTable htable = create_hash_table(compare_int, hash_int);
  init_hash(htable, keys, values, size);

  char* result = (char*) hash_table_remove(htable, &keys[3]);

  //assert(!strcmp(result, (char*) hash_table_get(htable, &keys[3])));
  assert(!strcmp(result, values[3]));

  destroy_hash_table(&htable);
}

void test_hash_table_remove_last()
{
  int       size = 8;
  int     keys[] = {6, 7, 1, 2, 8, 4, 3, 5};
  char* values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-"};

  HashTable htable = create_hash_table(compare_int, hash_int);
  init_hash(htable, keys, values, size);

  char* result = (char*) hash_table_remove(htable, &keys[7]);

  //assert(!strcmp(result, (char*) hash_table_get(htable, &keys[8])));
  assert(!strcmp(result, values[7]));

  destroy_hash_table(&htable);
}

//
// hash_table_size
//
void test_hash_table_size_on_empty_htable()
{
  HashTable htable = create_hash_table(compare_int, hash_int);
  assert(!hash_table_size(htable));
  assert(hash_table_size(htable) == hash_table_count(htable));
  destroy_hash_table(&htable);
}

void test_hash_table_size_on_htable_with_one_element()
{
  int     keys[] = {1};
  char* values[] = {"1-"};

  HashTable htable = create_hash_table(compare_int, hash_int);
  hash_table_put(htable, &keys[0], values[0]);

  assert(hash_table_size(htable) == 1);
  assert(hash_table_size(htable) == hash_table_count(htable));
  destroy_hash_table(&htable);
}

void test_hash_table_size_generic()
{
  int size = 8;
  int     keys[] = {6, 7, 1, 2, 8, 4, 3, 5};
  char* values[] = {"6-", "7-", "1-", "2-", "8-", "4-", "3-", "5-"};

  HashTable htable = create_hash_table(compare_int, hash_int);
  init_hash(htable, keys, values, size);

  assert(hash_table_size(htable) == size);
  assert(hash_table_size(htable) == hash_table_count(htable));
  destroy_hash_table(&htable);
}


//
// Main
//
int main(int argc, char  *argv[])
{
  start_tests("Hash Table");

  test(test_hash_table_contains_on_empty);
  test(test_hash_table_contains_passing_null_key);
  test(test_hash_table_contains_key);
  test(test_hash_table_not_contains_key);
  //end_tests();

  //start_tests("hash_table_get");
  test(test_hash_table_get_empty);
  test(test_hash_table_get);
  //end_tests();

  //start_tests("hash_table_is_empty");
  test(test_hash_table_is_empty);
  //end_tests();

  //start_tests("hash_table_put");
  test(test_hash_table_put_on_empty_table);
  test(test_hash_table_put_with_table_increasing_resize);
  test(test_hash_table_put_some_element_with_replace);
  //end_tests();

  //start_tests("hash_table_remove");
  test(test_hash_table_remove_on_empty_list);
  test(test_hash_table_remove_with_table_decreasing_resize);
  test(test_hash_table_remove_first);
  test(test_hash_table_remove_middle);
  test(test_hash_table_remove_last);
  //end_tests();

  //start_tests("hash_table_size");
  test(test_hash_table_size_on_empty_htable);
  test(test_hash_table_size_on_htable_with_one_element);
  test(test_hash_table_size_generic);
  end_tests();

  return EXIT_SUCCESS;
}
