#include "vertex.h"
#include "vertex_attributes.h"
#include "arrow.h"
#include "../utils/comparators.h"
#include "../utils/hashes.h"
#include "../hash_table/hash_table_iterator.h"
#include "../hash_table/hash_table_factory.h"
#include "../standard_libraries.h"


Vertex new_vertex(char* label, void* data)
{
  Vertex vertex = (Vertex) malloc(sizeof(struct vertex));
  if (!vertex) error(EXIT_FAILURE, 0, "Malloc error in function %s", __func__);
  vertex->label      = label;
  vertex->data       = data;
  vertex->attributes = NULL;
  vertex->adjacents  = create_hash_table(compare_string, hash_string);
  return vertex;
}

void destroy_vertex(Vertex* vertex)
{
  // più tutti gli altri
  // free()
  //*vertex = NULL;
}

void vertex_append_arrow(Vertex source, Vertex destination, double weight)
{
  if (!source->adjacents)
    source->adjacents = create_hash_table(compare_string, hash_string);

  // @todo per il momento, non si possono inserire frecce già presenti
  //       prossimamente valutare se si meglio aggiornare il peso
  /*
  if (hash_table_contains_key(source->adjacents, destination->label))
  {
    printf("Arrow from '%s' to '%s' already exists (distance: %lf)\n", source->label, destination->label, weight);
    exit(EXIT_FAILURE);
  }
  */

   //printf("Link from '%s' to '%s' with distance %lf\n", source->label, destination->label, weight); //debug

  Arrow arrow = new_arrow(destination, weight);
  hash_table_put(source->adjacents, destination->label, arrow);
  // @todo in caso di aggiornamento fare la free sul arrow restituito dalla put
}


// @todo ??? che è sta robba?
/*
void vertex_reset(Vertex vertex)
{
  vertex->attributes = NULL;
}
*/

int compare_vertex(void* v1, void* v2)
{
  char* s1 = ((Vertex) v1)->label;
  char* s2 = ((Vertex) v2)->label;
  return strcmp(s1, s2);
}