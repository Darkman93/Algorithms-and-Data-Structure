#include <assert.h>
#include "../../src/standard_libraries.h"
#include "../../src/test/test.h"
#include "../../include/utils.h"
#include "../../src/binary_tree/binary_tree.h"
#include "../../src/binary_tree/binary_tree_debug.h"

BinaryTree init_tree(BinaryTree tree, int keys[], char* values[], int size)
{
  for (int i=0; i < size; ++i)
  {
    binary_tree_put(tree, &(keys[i]), values[i]);
    assert(binary_tree_size(tree) == i+1);
  }
  return tree;
}


//
// binary_tree_contains_key
//


//
// binary_tree_get
//

void test_binary_contains_key_on_empty_tree()
{
  BinaryTree tree = new_binary_tree(compare_int);
  int data = 45;

  assert(!binary_tree_contains_key(tree, &data));
}

void test_binary_contains_key_one_element()
{
  BinaryTree tree = new_binary_tree(compare_int);
  int     keys[] = {1};
  char* values[] = {"one"};

  void* result = binary_tree_put(tree, &(keys[0]), values[0]);

  assert(!result);
  assert(binary_tree_contains_key(tree, &(keys[0])));
}


void test_binary_contains_key_root()
{
  BinaryTree tree = new_binary_tree(compare_int);
  int size = 8;
  int     keys[] = {6, 7, 1, 2, 8, 4, 3, 5, 9};
  char* values[] = {"six", "seven", "one", "two", "eight", "four", "three", "five", "nine"};

  tree = init_tree(tree, keys, values, size);

  assert(binary_tree_contains_key(tree, &(keys[0])));
}


void test_binary_contains_key_generic()
{
  BinaryTree tree = new_binary_tree(compare_int);
  int size = 8;
  int     keys[] = {6, 7, 1, 2, 8, 4, 3, 5, 9};
  char* values[] = {"six", "seven", "one", "two", "eight", "four", "three", "five", "nine"};

  tree = init_tree(tree, keys, values, size);

  assert(binary_tree_contains_key(tree, &(keys[6])));
}


void test_binary_contains_key_not_contain()
{
  BinaryTree tree = new_binary_tree(compare_int);
  int size = 8;
  int     keys[] = {6, 7, 1, 2, 8, 4, 3, 5, 9};
  char* values[] = {"six", "seven", "one", "two", "eight", "four", "three", "five", "nine"};
  int data = 40;

  tree = init_tree(tree, keys, values, size);

  assert(!binary_tree_contains_key(tree, &data));
}


//
// binary_tree_put
//

void test_binary_tree_put_root()
{
  BinaryTree tree = new_binary_tree(compare_int);
  int     keys[] = {1};
  char* values[] = {"one"};

  void* result = binary_tree_put(tree, &(keys[0]), values[0]);

  assert(!result);
  assert(binary_tree_size(tree) == 1);
  assert(binary_tree_contains_key(tree, &(keys[0])));
}

void test_binary_tree_put_with_replace_root()
{
  BinaryTree tree = new_binary_tree(compare_int);
  int     keys[] = {1};
  char* values[] = {"one", "one-one"};

  binary_tree_put(tree, &(keys[0]), values[0]);
  char* result = (char*) binary_tree_put(tree, &(keys[0]), values[1]);

  assert(!strcmp(result, values[0]));
  assert(binary_tree_size(tree) == 1);
  assert(binary_tree_contains_key(tree, &(keys[0])));
}

void test_binary_tree_put_some_element()
{
  BinaryTree tree = new_binary_tree(compare_int);
  int       size = 8;
  int     keys[] = {6, 7, 1, 2, 8, 4, 3, 5};
  char* values[] = {"six", "seven", "one", "two", "eight", "four", "three", "five"};

  void* result;
  for (int i=0; i < size; ++i)
  {
    result = binary_tree_put(tree, &(keys[i]), values[i]);
    assert(!result);
    assert(binary_tree_size(tree) == i+1);
  }

  for (int i=0; i < size; ++i)
  {
    assert(binary_tree_contains_key(tree, &(keys[i])));
  }
}

void test_binary_tree_put_some_element_with_replace()
{
  BinaryTree tree = new_binary_tree(compare_int);
  int       size = 8;
  int     keys[] = {6, 7, 1, 2, 8, 4, 3, 5, 2};
  char* values[] = {"six", "seven", "one", "two", "eight", "four", "three", "five", "two-two"};

  tree = init_tree(tree, keys, values, size);

  // replace "two" with "two-two"
  void* result = binary_tree_put(tree, &(keys[8]), values[8]);
  assert(!strcmp(result, values[3]));

  for (int i=0; i < size; ++i)
  {
    assert(binary_tree_contains_key(tree, &(keys[i])));
  }
}


//
// binary_tree_remove
//

