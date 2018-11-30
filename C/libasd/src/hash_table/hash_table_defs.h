#ifndef __HASH_TABLE_DEFS_H__
#define __HASH_TABLE_DEFS_H__

#include "hash_table.h"
#include "../standard_libraries.h"
#include "../function_types.h"
#include "../unsigned_types.h"
#include "../list_map/list_map.h"

#define HASH_TABLE_NULL_INDEX    SIZE_T_NULL
#define HASH_TABLE_MAX_CAPACITY (SIZE_T_MAX_VALUE - 1)

//
// Data Structures
//

struct hash_table
{
  CompareFunction compareKey;  // The function to compare keyes.
  HashFunction    hash;        // The hash function.
  size_t   initialCapacity;    // The initial capacity.
  float    loadFactorTreshold; // The resize treshold expressend as load factor.
  size_t   capacity;           // The capacity of the table.
  size_t   size;               // The nmber of elements.
  ListMap* table;              // The table.
};

/*
inline void hash_table_allocated(HashTable htable)
{
  if (!htable) {
    printf("The hash table not allocated\n");
    exit(EXIT_FAILURE);
  }
}
*/

//
// Functions
//

/**
 * @brief      Create a collision list of ListMap type
 *
 * @param[in]  capacity  The capacity
 *
 * @return     the pointer to the new @c ListMap
 */
ListMap* new_collision_list_table(size_t capacity);

/**
 * @brief      Destroy the ListMap structure
 *
 * @param      table     The table
 * @param[in]  capacity  The capacity
 */
void destroy_collision_list_table(ListMap* table, size_t capacity);

/**
 * @brief      If the key exsist find the exact index position
 *
 * @param[in]  htable  The htable
 * @param      key     The key
 *
 * @return     @c size_t of the index corrispondent to the key
 */
size_t hash_table_index_of(HashTable htable, void* key);

/**
 * @brief      Add an element into the HashTable with corrispondent key
 *
 * @param[in]  htable  The htable
 * @param      key     The key
 * @param      value   The value
 *
 * @return     the element replaced
 */
void* hash_table_add(HashTable htable, void* key, void* value);

/**
 * @brief      Check the capacity of the HashTable and if necessarry resize
 *
 * @param[in]  htable  The htable
 */
void hash_table_check_and_resize(HashTable htable);

/**
 * @brief      Resize the capacity of the HashTable
 *
 * @param[in]  htable       The htable
 * @param[in]  newCapacity  The new capacity
 */
void hash_table_resize(HashTable htable, size_t newCapacity);

#endif
