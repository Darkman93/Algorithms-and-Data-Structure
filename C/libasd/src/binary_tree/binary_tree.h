#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include "../standard_libraries.h"
#include "../function_types.h"

typedef struct binary_tree* BinaryTree;

/**
 * @brief      Creates a new binary-tree.
 *
 * @param[in]  compareKey  The function to compare two keys.
 *
 * @return     The new binary-tree.
 */
BinaryTree new_binary_tree(CompareFunction compareKey);


/**
 * @brief      Destroy recursively the tree
 *
 * @param      tree  The tree
 */
void   destroy_binary_tree(BinaryTree* tree);


/**
 * @brief      Search if exist the key in the tree
 *
 * @param[in]  tree  The tree
 * @param      key   The key
 *
 * @return     @c true if the key exist in the tree, @c false otherwise
 */
bool   binary_tree_contains_key(BinaryTree tree, void* key);

/**
 * @brief      Search a node in the tree.
 *
 * @param[in]  tree  The binary-tree.
 * @param[in]  key   The key.
 *
 * @return     The value of the node if a node with the specified key is in the
 *             tree. @c NULL otherwise.
 */
void*  binary_tree_get(BinaryTree tree, void* key);

/**
 * @brief      Check if the tree is empty.
 *
 * @param[in]  tree  The tree
 *
 * @return     @c true if the tree is empty. @c false otherwise.
 */
bool   binary_tree_is_empty(BinaryTree tree);

/**
 * @brief      Insert a key-value node in the tree, or replace the value of an
 *             existing one.
 *
 * @param[in]  tree   The binary-tree.
 * @param[in]  key    The key.
 * @param[in]  value  The value.
 *
 * @return     The old value of the node if a node with the specified key is
 *             already in the tree. @c NULL otherwise.
 */
void*  binary_tree_put(BinaryTree tree, void* key, void* value);

/**
 * @brief      Deletes a node in the tree.
 *
 * @param[in]  tree  The binary-tree.
 * @param[in]  key   The key of the node to be deleted.
 *
 * @return     The value of the node if a node with the specified key is in the
 *             tree. @c NULL otherwise.
 */
void*  binary_tree_remove(BinaryTree tree, void* key);

/**
 * @brief      Gets the size of a binary-tree.
 *
 * @param[in]  tree  The binary-tree.
 *
 * @return     The size of the tree.
 */
size_t binary_tree_size(BinaryTree tree);

#endif