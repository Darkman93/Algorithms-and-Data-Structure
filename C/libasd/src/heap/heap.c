#include "heap.h"
#include "../unsigned_types.h"

#define NULL_INDEX SIZE_T_MAX_VALUE
#define HEAP_MIN_CAPACITY 16
#define HEAP_MAX_CAPACITY (SIZE_T_MAX_VALUE - 1)

/*
 * Types
 */

typedef void* HeapNode;

/*
 * Data Structures
 */

struct heap
{
  CompareFunction compare;
  HeapNode* elements;
  size_t capacity;
  size_t elementsNumber;
};

/*
 * Functions
 */

HeapNode* init_elements_array(size_t size);
size_t reach(Heap heap, void* data);
void check_and_resize(Heap heap);
void move_up(Heap heap, size_t index);
void move_down(Heap heap, size_t index);

// @todo costruttore generico che prende tutti i parametri, poi demandare tutto alla factory (se avanza tempo)
Heap new_heap(CompareFunction compare)
{
  Heap heap = (Heap) malloc(sizeof(struct heap));
  if (!heap) error(EXIT_FAILURE, 0, "Malloc error in function %s", __func__);

  size_t size = HEAP_MIN_CAPACITY; // @todo variabile TEMPORANEA sino all'implementaz della factory
  heap->compare  = compare;
  heap->elements = init_elements_array(size);
  heap->capacity = HEAP_MIN_CAPACITY;
  heap->elementsNumber = 0;

  return heap;
}

void destroy_heap(Heap heap)
{
  free(heap->elements);
  free(heap);
}

bool heap_contains(Heap heap, void* data)
{
  if (!heap) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  size_t index = reach(heap, data);
  return index != NULL_INDEX;
}

bool heap_offer(Heap heap, void* data)
{
  if (!heap) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  if(data){
    check_and_resize(heap); // @todo handle false
    heap->elements[ heap->elementsNumber++ ] = data;
    move_up(heap, heap->elementsNumber-1);
    return true;
  }
  return false;
}

void* heap_peek(Heap heap)
{
  if (!heap) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  return heap->elementsNumber > 0 ? heap->elements[0] : NULL;
}

void* heap_poll(Heap heap)
{
  if (!heap) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  if (heap->elementsNumber > 0)
  {
    void* elementToReturn = heap->elements[0];
    --(heap->elementsNumber);
    heap->elements[0] = heap->elements[heap->elementsNumber];
    move_down(heap, 0);
    check_and_resize(heap);
    return elementToReturn;
  }
  return NULL;
}

void* heap_remove(Heap heap, void* data)
{
  if (!heap) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  size_t index = reach(heap, data);
  if (index != NULL_INDEX)
  {
    void* elementToReturn = heap->elements[index];
    --(heap->elementsNumber);
    heap->elements[index] = heap->elements[heap->elementsNumber];
    move_down(heap, index);
    check_and_resize(heap);
    return elementToReturn;
  }
  return NULL;
}

size_t heap_size(Heap heap)
{
  if (!heap) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  return heap->elementsNumber;
}

HeapNode* init_elements_array(size_t size)
{
  HeapNode* elements = (HeapNode*) malloc(sizeof(HeapNode) * size);
  if (!elements) {
    printf("Impossible allocate heap element array\n");
    exit(EXIT_FAILURE);
  }
  return elements;
}

size_t reach(Heap heap, void* data)
{
  if (!heap) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  CompareFunction compare = heap->compare;
  for (size_t i=0; i < heap->elementsNumber; ++i)
  {
    if (!compare(heap->elements[i], data))
      return i;
  }
  return NULL_INDEX;
}

void check_and_resize(Heap heap)
{
  if (!heap) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  if (heap->capacity == HEAP_MAX_CAPACITY)
  {
    printf("Memory error: heap full\n");
    exit(EXIT_FAILURE);
  }

  // @todo separare il codice come fatto per l'hash_table

  // increase capacity case
  if (heap->elementsNumber >= heap->capacity)
  {
    size_t increasedCapacity = heap->capacity << 1;
    if (increasedCapacity > HEAP_MAX_CAPACITY || increasedCapacity <= heap->capacity) //it handles overflow
      increasedCapacity = HEAP_MAX_CAPACITY;

    size_t capacityBytes = increasedCapacity * sizeof(HeapNode);
    heap->capacity = increasedCapacity;
    heap->elements = realloc(heap->elements, capacityBytes);
    if (!heap->elements) error(EXIT_FAILURE, 0, "Malloc error in function %s", __func__);
  }

  // decrease capacity case
  else if (heap->elementsNumber > HEAP_MIN_CAPACITY && heap->elementsNumber <= (heap->capacity >> 2)) // @todo ricontrollare
  {
    size_t decreasedCapacity = heap->capacity >> 1;
    if (decreasedCapacity < HEAP_MIN_CAPACITY)
      decreasedCapacity = HEAP_MIN_CAPACITY;

    size_t capacityBytes = decreasedCapacity * sizeof(HeapNode);
    heap->capacity = decreasedCapacity;
    heap->elements = realloc(heap->elements, capacityBytes);
    if (!heap->elements) error(EXIT_FAILURE, 0, "Malloc error in function %s", __func__);
  }
}

/*
void moveUp(int i){
 if(i<=lastIndex){
   elementWithPriority elem=heap[i];
   while (i!=1 && elem.priority < heap[i/2].priority) {
     heap[i]=heap[i/2];
     i=i/2;
   }
   heap[i]=elem;
   }
  }
*/
void move_up(Heap heap, size_t index)
{
  if (!heap) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  if (index < heap->elementsNumber)
  {
    CompareFunction compare = heap->compare;
    size_t iFather;
    HeapNode* elements = heap->elements;
    HeapNode     pivot = elements[index];
    while (index != 0 && compare(pivot, elements[index >> 1]) < 0)
    {
      iFather = index >> 1;
      elements[index] = elements[iFather];
      index = iFather;
    }
    elements[index] = pivot;
  }
}

/*
void moveDown(int i) {
 if(i <= lastIndex){
    elementWithPriority elem = heap[i];
    while(2*i <= lastIndex) {
      int l=2*i;
      if(l+1<=lastIndex)
        if(heap[l].priority >= heap[l+1].priority) l++;
      if(elem.priority <=heap[l].priority) break;
      heap[i]=heap[l];
      i=l;
    }
    heap[i]=elem;
  }
}
*/
void move_down(Heap heap, size_t index)
{
  if (!heap) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  if (index < heap->elementsNumber)
  {
    CompareFunction compare = heap->compare;
    size_t iChild;
    size_t elementsNumber = heap->elementsNumber;
    HeapNode* elements = heap->elements;
    HeapNode     pivot = elements[index];
    while((index << 1) < elementsNumber)
    {
      iChild = index << 1;
      if (iChild+1 < elementsNumber && compare(elements[iChild], elements[iChild+1]) > 0) ++iChild;
      if (compare(pivot, elements[iChild]) <= 0) break;
      elements[index] = elements[iChild];
      index = iChild;
    }
    elements[index] = pivot;
  }
}