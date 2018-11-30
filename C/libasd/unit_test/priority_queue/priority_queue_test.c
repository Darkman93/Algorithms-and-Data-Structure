#include <assert.h>
#include "../../src/standard_libraries.h"
#include "../../include/test.h"
#include "../../include/utils.h"
#include "../../src/priority_queue/priority_queue.h"
#include "../../src/priority_queue/priority_queue_factory.h"
#include "../../src/priority_queue/priority_queue_debug.h"

//
// priority_queue_change_priority
//

void test_priority_queue_change_priority_of_first_element()
{
  int   size         = 8;
  char* values[]     = {"nine", "six", "five", "four", "two", "seven", "eight", "one"};
  int   priorities[] = {9, 6, 5, 4, 2, 7, 8, 1};
  PriorityQueue queue = create_priority_queue(compare_string, compare_int);

  for (int i=0; i < size ;++i)
    priority_queue_offer(queue, values[i], &priorities[i]);

  void* first = priority_queue_peek(queue);
  assert(!compare_string(first, "one"));

  int priority = 10;

  assert(priority_queue_change_priority(queue, "one", &priority));
  assert(priority_queue_size(queue) == size);

  first = priority_queue_peek(queue);
  assert(!compare_string(first, "two"));

  assert(priority_queue_contains(queue, "one"));

  destroy_priority_queue(&queue);
}


//
// priority_queue_offer
//
void test_priority_queue_offer_one_element()
{
  char* values[]     = {"nine", "six", "five", "four", "two", "seven", "eight", "one"};
  int   priorities[] = {9, 6, 5, 4, 2, 7, 8, 1};
  PriorityQueue queue = create_priority_queue(compare_string, compare_int);
  assert(priority_queue_offer(queue, values[0], &priorities[0]));

  size_t size = priority_queue_size(queue);
  assert(size == 1);

  destroy_priority_queue(&queue);
}

void test_priority_queue_offer_some_element()
{
  int   size         = 8;
  char* values[]     = {"nine", "six", "five", "four", "two", "seven", "eight", "one"};
  int   priorities[] = {9, 6, 5, 4, 2, 7, 8, 1};
  PriorityQueue queue = create_priority_queue(compare_string, compare_int);

  for (int i=0; i < size ;++i)
  {
    assert(priority_queue_offer(queue, values[i], &priorities[i]));
    assert(priority_queue_size(queue) == i+1);
  }

  destroy_priority_queue(&queue);
}

void test_priority_queue_offer_with_increase_size()
{
  int   size         = 8;
  char* values[]     = {"nine", "six", "five", "four", "two", "seven", "eight", "one"};
  int   priorities[] = {9, 6, 5, 4, 2, 7, 8, 1};
  PriorityQueue queue = create_priority_queue(compare_string, compare_int);

  for (int i=0; i < size ;++i)
  {
    assert(priority_queue_offer(queue, values[i], &priorities[i]));
    assert(priority_queue_size(queue) == i+1);
  }

  for (int i=0; i < size ;++i)
    assert(priority_queue_contains(queue, values[i]));

  char* value    = "tree";
  int   priority = 3;
  assert(priority_queue_offer(queue, value, &priority));
  assert(priority_queue_size(queue) == 9);
  assert(priority_queue_get_capacity(queue) == 16);

  assert(priority_queue_contains(queue, value));

  destroy_priority_queue(&queue);
}


//
// priority_queue_peek
//

void test_priority_queue_peek_on_first()
{
  char* values[]     = {"nine", "six", "five", "four", "two", "seven", "eight", "one"};
  int   priorities[] = {9, 6, 5, 4, 2, 7, 8, 1};
  PriorityQueue queue = create_priority_queue(compare_string, compare_int);
  assert(priority_queue_offer(queue, values[0], &priorities[0]));

  size_t size = priority_queue_size(queue);
  assert(size == 1);

  void* first = priority_queue_peek(queue);
  assert(!compare_string(first, values[0]));

  destroy_priority_queue(&queue);
}

void test_priority_queue_peek_sparse_number()
{
  int   size         = 8;
  char* values[]     = {"nine", "six", "five", "four", "two", "seven", "eight", "one"};
  int   priorities[] = {9, 6, 5, 4, 2, 7, 8, 1};
  PriorityQueue queue = create_priority_queue(compare_string, compare_int);

  for (int i=0; i < size ;++i)
  {
    assert(priority_queue_offer(queue, values[i], &priorities[i]));
    assert(priority_queue_size(queue) == i+1);
  }

  void* element = priority_queue_peek(queue);
  assert(!compare_string(element, values[7]));

  for (int i=0; i < size ;++i)
    assert(priority_queue_contains(queue, values[i]));

  destroy_priority_queue(&queue);
}

