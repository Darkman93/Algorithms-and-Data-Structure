#include "weighted_graph.h"
#include "weighted_graph_defs.h"
#include "arrow.h"
#include "vertex.h"
#include "vertex_attributes.h"
#include "../utils/comparators.h"
#include "../utils/files.h"
#include "../utils/hashes.h"
#include "../utils/strings.h"
#include "../hash_table/hash_table.h"
#include "../hash_table/hash_table_factory.h"
#include "../standard_libraries.h"

#define STR_BUFF_LEN 1000


//
// Public functions
//

WeightedGraph new_weighted_graph()
{
  WeightedGraph graph = (WeightedGraph) malloc(sizeof(struct weighted_graph));
  if (!graph) error(EXIT_FAILURE, 0, "malloc error in function %s", __func__);

  graph->size = 0;
  graph->vertices = create_hash_table(compare_string, hash_string);
  return graph;
}

bool weighted_graph_add_edge(WeightedGraph graph, char* sourceLabel, char* destinationLabel, double weight)
{
  //
  // Retrive of insert SOURCE vertex if not exists

  Vertex sourceVertex = (Vertex) hash_table_get(graph->vertices, sourceLabel);
  if (!sourceVertex)
  {
    sourceVertex = new_vertex(sourceLabel, NULL);
    hash_table_put(graph->vertices, sourceLabel, sourceVertex);
    ++(graph->size);
  }

  //
  // Retrive of insert DESTINATION vertex if not exists

  Vertex destinationVertex = (Vertex) hash_table_get(graph->vertices, destinationLabel);
  if (!destinationVertex)
  {
    destinationVertex = new_vertex(destinationLabel, NULL);
    hash_table_put(graph->vertices, destinationLabel, destinationVertex);
    ++(graph->size);
  }

  vertex_append_arrow(sourceVertex, destinationVertex, weight);

  // Per i non orientati:
  vertex_append_arrow(destinationVertex, sourceVertex, weight);

  // @todo perché true?
  return true;
}

WeightedGraph load_weighted_graph(char* filename)
{
  FILE* fp = fopen(filename, "r");
  if (!fp) error(EXIT_FAILURE, 0, "fopen error in function %s", __func__);

  char src_buff[STR_BUFF_LEN];
  char dst_buff[STR_BUFF_LEN];
  double weight;

  WeightedGraph graph = new_weighted_graph();
  size_t      n_lines = line_counter(fp);

  for (int i=0; i < n_lines; ++i)
  {
    int n_matched = fscanf(fp, "%[^,],%[^,],%lf ", src_buff, dst_buff, &weight);
    if (n_matched != 3) error(EXIT_FAILURE, 0, "Error format csv line: %d field(s) matched in function %s", n_matched, __func__);

    weighted_graph_add_edge(graph, new_string(src_buff), new_string(dst_buff), weight);
  }

  fclose(fp);
  // printf("Nodes: %zu\n", graph->size); // DEBUG???
  return graph;
}
