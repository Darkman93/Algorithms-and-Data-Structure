#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

#include "../standard_libraries.h"
#include "../function_types.h"

#define HASH_TABLE_INITIAL_CAPACITY     8
#define HASH_TABLE_LOAD_FACTOR_TRESHOLD 5

//
// Types
//

typedef struct hash_table* HashTable;

//
// Functions
//

/**
 * @brief      Create a new HashTable
 *
 * @param[in]  initialCapacity     The initial capacity
 * @param[in]  loadFactorTreshold  The load factor treshold
 * @param[in]  compareKey          The compare key
 * @param[in]  hash                The hash
 *
 * @return     the new HashTable
 */
HashTable new_hash_table(size_t initialCapacity, float loadFactorTreshold, CompareFunction compareKey, HashFunction hash);


/**
 * @brief      Destroy the HashTable
 *
 * @param[in]  htable  The htable
 */
void destroy_hash_table(HashTable* htable);

/**
 * @brief      Search the key into the HashTable
 *
 * @param[in]  htable  The htable
 * @param[in]  key     The key
 *
 * @return     @c true if the key exsist or @c false if doesn't exsist
 */
bool   hash_table_contains_key(HashTable htable, void* key);

/**
 * @brief      Get the element with the key on input
 *
 * @param[in]  htable  The htable
 * @param[in]  key     The key
 *
 * @return     @c void* element into the HashTable with have the corrispondent
 *             key
 */
void*  hash_table_get(HashTable htable, void* key);

/**
 * @brief      Control if the HashTable is empty
 *
 * @param[in]  htable  The htable
 *
 * @return     @c true if is empty or @c false if isn't empty
 */
bool   hash_table_is_empty(HashTable htable);

/**
 * @brief      Put an element into the HashTable with the corrispondent key and
 *             replaced the element if already exsist
 *
 * @param[in]  htable  The htable
 * @param[in]  key     The key
 * @param[in]  value   The value
 *
 * @return     @c void* of element replaced
 */
void*  hash_table_put(HashTable htable, void* key, void* value);

/**
 * @brief      Remove an element from the HashTable with the corrispondent key
 *
 * @param[in]  htable  The htable
 * @param[in]  key     The key
 *
 * @return     @c void* of the element elimated from HashTable
 */
void*  hash_table_remove(HashTable htable, void* key);

/**
 * @brief      Count how many elements have the HashTable
 *
 * @param[in]  htable  The htable
 *
 * @return     @c size_t of the HashTable
 */
size_t hash_table_size(HashTable htable);

#endif
