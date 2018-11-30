#include "list_node.h"

ListNode new_list_node(void* key, void* value, ListNode next)
{
  ListNode node = (ListNode) malloc(sizeof(struct list_node));
  if (!node) error(EXIT_FAILURE, 0, "Malloc error in function %s", __func__);
  node->key   = key;
  node->value = value;
  node->next  = next;
  return node;
}

void destroy_list_node(ListNode node)
{
  free(node);
}

void destroy_list_node_recursive(ListNode node)
{
  ListNode next;
  while (node)
  {
    next = node->next;
    destroy_list_node(node);
    node = next;
  }
}

ListNode* list_node_reach(ListNode* node, void* key, CompareFunction compareKey)
{
  int compare;
  while (*node)
  {
    compare = compareKey(key, (*node)->key);
    if (!compare) return node;
    node = &((*node)->next);
  }
  return node;
}

ListNode* list_node_find_position(ListNode* node, void* key, CompareFunction compareKey)
{
  int compare;
  while (*node)
  {
    compare = compareKey(key, (*node)->key);
    if (compare <= 0) return node;
    node = &((*node)->next);
  }
  return node;
}

void* list_node_remove(ListNode* node)
{
  void* value = NULL;
  if (*node)
  {
    ListNode nodeToRemove = *node;
    value = nodeToRemove->value;
    *node = nodeToRemove->next;
    destroy_list_node(nodeToRemove);
  }
  return value;
}