#ifndef __VERTEX_H__
#define __VERTEX_H__

#include "../hash_table/hash_table.h"


//
// Data types
//

typedef struct vertex* Vertex;


//
// Data Structures
//

struct vertex
{
  char* label;
  void* attributes;
  void* data;
  HashTable adjacents;
};


//
// Functions
//

/**
 * @brief      Create a new vertex
 *
 * @param      label  The label
 * @param      data   The data
 *
 * @return     the new vertex create
 */
Vertex new_vertex(char* label, void* data);

/**
 * @brief      Destroy the structure vertex
 *
 * @param      vertex  The vertex
 */
void destroy_vertex(Vertex* vertex);

/**
 * @brief      Append or update the corrispondent arrow on the source vertex.
 *
 * @param[in]  source       The source
 * @param[in]  destination  The destination
 * @param[in]  weight       The weight
 */
void vertex_append_arrow(Vertex source, Vertex destination, double weight);

/**
 * @brief      Put the attributes to NULL
 *
 * @param[in]  vertex  The vertex
 */
void vertex_reset(Vertex vertex);

/**
 * @brief      Compare weight of two Vertex.
 *
 * @param      v1    The first vertex.
 * @param      v2    The second vertex.
 *
 * @return     0 if the two vertexes have the same label. Another @c int otherwise.
 */
int compare_vertex(void* v1, void* v2);

#endif
