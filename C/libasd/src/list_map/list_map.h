#ifndef __LIST_MAP_H__
#define __LIST_MAP_H__

#include "../standard_libraries.h"
#include "../function_types.h"

/**
 * @todo scrivere un invariante di 'classe'
 *       specificando in particolare che non sono ammessi elementi ripetuti
 *       e che l'inserimento avviene in maniera ordinata
 *
 */
typedef struct list_map* ListMap;

/**
 * @brief      Creates an empty list-map.
 *
 * @param[in]  compare  The function to compare two keys.
 *
 * @return     The new list-map.
 */
ListMap new_list_map(CompareFunction compare);

/**
 * @brief      Destroy a List-Map
 *
 * @param[in]  list  The List-Map.
 */
void destroy_list_map(ListMap* list);

// @todo e' necessaria ???
// ris. UTILE, MA NON STRETTAMENTE NECESSARIA (IN QUESTO PROGETTO VIENE USATA PRINCIPALMENTE NEI TEST)
bool list_map_contains_key(ListMap listMap, void* key);

/**
 * @brief      Search a node in the list.
 *
 * @param[in]  listMap  The list-map.
 * @param[in]  key      The key.
 *
 * @return     The value of the node if a node with the specified key is in the
 *             list. @c NULL otherwise.
 */
void* list_map_get(ListMap listMap, void* key);

/**
 * @brief      Check if the list is empty.
 *
 * @param[in]  listMap  The list-map.
 *
 * @return     @c true if the list is empty. @c false otherwise.
 */
bool list_map_is_empty(ListMap listMap);

/**
 * @brief      Insert a key-value node in the list, or replace the value of an
 *             existing one.
 *
 * @todo dire due paroline sull'inserimento ordinato
 *
 * @param[in]  listMap  The list-map.
 * @param[in]  key      The key.
 * @param[in]  value    The value.
 *
 * @return     The old value of the node if a node with the specified key is
 *             already in the list. @c NULL otherwise.
 */
void* list_map_put(ListMap listMap, void* key, void* value);

/**
 * @brief      Deletes a node in the list.
 *
 * @param[in]  listMap  The list-map.
 * @param[in]  key      The key of the node to be deleted.
 *
 * @return     The value of the node if a node with the specified key is in the
 *             list. @c NULL otherwise.
 */
void* list_map_remove(ListMap listMap, void* key);

/**
 * @brief      Gets the size of a list-map.
 *
 * @param[in]  listMap  The list-map.
 *
 * @return     The size of the list-map.
 */
size_t list_map_size(ListMap listMap);

#endif