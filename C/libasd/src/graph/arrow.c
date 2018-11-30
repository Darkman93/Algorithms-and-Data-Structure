#include "arrow.h"
#include "vertex.h"
#include "../standard_libraries.h"

Arrow new_arrow(Vertex vertex, double weight)
{
  Arrow arrow = (Arrow) malloc(sizeof(struct arrow));
  if (!arrow) error(EXIT_FAILURE, 0, "Malloc error in function %s", __func__);
  arrow->destination = vertex;
  arrow->weight      = weight;
  return arrow;
}

void destroy_arrow(Arrow* arrow)
{
  free(*arrow);
  *arrow = NULL;
}
