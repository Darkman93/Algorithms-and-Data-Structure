#ifndef __WEIGHTED_GRAPH_H__
#define __WEIGHTED_GRAPH_H__

#include "../standard_libraries.h"

typedef struct weighted_graph* WeightedGraph;

/**
 * @brief      Create a new weighted graph
 *
 * @return     The graph with weighted edge
 */
WeightedGraph new_weighted_graph();

/**
 * @brief      { function_description }
 *
 * @param[in]  graph        The graph
 * @param      source       The source
 * @param      destination  The destination
 * @param[in]  weight       The weight
 *
 * @return     { description_of_the_return_value }
 */
bool weighted_graph_add_edge(WeightedGraph graph, char* source, char* destination, double weight);

/**
 * @brief      Loads a weighted graph.
 *
 * @param      filename  The filename
 *
 * @return     the loaded graph
 */
WeightedGraph load_weighted_graph(char* filename);

#endif
