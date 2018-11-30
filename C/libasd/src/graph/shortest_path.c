#include "shortest_path.h"
#include "arrow.h"
#include "vertex.h"
#include "weighted_graph.h"
#include "weighted_graph_defs.h"
#include "../utils/comparators.h"
#include "../utils/numbers.h"
#include "../hash_table/hash_table.h"
#include "../hash_table/hash_table_iterator.h"
#include "../priority_queue/priority_queue.h"
#include "../priority_queue/priority_queue_factory.h"
#include "../standard_libraries.h"


double dijkstra_shortest_path(WeightedGraph graph, char* start, char* destination)
{
  Vertex startVertex = hash_table_get(graph->vertices, start);
  if (!startVertex) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);

  PriorityQueue queue = create_priority_queue(compare_vertex, compare_double);
  HashTableIterator verticesIterator = new_hash_table_iterator(graph->vertices);

  while (hash_table_iterator_next(verticesIterator))
  {
    Vertex vertex = (Vertex) hash_table_iterator_current_value(verticesIterator);
    vertex->attributes = new_double(DBL_MAX);
    priority_queue_offer(queue, vertex, vertex->attributes);
  }

  destroy_hash_table_iterator(&verticesIterator);
  double* newDistance = new_double(0);
  startVertex->attributes = newDistance;
  priority_queue_change_priority(queue, startVertex, newDistance);
  double sourceDistance, recipientDistance, weight;
  Vertex sourceVertex, recipientVertex;
  Arrow arrow;

  while (!priority_queue_is_empty(queue))
  {
    sourceVertex = (Vertex) priority_queue_poll(queue);
    if(!strcmp(sourceVertex->label, destination))
    {
      Vertex destinationVertex = sourceVertex;
      double destinationDistance = *(double*) destinationVertex->attributes;
      if(destinationDistance != DBL_MAX)
      {
        double km = *(double*) destinationVertex->attributes / 1000;
        return km;
      }
      //printf("From %s to %s: %lf Km\n", startVertex->label, destinationVertex->label, *(double*) destinationVertex->attributes / 1000);
      else return DBL_MAX;
      //printf("%s can't be reached from %s\n", destinationVertex->label, startVertex->label);
      //return;
    }

    sourceDistance = *(double*) sourceVertex->attributes;
    HashTableIterator adjacentsIterator = new_hash_table_iterator(sourceVertex->adjacents);

    while (hash_table_iterator_next(adjacentsIterator))
    {
      arrow = (Arrow) hash_table_iterator_current_value(adjacentsIterator);
      recipientVertex = arrow->destination;
      recipientDistance = *(double*) recipientVertex->attributes;
      weight = arrow->weight;
      if (sourceDistance + weight < recipientDistance)
      {
        newDistance = new_double(sourceDistance + weight);
        recipientVertex->attributes = newDistance;
        priority_queue_change_priority(queue, recipientVertex, newDistance);
      }
    }
    destroy_hash_table_iterator(&adjacentsIterator);
    // Printa l' albero.
    //printf("Node: %s, Distance: %lf\n", sourceVertex->label, *(double*) sourceVertex->attributes);
  }

  return DBL_MAX;
}



// @todo init_dijkstra