void test_binary_tree_remove_root_on_single_tree_element()
{
  BinaryTree tree = new_binary_tree(compare_int);
  int     keys[] = {1};
  char* values[] = {"one"};
  binary_tree_put(tree, &(keys[0]), values[0]);

  char* result = (char*) binary_tree_remove(tree, &(keys[0]));

  assert(!strcmp(result, values[0]));
  assert(!binary_tree_size(tree));
  assert(!binary_tree_contains_key(tree, &(keys[0])));
}


void test_binary_remove_root()
{
  BinaryTree tree = new_binary_tree(compare_int);
  int size = 9;
  int     keys[] = {6, 7, 1, 2, 8, 4, 3, 5, 9};
  char* values[] = {"six", "seven", "one", "two", "eight", "four", "three", "five", "nine"};

  tree = init_tree(tree, keys, values, size);

  char* result = (char*) binary_tree_remove(tree, &(keys[0]));

  assert(!strcmp(result, values[0]));
  assert(binary_tree_size(tree) == binary_tree_count(tree));
  assert(!binary_tree_contains_key(tree, &(keys[0])));
  assert(is_binary_tree(tree));
}


void test_binary_remove_leaf()
{
  BinaryTree tree = new_binary_tree(compare_int);
  int size = 8;
  int     keys[] = {6, 7, 1, 2, 8, 4, 3, 5, 9};
  char* values[] = {"six", "seven", "one", "two", "eight", "four", "three", "five", "nine"};

  tree = init_tree(tree, keys, values, size);

  char* result = (char*) binary_tree_remove(tree, &(keys[4]));

  assert(!strcmp(result, values[4]));
  assert(binary_tree_size(tree) == binary_tree_count(tree));
  assert(!binary_tree_contains_key(tree, &(keys[4])));
  assert(is_binary_tree(tree));
}

void test_binary_remove_generic()
{
  BinaryTree tree = new_binary_tree(compare_int);
  int size = 8;
  int     keys[] = {6, 7, 1, 2, 8, 4, 3, 5, 9};
  char* values[] = {"six", "seven", "one", "two", "eight", "four", "three", "five", "nine"};

  tree = init_tree(tree, keys, values, size);

  char* result = (char*) binary_tree_remove(tree, &(keys[6]));

  assert(!strcmp(result, values[6]));
  assert(binary_tree_size(tree) == binary_tree_count(tree));
  assert(!binary_tree_contains_key(tree, &(keys[6])));
  assert(is_binary_tree(tree));
}

void test_binary_remove_not_contain()
{
  BinaryTree tree = new_binary_tree(compare_int);
  int size = 8;
  int     keys[] = {6, 7, 1, 2, 8, 4, 3, 5, 9};
  char* values[] = {"six", "seven", "one", "two", "eight", "four", "three", "five", "nine"};
  int element = 10;

  tree = init_tree(tree, keys, values, size);

  char* result = (char*) binary_tree_remove(tree, &(element));

  assert(!result);
  assert(binary_tree_size(tree) == binary_tree_count(tree));
  assert(!binary_tree_contains_key(tree, &(element)));
  assert(is_binary_tree(tree));
}


//
// binary_tree_size
//
void test_binary_tree_size_on_empty_tree()
{
  BinaryTree tree = new_binary_tree(compare_int);
  assert(!binary_tree_size(tree));
  assert(binary_tree_size(tree) == binary_tree_count(tree));
}

void test_binary_tree_size_on_tree_with_one_element()
{
  BinaryTree tree = new_binary_tree(compare_int);
  int     keys[] = {1};
  char* values[] = {"one"};
  binary_tree_put(tree, &(keys[0]), &(values[0]));

  assert(binary_tree_size(tree) == 1);
  assert(binary_tree_size(tree) == binary_tree_count(tree));
}


void test_binary_tree_size_generic()
{
  BinaryTree tree = new_binary_tree(compare_int);
  int size = 8;
  int     keys[] = {6, 7, 1, 2, 8, 4, 3, 5, 9};
  char* values[] = {"six", "seven", "one", "two", "eight", "four", "three", "five", "nine"};

  tree = init_tree(tree, keys, values, size);

  assert(binary_tree_size(tree) == size);
  assert(binary_tree_size(tree) == binary_tree_count(tree));
}


//
// Main
//
int main(int argc, char  *argv[])
{
  start_tests("Binary Tree");

  test(test_binary_contains_key_on_empty_tree);
  test(test_binary_contains_key_one_element);
  test(test_binary_contains_key_root);
  test(test_binary_contains_key_generic);
  test(test_binary_contains_key_not_contain);


  start_tests("binary_tree_put");
  test(test_binary_tree_put_root);
  test(test_binary_tree_put_with_replace_root);
  test(test_binary_tree_put_some_element);
  test(test_binary_tree_put_some_element_with_replace);

  test(test_binary_tree_remove_root_on_single_tree_element);
  test(test_binary_remove_root);
  test(test_binary_remove_leaf);
  test(test_binary_remove_generic);
  test(test_binary_remove_not_contain);

  test(test_binary_tree_size_on_empty_tree);
  test(test_binary_tree_size_on_tree_with_one_element);
  test(test_binary_tree_size_generic);

  end_tests();

  return EXIT_SUCCESS;
}
