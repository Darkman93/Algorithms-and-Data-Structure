#ifndef __BINARY_TREE_DEBUG_H__
#define __BINARY_TREE_DEBUG_H__

#include "binary_tree.h"
#include "../standard_libraries.h"
#include "../function_types.h"

/**
 * @brief      Determines if binary tree.
 *
 * @param[in]  tree  The tree
 *
 * @return     True if binary tree, False otherwise.
 */
bool is_binary_tree(BinaryTree tree);

/**
 * @brief      The number of the node in the tree
 *
 * @param[in]  tree  The tree
 *
 * @return     @c size_t the total number of the node that the tree contains
 */
size_t binary_tree_count(BinaryTree tree);

/**
 * @brief      Do a inorder visit of the tree and put the node in the array
 *
 * @param[in]  tree  The tree
 *
 * @return     the pointer to the array wich contains the inorder visit of the tree
 */
void** binary_tree_get_inorder_array(BinaryTree tree);

#endif