#ifndef __HEAP_H__
#define __HEAP_H__

#include "../standard_libraries.h"
#include "../function_types.h"

/*
 * Types
 */

typedef struct heap* Heap;

/*
 * Functions
 */

Heap new_heap(CompareFunction compare);
void destroy_heap(Heap heap);

/*
 * Returns true if this heap contains the specified element.
 */
bool heap_contains(Heap heap, void* data);

/**
 * Inserts the specified element into this heap.
 */
bool heap_offer(Heap heap, void* data);

/**
 * Retrieves, but does not remove, the head of this heap, or returns null if this heap is empty.
 */
void* heap_peek(Heap heap);

/**
 * Retrieves and removes the head of this heap, or returns null if this heap is empty.
 */
void* heap_poll(Heap heap);

/**
 * Removes a single instance of the specified element from this heap, if it is present.
 */
void* heap_remove(Heap heap, void* data);

/**
 * Returns the number of elements in this collection.
 */
size_t heap_size(Heap heap);

void heap_insert(Heap heap, void* priority, void* data);

void heap_print(Heap heap); // @todo only for testing

#endif