#ifndef __WEIGHTED_GRAPH_DEFS_H__
#define __WEIGHTED_GRAPH_DEFS_H__

#include "../hash_table/hash_table.h"
#include "../standard_libraries.h"

struct weighted_graph
{
  size_t size;
  HashTable vertices;
};

#endif
