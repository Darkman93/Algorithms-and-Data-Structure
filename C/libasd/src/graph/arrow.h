#ifndef __ARROW_H__
#define __ARROW_H__

#include "vertex.h"


//
// Data types
//

typedef struct arrow* Arrow;


//
// Data Structures
//

struct arrow
{
  Vertex destination; // The recipient of the edge.
  double  weight;			// The weight of the edge.
};


//
// Functions
//

/**
 * @brief      Create a new arrow
 *
 * @param[in]  vertex  The vertex
 * @param[in]  weight  The weight
 *
 * @return     the new @c arrow
 */
Arrow new_arrow(Vertex vertex, double weight);

/**
 * @brief      Destroy the structure arrow
 *
 * @param      arrow  The arrow
 */
void destroy_arrow(Arrow* arrow);

#endif
