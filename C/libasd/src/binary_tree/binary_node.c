#include "binary_node.h"

BinaryNode new_binary_node(void* key, void* value, BinaryNode left, BinaryNode right)
{
  BinaryNode node = (BinaryNode) malloc(sizeof(struct binary_node));
  if (!node) error(EXIT_FAILURE, 0, "Malloc error in function %s", __func__);
  node->key   = key;
  node->value = value;
  node->left  = left;
  node->right = right;
  return node;
}

void destroy_binary_node(BinaryNode node)
{
  free(node);
}

void destroy_binary_node_recursive(BinaryNode node)
{
  if (node)
  {
    destroy_binary_node_recursive(node->left);
    destroy_binary_node_recursive(node->right);
    destroy_binary_node(node);
  }
}

bool binary_node_is_leaf(BinaryNode node)
{
  return !node || (!node->left && !node->right);
}

BinaryNode* binary_node_reach(BinaryNode* node, void* key, CompareFunction compareKey)
{
  int compared;
  while (*node)
  {
    compared = compareKey(key, (*node)->key);
    if (!compared) return node; // equals 0, found
    node = compared < 0 ? &((*node)->left) : &((*node)->right);
  }
  return node;
}

BinaryNode binary_node_detach_min(BinaryNode* node)
{
  if (*node)
  {
    while ((*node)->left) *node = (*node)->left;

    BinaryNode nodeToRemove = *node;
    *node = (*node)->right;

    // @todo potare? forse non è necessario
    //nodeToRemove->left  = NULL;
    //nodeToRemove->right = NULL;

    return nodeToRemove;
  }

  return NULL;
}
