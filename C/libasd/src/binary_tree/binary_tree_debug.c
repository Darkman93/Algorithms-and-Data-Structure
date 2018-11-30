#include "binary_tree_debug.h"
#include "binary_node.h"
#include "binary_tree.h"
#include "binary_tree_defs.h"

//
// Prototypes
//

size_t binary_tree_count_ric(BinaryNode node);
void binary_tree_get_inorder_array_ric(BinaryNode node, void** array, size_t* index);
bool is_binary_tree_ric(BinaryNode node, CompareFunction compareKey);


//
// Public functions
//

bool is_binary_tree(BinaryTree tree)
{
  return is_binary_tree_ric(tree->root, tree->compareKey);
}

size_t binary_tree_count(BinaryTree tree)
{
  return binary_tree_count_ric(tree->root);
}

//Not used function
void** binary_tree_get_inorder_array(BinaryTree tree)
{
  size_t index = 0;
  void** array = (void**) malloc(tree->size * sizeof(void*));
  binary_tree_get_inorder_array_ric(tree->root, array, &index);
  return array;
}


//
// Private functions
//

bool is_binary_tree_ric(BinaryNode node, CompareFunction compareKey)
{
  if (node)
  {
    bool result = true;

    if (node->left)  result = result && compareKey(node->left->key,  node->key) < 0;
    if (node->right) result = result && compareKey(node->right->key, node->key) > 0;

    return result && is_binary_tree_ric(node->left, compareKey) && is_binary_tree_ric(node->right, compareKey);
  }
  return true;
}

size_t binary_tree_count_ric(BinaryNode node)
{
  return node ? 1 + binary_tree_count_ric(node->left) + binary_tree_count_ric(node->right) : 0;
}

void binary_tree_get_inorder_array_ric(BinaryNode node, void** array, size_t* index)
{
  if (node)
  {
    binary_tree_get_inorder_array_ric(node->left, array, index);
    array[*index] = node->value;
    ++(*index);
    binary_tree_get_inorder_array_ric(node->right, array, index);
  }
}
