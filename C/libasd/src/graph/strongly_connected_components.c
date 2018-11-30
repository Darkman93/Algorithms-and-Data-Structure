#include "strongly_connected_components.h"
#include "arrow.h"
#include "vertex.h"
#include "vertex_attributes.h"
#include "weighted_graph.h"
#include "weighted_graph_defs.h"
#include "../hash_table/hash_table_iterator.h"
#include "../stack/stack.h"
#include "../utils/comparators.h"
#include "../standard_libraries.h"


//
// Prototypes
//

void scc(Vertex vertex, int step, Stack stack, int* sccNumber);


//
// Public functions
//

int tarjan_strongly_connected_components(WeightedGraph graph)
{
  int step      = 0;
  int cfcNumber = 0;

  Stack                stack = new_stack();
  HashTableIterator iterator = new_hash_table_iterator(graph->vertices);

  while(hash_table_iterator_next(iterator))
  {
    Vertex vertex = hash_table_iterator_current_value(iterator);
    if(!vertex->attributes)
      scc(vertex, step, stack, &cfcNumber);
  }

  return cfcNumber;
}


//
// Private functions
//

void scc(Vertex vertex, int index, Stack stack, int* cfcNumber)
{
  vertex->attributes = new_tarjan_attributes(); // @todo cercare dove viene fatta la free

  TarjanAttributes currentIndexes = (TarjanAttributes) vertex->attributes;
  currentIndexes->index = index;
  currentIndexes->lowIndex = index;
  currentIndexes->onStack = 1;

  stack_push(stack, vertex);
  ++index;


  HashTableIterator iterator = new_hash_table_iterator(vertex->adjacents);

  while(hash_table_iterator_next(iterator))
  {
    Arrow        arrow = (Arrow) hash_table_iterator_current_value(iterator);
    Vertex destination = arrow->destination;

    TarjanAttributes destinationIndexes = (TarjanAttributes) destination->attributes;
    if(!destinationIndexes)
    {
      scc(destination, index, stack, cfcNumber);
      destinationIndexes = (TarjanAttributes) destination->attributes;
      currentIndexes->lowIndex = min_int(currentIndexes->lowIndex, destinationIndexes->lowIndex);
    }
    else if(destinationIndexes->onStack == 1)
    {
      currentIndexes->lowIndex = min_int(currentIndexes->lowIndex, destinationIndexes->index);
    }
  }

  if(currentIndexes->index == currentIndexes->lowIndex)
  {
    int sccSize = 1;
    Vertex next = stack_pop(stack);
    TarjanAttributes nextIndexes = (TarjanAttributes) next->attributes;
    nextIndexes->onStack = 0;

    while(next != vertex)
    {
      next = stack_pop(stack);
      nextIndexes = ((TarjanAttributes) next->attributes);
      nextIndexes->onStack = 0;
      ++sccSize;
    }

    printf("\nSize: %d\n", sccSize); // @todo spostare in qualche modo nel main
    ++*cfcNumber;
  }
}
