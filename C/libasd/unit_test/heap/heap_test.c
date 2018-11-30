#include <assert.h>
#include "../../src/standard_libraries.h"
#include "../../include/test.h"
#include "../../include/utils.h"
#include "../../include/heap.h"

//
// TESTS
//

void test_heap_contains_on_empty_heap()
{
  int array[] = {9, 6, 5, 5, 6, 7, 8};
  Heap heap = new_heap(compare_int);
  assert(!heap_contains(heap, &array[0]));
  destroy_heap(heap);
}

void test_heap_contains_on_heap_with_one_element()
{
  int array[] = {9, 6, 5, 5, 6, 7, 8};
  Heap heap = new_heap(compare_int);
  assert(heap_offer(heap, &array[0]));
  assert(heap_contains(heap, &array[0]));
  destroy_heap(heap);
}

void test_heap_contains_on_heap_with_some_elements()
{
  int array[] = {9, 6, 5, 5, 6, 7, 8};
  Heap heap = new_heap(compare_int);
  assert(heap_offer(heap, &array[0]));
  assert(heap_offer(heap, &array[1]));
  assert(heap_offer(heap, &array[2]));
  assert(heap_contains(heap, &array[0]));
  assert(heap_contains(heap, &array[1]));
  assert(heap_contains(heap, &array[2]));
  destroy_heap(heap);
}


void test_heap_offer_on_empty_heap()
{
  int array[] = {9, 6, 5, 5, 6, 7, 8};
  Heap heap = new_heap(compare_int);
  assert(heap_offer(heap, &(array[0])));

  size_t size = heap_size(heap);
  assert(size == 1);

  void* first = heap_peek(heap);
  assert(!compare_int(first, &array[0]));

  destroy_heap(heap);
}

void test_heap_offer_some_element()
{
  int size = 10;
  int array[] = {9, 6, 5, 5, 6, 7, 8, 9, 6, 5};
  Heap heap = new_heap(compare_int);
  for (int i=0; i < size ;++i)
  {
    assert(heap_offer(heap, &array[i]));
  }
  destroy_heap(heap);
}

void test_heap_offer_with_increase()
{
  int size = 20;
  int array[] = {1, 1, 2, 3, 4, 5, 6, 7, 7, 8, 9, 10, 23, 24, 32, 33, 33,
                          45, 54, 335};
  Heap heap = new_heap(compare_int);
  for (int i=0; i < size ;++i)
  {
    assert(heap_offer(heap, &array[i]));
  }
  destroy_heap(heap);
}


void test_heap_offer_with_decrease()
{
  int size = 20;
  int array[] = {345, 70, 45, 45, 44, 43, 42, 41, 23, 23, 22, 12, 11, 10, 10,
                      9, 8, 7, 6, 5};
  Heap heap = new_heap(compare_int);
  for (int i=0; i < size ;++i)
  {
    assert(heap_offer(heap, &array[i]));
  }
  destroy_heap(heap);
}



void test_heap_poll()
{
  int array[] = {100, 4, 45, 3, 3};
  Heap heap = new_heap(compare_int);
  for (int i = 0; i < 5; ++i)
  {
    assert(heap_offer(heap, &array[i]));
  }

  size_t size = heap_size(heap);
  assert(size == 5);

  int* this;
  int* prec = heap_poll(heap);
  for (int i=0; i < size-1 ;++i)
  {
    this = heap_poll(heap);
    assert(compare_int(this, prec) >= 0);
    prec = this;
  }
  destroy_heap(heap);
}



void test_heap_poll_on_empty_heap()
{
  Heap heap = new_heap(compare_int);
  assert(!heap_poll(heap));
  destroy_heap(heap);
}

void test_heap_poll_some_element()
{
  int size = 10;
  int array[] = {9, 6, 5, 5, 6, 7, 8, 9, 6, 5};
  Heap heap = new_heap(compare_int);
  for (int i=0; i < size ;++i) assert(heap_offer(heap, &array[i]));

  int* this;
  int* prec = heap_poll(heap);
  for (int i=0; i < size-1 ;++i)
  {
    this = heap_poll(heap);
    assert(compare_int(this, prec) >= 0);
    prec = this;
  }

  destroy_heap(heap);
}