void test_priority_queue_peek_equals_elements()
{
  int   size         = 8;
  char* values[]     = {"nine", "six", "five", "four", "two", "seven", "one", "one"};
  int   priorities[] = {9, 6, 5, 4, 2, 7, 1, 1};
  PriorityQueue queue = create_priority_queue(compare_string, compare_int);

  for (int i=0; i < size ;++i)
  {
    assert(priority_queue_offer(queue, values[i], &priorities[i]));
    assert(priority_queue_size(queue) == i+1);
  }

  void* element = priority_queue_peek(queue);
  assert(!compare_string(element, values[6]));

  for (int i=0; i < size ;++i)
    assert(priority_queue_contains(queue, values[i]));

  destroy_priority_queue(&queue);
}




//
// priority_queue_poll
//

void test_priority_queue_poll_on_first()
{
  int   size         = 9;
  char* values[]     = {"nine", "six", "five", "four", "two", "seven", "eight", "one", "tree"};
  int   priorities[] = {9, 6, 5, 4, 2, 7, 8, 1, 3};
  PriorityQueue queue = create_priority_queue(compare_string, compare_int);

  for (int i=0; i < size ;++i)
    assert(priority_queue_offer(queue, values[i], &priorities[i]));

  assert(!strcmp("one",  (char*) priority_queue_poll(queue)));

  destroy_priority_queue(&queue);
}


void test_priority_queue_offer_poll_decrease_size()
{
  int   size         = 9;
  char* values[]     = {"nine", "six", "five", "four", "two", "seven", "eight", "one", "tree"};
  int   priorities[] = {9, 6, 5, 4, 2, 7, 8, 1, 3};
  PriorityQueue queue = create_priority_queue(compare_string, compare_int);

  for (int i=0; i < size ;++i)
    assert(priority_queue_offer(queue, values[i], &priorities[i]));

  assert(!strcmp("one",  (char*) priority_queue_poll(queue)));
  assert(!strcmp("two",  (char*) priority_queue_poll(queue)));
  assert(!strcmp("tree", (char*) priority_queue_poll(queue)));
  assert(!strcmp("four", (char*) priority_queue_poll(queue)));
  assert(!strcmp("five", (char*) priority_queue_poll(queue)));

  assert(priority_queue_get_capacity(queue) == 8);

  destroy_priority_queue(&queue);
}


//
// priority_queue_remove
//

void test_priority_queue_remove_head()
{
  int   size         = 9;
  char* values[]     = {"nine", "six", "five", "four", "two", "seven", "eight", "one", "tree"};
  int   priorities[] = {9, 6, 5, 4, 2, 7, 8, 1, 3};
  PriorityQueue queue = create_priority_queue(compare_string, compare_int);

  for (int i=0; i < size ;++i)
    assert(priority_queue_offer(queue, values[i], &priorities[i]));

  assert(!strcmp("one",  (char*) priority_queue_remove(queue, values[7])));

  destroy_priority_queue(&queue);
}


void test_priority_queue_remove_generic()
{
  int   size         = 9;
  char* values[]     = {"nine", "six", "five", "four", "two", "seven", "eight", "one", "tree"};
  int   priorities[] = {9, 6, 5, 4, 2, 7, 8, 1, 3};
  PriorityQueue queue = create_priority_queue(compare_string, compare_int);

  for (int i=0; i < size ;++i)
    assert(priority_queue_offer(queue, values[i], &priorities[i]));

  assert(!strcmp("one",  (char*) priority_queue_remove(queue, values[7])));
  assert(!strcmp("two",  (char*) priority_queue_remove(queue, values[4])));
  assert(!strcmp("tree",  (char*) priority_queue_remove(queue, values[8])));
  assert(!strcmp("four",  (char*) priority_queue_remove(queue, values[3])));

  destroy_priority_queue(&queue);
}


void test_priority_queue_remove_tail()
{
  int   size         = 9;
  char* values[]     = {"nine", "six", "five", "four", "two", "seven", "eight", "one", "tree"};
  int   priorities[] = {9, 6, 5, 4, 2, 7, 8, 1, 3};
  PriorityQueue queue = create_priority_queue(compare_string, compare_int);

  for (int i=0; i < size ;++i)
    assert(priority_queue_offer(queue, values[i], &priorities[i]));

  assert(!strcmp("nine",  (char*) priority_queue_remove(queue, values[0])));

  destroy_priority_queue(&queue);
}


//
// Main
//
int main(int argc, char  *argv[])
{
  start_tests("priority Queue");

  test(test_priority_queue_change_priority_of_first_element);

  test(test_priority_queue_offer_one_element);
  test(test_priority_queue_offer_some_element);
  test(test_priority_queue_offer_with_increase_size);

  test(test_priority_queue_peek_on_first);
  test(test_priority_queue_peek_sparse_number);
  test(test_priority_queue_peek_equals_elements);

  test(test_priority_queue_poll_on_first);
  test(test_priority_queue_offer_poll_decrease_size);

  test(test_priority_queue_remove_head);
  test(test_priority_queue_remove_generic);
  test(test_priority_queue_remove_tail);

  end_tests();

  return EXIT_SUCCESS;
}
