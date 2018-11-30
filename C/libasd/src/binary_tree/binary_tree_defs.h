#ifndef __BINARY_TREE_DEFS_H__
#define __BINARY_TREE_DEFS_H__

#include "binary_node.h"
#include "../standard_libraries.h"
#include "../function_types.h"

struct binary_tree
{
  CompareFunction compareKey;
  size_t     size;
  BinaryNode root;
};

//void tree_exists(BinaryTree tree);

#endif