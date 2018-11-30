#ifndef __BINARY_NODE_H__
#define __BINARY_NODE_H__

#include "../standard_libraries.h"
#include "../function_types.h"

/*
 * Types
 */

typedef struct binary_node* BinaryNode;

/*
 * Data Structures
 */

struct binary_node
{
  void* key;
  void* value;
  BinaryNode left;
  BinaryNode right;
};

/*
 * Functions
 */

/**
 * @brief      Create a new binary-node
 *
 * @param      key    The key
 * @param      value  The value
 * @param[in]  left   The left
 * @param[in]  right  The right
 *
 * @return     the new binary-node
 */
BinaryNode new_binary_node(void* key, void* value, BinaryNode left, BinaryNode right);


/**
 * @brief      Destroy the single BinaryNode
 *
 * @param[in]  node  The node
 */
void   destroy_binary_node(BinaryNode node);


/**
 * @brief      Destroy the full structure BinaryNode
 *
 * @param[in]  node  The node
 */
void   destroy_binary_node_recursive(BinaryNode node);

/**
 * @brief      Check if the node is a leaf
 *
 * @param[in]  node  The node
 *
 * @return     @c true if node is a leaf, @c false isn't
 */
bool binary_node_is_leaf(BinaryNode node);

/**
 * @brief      Search a node
 *
 * @param      node        The node
 * @param      key         The key
 * @param[in]  compareKey  The compare key
 *
 * @return     The pointer of the node if a node with the specified key is in the
 *             tree
 */
BinaryNode* binary_node_reach(BinaryNode* node, void* key, CompareFunction compareKey);

/**
 * @brief      Remove from the tree the node with minimum key
 *
 * @param      node  The node
 *
 * @return     The binary-node with minimum key
 */
BinaryNode binary_node_detach_min(BinaryNode* node);

#endif