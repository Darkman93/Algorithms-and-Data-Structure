#include <assert.h>
#include "../../include/utils.h"
#include "../../src/standard_libraries.h"
#include "../../src/test/test.h"
#include "../../src/graph/weighted_graph.h"
#include "../../src/graph/shortest_path.h"
#include "../../src/graph/strongly_connected_components.h"

//
//init_graph
//
void init_graph(WeightedGraph graph,int size, char* start[], char* end[], double weight[])
{
  for (int i = 0; i < size; ++i)
  {
    weighted_graph_add_edge(graph, start[i], end[i], weight[i]);
  }
}

//
//graph_ssc_test
//
void test_graph_ssc()
{
  int     size = 10;
  char*   start[]  =   {"A", "A", "B", "B", "C", "D", "D", "D", "E", "E"};
  char*   end[]    =   {"B", "D", "C", "D", "E", "B", "C", "E", "A", "C"};
  double  weight[] =   {10, 5, 1, 3, 4, 3, 9, 2, 7, 6};

  WeightedGraph graph = new_weighted_graph();
  init_graph(graph, size, start, end, weight);

  int ssc = tarjan_strongly_connected_components(graph);

  assert(ssc == 1);
}

//
//graph_dijkstra_test
//
void test_graph_dijkstra()
{
  int     size = 10;
  char*   start[]  =   {"A", "A", "B", "B", "C", "D", "D", "D", "E", "E"};
  char*   end[]    =   {"B", "D", "C", "D", "E", "B", "C", "E", "A", "C"};
  double  weight[] =   {10, 5, 1, 3, 4, 3, 9, 2, 7, 6};

  WeightedGraph graph = new_weighted_graph();
  init_graph(graph, size, start, end, weight);

  double minimum_path = dijkstra_shortest_path(graph, "A", "E");

  assert(minimum_path == 0.007000);
}


//
// Main
//
int main(int argc, char  *argv[])
{
  start_tests();
  test(test_graph_ssc);
  test(test_graph_dijkstra);
  end_tests();

  return EXIT_SUCCESS;
}
