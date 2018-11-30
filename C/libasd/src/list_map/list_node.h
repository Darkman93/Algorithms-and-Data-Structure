#ifndef __LIST_NODE_H__
#define __LIST_NODE_H__

#include "../standard_libraries.h"
#include "../function_types.h"

/*
 * Types
 */

typedef struct list_node* ListNode;

/*
 * Data Structures
 */

struct list_node
{
  void* key;
  void* value;
  ListNode next;
};

/*
 * Functions
 */

/**
 * @brief      Creates a new List Node.
 *
 * @param[in]  key    The key.
 * @param[in]  value  The value.
 * @param[in]  next   The pointer to the next node.
 *
 * @return     The new List Node.
 */
ListNode new_list_node(void* key, void* value, ListNode next);

/**
 * @brief      Destroy a List Node.
 *
 * @param[in]  node  The List Node.
 */
void destroy_list_node(ListNode node);

/**
 * @brief      Destroy a list of List Nodes.
 *
 * @param[in]  node  The first List Node.
 */
void destroy_list_node_recursive(ListNode node);

/**
 * @brief      Search a node in a list of List Nodes.
 *
 * @param      node        The first List Node.
 * @param      key         The key.
 * @param[in]  compareKey  The function to compare keyes.
 *
 * @return     @c NULL if the key does not exists. The pointer to the List Node otherwise.
 */
ListNode* list_node_reach(ListNode* node, void* key, CompareFunction compareKey);

//@ todo commenti
ListNode* list_node_find_position(ListNode* node, void* key, CompareFunction compareKey);

/**
 * @brief      Delete a node from a list of List Nodes.
 *
 * @param      node  The List Node.
 *
 * @return     @ NULL if @c node is @c NULL. The value of the List Node
 *             otherwise.
 */
void* list_node_remove(ListNode* node);

#endif