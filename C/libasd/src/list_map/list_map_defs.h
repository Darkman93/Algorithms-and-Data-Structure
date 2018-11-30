#ifndef __LIST_MAP_DEFS_H__
#define __LIST_MAP_DEFS_H__

#include "list_node.h"
#include "list_map.h"
#include "../standard_libraries.h"
#include "../function_types.h"

/*
 * Data Structures
 */

struct list_map
{
  CompareFunction compareKey; // The function to compare keyes.
  size_t   size;							// The number of nodes.
  ListNode head;							// The first node of the list.
};

/*
 * Functions
 */

//void list_exists(ListMap list);

#endif