void test_heap_poll_with_decrease()
{
  int size = 20;
  int array[] = {345, 70, 45, 45, 44, 43, 42, 41, 23, 23, 22, 12, 11, 10, 10,
                      9, 8, 7, 6, 5};
  Heap heap = new_heap(compare_int);
  for (int i=0; i < size ;++i) assert(heap_offer(heap, &array[i]));

  int* this;
  int* prec = heap_poll(heap);
  for (int i=0; i < size-1 ;++i)
  {
    this = heap_poll(heap);
    assert(compare_int(this, prec) >= 0);
    prec = this;
  }

  destroy_heap(heap);
}


void test_heap_poll_with_increase()
{
  int size = 20;
  int array[] = {1, 1, 2, 3, 4, 5, 6, 7, 7, 8, 9,
                      10, 23, 24, 32, 33, 33, 45, 54, 335};

  Heap heap = new_heap(compare_int);
  for (int i=0; i < size ;++i) assert(heap_offer(heap, &array[i]));

  int* this;
  int* prec = heap_poll(heap);
  for (int i=0; i < size-1 ;++i)
  {
    this = heap_poll(heap);
    assert(compare_int(this, prec) >= 0);
    prec = this;
  }

  destroy_heap(heap);
}

void test_heap_poll_equals_elements()
{
  int size = 5;

  int array[] = {10, 10, 10, 10, 10};
  Heap heap = new_heap(compare_int);

  for (int i = 0; i < 5; ++i)
  {
    assert(heap_offer(heap, &array[i]));
  }

  size_t size_heap = heap_size(heap);
  assert(size_heap == 5);

  int* this;
  int* prec = heap_poll(heap);
  for (int i=0; i < size-1 ;++i)
  {
    this = heap_poll(heap);
    assert(compare_int(this, prec) >= 0);
    prec = this;
  }

  destroy_heap(heap);
}

void test_heap_poll_sparse_number()
{
  int size = 6;

  int array[] = {10, 6, 21, 4, 7, 0};
  Heap heap = new_heap(compare_int);
  for (int i = 0; i < 6; ++i)
  {
    assert(heap_offer(heap, &array[i]));
  }


  size_t size_heap = heap_size(heap);
  assert(size_heap == 6);

  int* this;
  int* prec = heap_poll(heap);
  for (int i=0; i < size-1 ;++i)
  {
    this = heap_poll(heap);
    assert(compare_int(this, prec) >= 0);
    prec = this;
  }

  destroy_heap(heap);
}



void test_heap_poll_not_increasing_elemets()
{
  int size = 5;

  int array[] = {10, 20, 30, 40, 50};
  Heap heap = new_heap(compare_int);
  for (int i = 0; i < 5; ++i)
  {
    assert(heap_offer(heap, &array[i]));
  }

  size_t size_heap = heap_size(heap);
  assert(size_heap == 5);

  int* this;
  int* prec = heap_poll(heap);
  for (int i=0; i < size-1 ;++i)
  {
    this = heap_poll(heap);
    assert(compare_int(this, prec) >= 0);
    prec = this;
  }
  destroy_heap(heap);
}



void test_heap_poll_not_decreasing_elemets()
{
  int size = 5;

  int array[] = {50, 40, 30, 20, 10};
  Heap heap = new_heap(compare_int);
  for (int i = 0; i < 5; ++i)
  {
    assert(heap_offer(heap, &array[i]));
  }

  size_t size_heap = heap_size(heap);
  assert(size_heap == 5);

  int* this;
  int* prec = heap_poll(heap);
  for (int i=0; i < size-1 ;++i)
  {
    this = heap_poll(heap);
    assert(compare_int(this, prec) >= 0);
    prec = this;
  }
  destroy_heap(heap);
}


void test_heap_size_on_empty_heap()
{
  Heap heap = new_heap(compare_int);
  size_t size = heap_size(heap);
  assert(size == 0);
  destroy_heap(heap);
}

void test_heap_size_with_one_element()
{
  int array[] = {9, 6, 5, 5, 6, 7, 8};
  Heap heap = new_heap(compare_int);
  heap_offer(heap, &array[0]);
  size_t size = heap_size(heap);
  assert(size == 1);
  destroy_heap(heap);
}

void test_heap_size_with_some_element()
{
  int array[] = {9, 6, 5, 5, 6, 7, 8};
  Heap heap = new_heap(compare_int);
  heap_offer(heap, &array[0]);
  heap_offer(heap, &array[1]);
  heap_offer(heap, &array[2]);
  heap_offer(heap, &array[3]);
  heap_offer(heap, &array[4]);
  size_t size = heap_size(heap);
  assert(size == 5);
  destroy_heap(heap);
}


