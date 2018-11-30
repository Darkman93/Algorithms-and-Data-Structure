#include "standard_libraries.h"
#include "asd.h"


//
// Configuration
//
char* graphFilename = "data/italian_dist_graph.csv";

int   numOfPaths = 5;
char* sources[]  = {"torino", "torino", "torino", "roma", "perfugas"};
char* dests[]    = {"catania", "borsoi", "sassari", "venezia", "bulzi"};


//
// Main
//
int main(int argc, char  *argv[])
{
  printf("#EXERCISE 3\n\n");

  printf("Loading graph ... "); fflush(stdout);
  WeightedGraph graph = load_weighted_graph(graphFilename);
  printf("COMPLETED\n\n"); fflush(stdout);

  printf("\n***\n");
  printf("Computing Strongly Connected Components ... "); fflush(stdout);
  int scc1 = tarjan_strongly_connected_components(graph);
  printf("COMPLETED\n\n");
  printf("Total number of Strongly Connected Components: %d\n\n", scc1);
  fflush(stdout);

  for (int i = 0; i < numOfPaths; ++i)
  {
    char* source      = sources[i];
    char* destination = dests[i];

    printf("\n***\n");
    printf("Computing path from **%s** to **%s** ... ", source, destination); fflush(stdout);
    double path = dijkstra_shortest_path(graph, source, destination);
    printf("COMPLETED\n\n");

    if   (path != DBL_MAX) printf("Distance: %lf Km\n", path);
    else                   printf("No path exists\n");

    printf("\n");

    fflush(stdout);
  }

  return EXIT_SUCCESS;
}
