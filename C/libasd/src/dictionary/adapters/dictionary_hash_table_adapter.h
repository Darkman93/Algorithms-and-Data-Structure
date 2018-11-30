#ifndef __DICTIONARY_HASH_TABLE_ADAPTER_H__
#define __DICTIONARY_HASH_TABLE_ADAPTER_H__

#include "../../standard_libraries.h"
#include "../dictionary_defs.h"

/**
 * @brief      Create new DisctionaryVTable
 *
 * @return     The new DictionaryVTable
 */
DictionaryVTable new_dictionary_hash_table_vtable();

/**
 * @brief      Destroy the structure Dictionary
 *
 * @param      htable  The htable
 */
void  destroy_dictionary_hash_table(void* htable);

/**
 * @brief      Get function for a certain value with corrispondent key
 *
 * @param      htable  The htable
 * @param      key     The key
 *
 * @return     the @c void* value
 */
void*  dictionary_hash_table_get(void* htable, void* key);

/**
 * @brief      Control if the Dictionary is empty
 *
 * @param      htable  The htable
 *
 * @return     @c true if is empty or @c false if isn't
 */
bool   dictionary_hash_table_is_empty(void* htable);

/**
 * @brief      Put an element into the Dictionary with the corrispondent key and replaced the element if already exsist
 *
 * @param      htable  The htable
 * @param      key     The key
 * @param      value   The value
 *
 * @return     @c void* of element replaced
 */
void*  dictionary_hash_table_put(void* htable, void* key, void* value);

/**
 * @brief      Remove an element from the Dictionary with the corrispondent key
 *
 *
 * @param      htable  The htable
 * @param      key     The key
 *
 * @return     @c void* of the element elimated from Dictionary
 */
void*  dictionary_hash_table_remove(void* htable, void* key);

/**
 * @brief      Count how many elements have the Dictionary
 *
 * @param      htable  The htable
 *
 * @return     @c size_t of the Dictionary
 */
size_t dictionary_hash_table_size(void* htable);

#endif
