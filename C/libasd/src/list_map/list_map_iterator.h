#ifndef __LIST_MAP_ITERATOR_H__
#define __LIST_MAP_ITERATOR_H__

#include "list_map.h"
#include "../standard_libraries.h"

/*
 * Types
 */

typedef struct list_map_iterator* ListMapIterator;

/*
 * Functions
 */

/**
 * @brief      Create a new iterator for a list-map.
 *
 * @param[in]  listMap  The list-map.
 *
 * @return     The new iterator.
 */
ListMapIterator new_list_map_iterator(ListMap listMap);


/**
 * @brief      Destroy a List-Map Iterator.
 *
 * @param[in]  iterator  The List-Map Iterator.
 */
void destroy_list_map_iterator(ListMapIterator* iterator);

/**
 * @brief      Gets the key of the current node.
 *
 * @param[in]  iterator  The list-map iterator.
 *
 * @return     The key of the current node.
 */
void* list_map_iterator_current_key(ListMapIterator iterator);

/**
 * @brief      Gets the value of the current node.
 *
 * @param[in]  iterator  The list-map iterator.
 *
 * @return     The value of the current node.
 */
void* list_map_iterator_current_value(ListMapIterator iterator);

/**
 * @brief      Check if the iterator may advance.
 *
 * @param[in]  iterator  The list-map iterator.
 *
 * @return     @c true if the iterator may advance. @c false otherwise.
 */
bool list_map_iterator_has_next(ListMapIterator iterator);

/**
 * @brief      Advances the interator position.
 *
 * @param[in]  iterator  The list-map iterator.
 *
 * @return     @c true if the iterator advances. @c false otherwise.
 */
bool list_map_iterator_next(ListMapIterator iterator);

/**
 * @brief      Remove the current node.
 *
 * @param[in]  iterator  The list-map iterator.
 *
 * @return     The value of th node.
 */
void* list_map_iterator_remove(ListMapIterator iterator);

/**
 * @brief      Reinitialize the iterator with the head of the list.
 *
 * @param[in]  iterator  The list-map iterator.
 */
void list_map_iterator_reset(ListMapIterator iterator);

#endif