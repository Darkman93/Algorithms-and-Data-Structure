#ifndef __HASH_TABLE_DEBUG_H__
#define __HASH_TABLE_DEBUG_H__

#include "hash_table.h"
#include "../standard_libraries.h"

/**
 * @brief      How many elements have the HashTable
 *
 * @param[in]  htable  The htable
 *
 * @return     @c size_t of HashTable
 */
size_t hash_table_get_capacity(HashTable htable);

/**
 * @brief      Count every single element into the HashTable
 *
 * @param[in]  htable  The htable
 *
 * @return     @c size_t of all elements that HashTable contains
 */
size_t hash_table_count(HashTable htable);

/**
 * @brief      The copy of the hash table
 *
 * @param[in]  htable  The htable
 */
void hash_table_dump(HashTable htable);

/**
 * @brief      The copy of the hash table
 *
 * @param[in]  htable  The htable
 */
void hash_table_size_vs_capacity(HashTable htable);

/**
 * @brief      The copy of the hash table
 *
 * @param[in]  htable  The htable
 */
void hash_table_collion_list_statistics(HashTable htable);

#endif
