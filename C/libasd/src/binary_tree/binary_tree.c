#include "binary_tree.h"
#include "binary_node.h"
#include "binary_tree_defs.h"

BinaryTree new_binary_tree(CompareFunction compareKey)
{
  if(!compareKey) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  BinaryTree tree = (BinaryTree) malloc(sizeof(struct binary_tree));
  if (!tree) error(EXIT_FAILURE, 0, "Malloc error in function %s", __func__);
  tree->compareKey = compareKey;
  tree->size = 0;
  tree->root = NULL;
  return tree;
}

void destroy_binary_tree(BinaryTree* tree)
{
  if (!*tree) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  destroy_binary_node_recursive((*tree)->root);
  free(*tree);
  *tree = NULL;
}

bool binary_tree_contains_key(BinaryTree tree, void* key)
{
  if (!tree || !key) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  BinaryNode* node = binary_node_reach(&(tree->root), key, tree->compareKey);
  return *node != NULL;
}

void* binary_tree_get(BinaryTree tree, void* key)
{
  if (!tree || !key) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  BinaryNode* node = binary_node_reach(&(tree->root), key, tree->compareKey);
  return (*node) ? (*node)->value : NULL;
}

bool binary_tree_is_empty(BinaryTree tree)
{
  if (!tree) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  return !tree->root;
}

void* binary_tree_put(BinaryTree tree, void* key, void* value)
{
  if (!tree || !key) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);

  void* replaced = NULL;
  BinaryNode* node = binary_node_reach(&(tree->root), key, tree->compareKey);

  if (*node)
  {
    replaced = (*node)->value;
    (*node)->value = value;
  }
  else
  {
    *node = new_binary_node(key, value, NULL, NULL);
    ++(tree->size);
  }

  return replaced;
}

void* binary_tree_remove(BinaryTree tree, void* key)
{
  if (!tree || !key) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);

  void* value = NULL;
  BinaryNode  nodeToRemove;
  BinaryNode* node = binary_node_reach(&(tree->root), key, tree->compareKey);

  if (*node)
  {
    if (!((*node)->right)) // right == NULL
    {
      value = (*node)->value;
      nodeToRemove = *node;
      *node = (*node)->left;
    }
    else
    {
      value = (*node)->value;
      nodeToRemove   = binary_node_detach_min(&((*node)->right));
      (*node)->key   = nodeToRemove->key;
      (*node)->value = nodeToRemove->value;
    }

    destroy_binary_node(nodeToRemove);
    --(tree->size);
  }

  return value;
}

size_t binary_tree_size(BinaryTree tree)
{
  if (!tree) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  return tree->size;
}