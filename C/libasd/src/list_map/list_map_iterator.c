#include "list_map_iterator.h"
#include "list_map.h"
#include "list_node.h"
#include "list_map_defs.h"

/*
 * Data Strctures
 */

struct list_map_iterator
{
  ListMap   list;    // The List Map.
  ListNode* current; // The pointer to the current node.
};

/*
 * Functions
 */

ListMapIterator new_list_map_iterator(ListMap list)
{
  ListMapIterator iterator = (ListMapIterator) malloc(sizeof(struct list_map_iterator));
  if (!iterator) error(EXIT_FAILURE, 0, "Malloc error in function %s", __func__);
  iterator->list    = list;
  iterator->current = NULL;
  return iterator;
}

void destroy_list_map_iterator(ListMapIterator* iterator)
{
  free(*iterator);
  *iterator = NULL;
}

void* list_map_iterator_current_key(ListMapIterator iterator)
{
  if (!iterator) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  ListNode current = iterator->current ? *iterator->current : NULL;
  return current ? current->key : NULL;
}

void* list_map_iterator_current_value(ListMapIterator iterator)
{
  if (!iterator) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  ListNode current = iterator->current ? *iterator->current : NULL;
  return current ? current->value : NULL;
}

bool list_map_iterator_has_next(ListMapIterator iterator)
{
  if (!iterator) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  return iterator->current ? (*iterator->current)->next != NULL : iterator->list->head != NULL;
}

bool list_map_iterator_next(ListMapIterator iterator)
{
  if (!iterator) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  if(list_map_iterator_has_next(iterator))
  {
    iterator->current = iterator->current ? &(*iterator->current)->next : &iterator->list->head;
    return true;
  }
  return false;
}

void* list_map_iterator_remove(ListMapIterator iterator)
{
  if (!iterator) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  void* value = iterator->current ? list_node_remove(iterator->current) : NULL;
  if (value) --iterator->list->size;
  return value;
}

void list_map_iterator_reset(ListMapIterator iterator)
{
  if (!iterator) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  iterator->current = NULL;
}