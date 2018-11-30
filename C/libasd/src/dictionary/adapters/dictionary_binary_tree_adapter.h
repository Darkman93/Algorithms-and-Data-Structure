#ifndef __DICTIONARY_BINARY_TREE_ADAPTER_H__
#define __DICTIONARY_BINARY_TREE_ADAPTER_H__

#include "../../standard_libraries.h"
#include "../dictionary_defs.h"

/**
 * @brief      Create new DisctionaryVTable
 *
 * @return     The new DictionaryVTable
 */
DictionaryVTable new_dictionary_binary_tree_vtable();

/**
 * @brief      Destroy the structure Dictionary
 *
 * @param      tree  The tree
 */
void destroy_dictionary_binary_tree(void* tree);

/**
 * @brief      Get function for a certain value with corrispondent key
 *
 * @param      tree  The tree
 * @param      key   The key
 *
 * @return     the @c void* value
 */
void* dictionary_binary_tree_get(void* tree, void* key);

/**
 * @brief      Control if the Dictionary is empty
 *
 * @param      tree  The tree
 *
 * @return     @c true if is empty or @c false if isn't
 */
bool dictionary_binary_tree_is_empty(void* tree);

/**
 * @brief      Put an element into the Dictionary with the corrispondent key and replaced the element if already exsist
 *
 * @param      tree   The tree
 * @param      key    The key
 * @param      value  The value
 *
 * @return     @c void* of element replaced
 */
void* dictionary_binary_tree_put(void* tree, void* key, void* value);

/**
 * @brief      Remove an element from the Dictionary with the corrispondent key
 *
 * @param      tree  The tree
 * @param      key   The key
 *
 * @return     @c void* of the element elimated from Dictionary
 */
void* dictionary_binary_tree_remove(void* tree, void* key);

/**
 * @brief      Count how many elements have the Dictionary
 *
 * @param      tree  The tree
 *
 * @return     @c size_t of the Dictionary
 */
size_t dictionary_binary_tree_size(void* tree);

#endif
