#include "list_node.h"
#include "list_map_defs.h"
#include "list_map.h"

ListMap new_list_map(CompareFunction compareKey)
{
  if (!compareKey) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  ListMap list = (ListMap) malloc(sizeof(struct list_map));
  if (!list) error(EXIT_FAILURE, 0, "Malloc error in function %s", __func__);
  list->compareKey = compareKey;
  list->size       = 0;
  list->head       = NULL;
  return list;
}

void destroy_list_map(ListMap* list)
{
  if (!*list) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  destroy_list_node_recursive((*list)->head);
  free(*list);
  *list = NULL;
}

bool list_map_contains_key(ListMap list, void* key)
{
  if (!list || !key) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  ListNode* node = list_node_reach(&(list->head), key, list->compareKey);
  return *node != NULL;
}

void* list_map_get(ListMap list, void* key)
{
  if (!list || !key) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  ListNode* node = list_node_reach(&(list->head), key, list->compareKey);
  return *node ? (*node)->value : NULL;
}

bool list_map_is_empty(ListMap list)
{
  if (!list) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  return !list->head;
}

// @todo scrivere due righe sul perché facciamo l'inserimento ordinato (migliore dell'inserimento in coda)
//       e non il canonico inserimento in testa (ricorda: non ci possono elementi ripetuti)
void* list_map_put(ListMap list, void* key, void* value)
{
  if (!list || !key) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  void* replaced = NULL;
  ListNode* node = list_node_find_position(&(list->head), key, list->compareKey);

  if (!*node || list->compareKey(key, (*node)->key) < 0)
  {
    ListNode next = NULL;
    if (*node) next = *node;
    *node = new_list_node(key, value, next);
    ++(list->size);
  }
  else
  {
    replaced = (*node)->value;
    (*node)->value = value;
  }
  return replaced;
}

void* list_map_remove(ListMap list, void* key)
{
  if (!list || !key) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  ListNode* node = list_node_find_position(&(list->head), key, list->compareKey);
  void* value = list_node_remove(node);
  if (value) --(list->size);
  return value;
}

size_t list_map_size(ListMap list)
{
  if (!list) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  return list->size;
}
