#ifndef __STRONGLY_CONNECTED_COMPONENTS_H__
#define __STRONGLY_CONNECTED_COMPONENTS_H__

#include "weighted_graph.h"

/**
 * @brief      Call the ssc function for make the strongly connect components
 *
 * @param[in]  graph  The graph
 *
 * @return     the number of the strongly connect components
 */
int tarjan_strongly_connected_components(WeightedGraph graph);

#endif
