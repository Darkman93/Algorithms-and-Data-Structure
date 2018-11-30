#ifndef __SHORTEST_PATH_H__
#define __SHORTEST_PATH_H__

#include "weighted_graph.h"

/**
 * @brief      Implementation of the Dijkstra algorithm for find the minimum path
 *
 * @param[in]  graph        The graph
 * @param      source       The source
 * @param      destination  The destination
 */
double dijkstra_shortest_path(WeightedGraph graph, char* start, char* destination);

#endif