void test_heap_empty()
{
  Heap heap = new_heap(compare_int);
  assert(!(heap_offer(heap, NULL)));
  size_t size = heap_size(heap);
  assert(size == 0);
  destroy_heap(heap);
}

void test_heap_one_element()
{
  int array[] = {10};
  Heap heap = new_heap(compare_int);
  assert(heap_offer(heap, &array[0]));
  size_t size = heap_size(heap);
  assert(size == 1);
  destroy_heap(heap);
}

void test_heap_peek_equals_elements()
{
  int array[] = {10, 10, 10, 10, 10};
  Heap heap = new_heap(compare_int);
  for (int i = 0; i < 5; ++i)
  {
    assert(heap_offer(heap, &array[i]));
  }

  int* head = heap_peek(heap);
  size_t size = heap_size(heap);
  assert(size == 5);
  assert(heap_poll(heap) == head);
  destroy_heap(heap);
}


void test_heap_peek_on_empty_heap()
{
  Heap heap = new_heap(compare_int);
  assert(!heap_peek(heap));
  destroy_heap(heap);
}



void test_heap_peek_sparse_number()
{
  int array[] = {10, 6, 21, 4, 7, 0};
  Heap heap = new_heap(compare_int);
  for (int i = 0; i < 6; ++i)
  {
    assert(heap_offer(heap, &array[i]));
  }

  int* head = heap_peek(heap);
  size_t size = heap_size(heap);
  assert(size == 6);

  assert(heap_poll(heap) == head);
  destroy_heap(heap);
}



void test_heap_remove_on_empty_heap()
{
  int array[] = {9, 6, 5, 5, 6, 7, 8};
  Heap heap = new_heap(compare_int);
  assert(!heap_remove(heap, &array[0]));
  destroy_heap(heap);
}




void test_heap_remove_generic()
{
  int array[] = {100, 4, 75, 3, 3};
  Heap heap = new_heap(compare_int);
  for (int i = 0; i < 5; ++i)
  {
    assert(heap_offer(heap, &array[i]));
  }

  size_t size = heap_size(heap);

  int* element = heap_remove(heap, &array[2]);

  assert((size - 1) == heap_size(heap));

  assert(75 == *element);

  destroy_heap(heap);
}




void test_heap_remove_head()
{
  int array[] = {100, 4, 45, 3, 3};
  Heap heap = new_heap(compare_int);
  for (int i = 0; i < 5; ++i)
  {
    assert(heap_offer(heap, &array[i]));
  }

  int* head = heap_peek(heap);
  size_t size = heap_size(heap);

  assert(size == 5);

  //assert(heap_poll(heap) == head);

  int* element = heap_remove(heap, head);

  assert((size - 1) == heap_size(heap));

  assert(*head == *element);

  destroy_heap(heap);
}




//
// Main
//
int main(int argc, char* argv[])
{
  start_tests("heap.array");
  test(test_heap_empty);
  test(test_heap_one_element);
  end_tests();

  start_tests("heap.heap_contains");
  test(test_heap_contains_on_empty_heap);
  test(test_heap_contains_on_heap_with_one_element);
  test(test_heap_contains_on_heap_with_some_elements);
  end_tests();

  start_tests("heap.heap_offer");
  test(test_heap_offer_on_empty_heap);
  test(test_heap_offer_some_element);
  test(test_heap_offer_with_increase);
  test(test_heap_offer_with_decrease);
  end_tests();

  start_tests("heap.heap_peek");
  test(test_heap_peek_on_empty_heap);
  test(test_heap_peek_sparse_number);
  test(test_heap_peek_equals_elements);
  end_tests();


  start_tests("heap.heap_poll");
  test(test_heap_poll_on_empty_heap);
  test(test_heap_poll_some_element);
  test(test_heap_poll);
  test(test_heap_poll_not_decreasing_elemets);
  test(test_heap_poll_not_increasing_elemets);
  test(test_heap_poll_with_decrease);
  test(test_heap_poll_with_increase);
  test(test_heap_poll_sparse_number);
  test(test_heap_poll_equals_elements);
  end_tests();

  start_tests("heap.heap_remove");
  test(test_heap_remove_on_empty_heap);
  test(test_heap_remove_generic);
  test(test_heap_remove_head);
  end_tests();

  start_tests("heap.heap_size");
  test(test_heap_size_on_empty_heap);
  test(test_heap_size_with_one_element);
  test(test_heap_size_with_some_element);
  end_tests();

  return 0;
}
