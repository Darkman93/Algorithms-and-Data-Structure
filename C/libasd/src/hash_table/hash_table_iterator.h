#ifndef __HASH_TABLE_ITERATOR_H__
#define __HASH_TABLE_ITERATOR_H__

#include "hash_table.h"
#include "../standard_libraries.h"

/*
 * Types
 */

typedef struct hash_table_iterator* HashTableIterator;

/*
 * Functions
 */

/**
 * @brief      Create a new iterator of the HasTable
 *
 * @param[in]  htable  The htable
 *
 * @return     The iterator
 */
HashTableIterator new_hash_table_iterator(HashTable htable);


/**
 * @brief      Destroy the structure iterator
 *
 * @param      iterator  The iterator
 */
void destroy_hash_table_iterator(HashTableIterator* iterator);


/**
 * @brief      If iterator exsist return the key
 *
 * @param[in]  iterator  The iterator
 *
 * @return     the @c void* of the key or NULL
 */
void* hash_table_iterator_current_key(HashTableIterator iterator);


/**
 * @brief      If iterator exsist return the value
 *
 * @param[in]  iterator  The iterator
 *
 * @return     the @c void* of the value or NULL
 */
void* hash_table_iterator_current_value(HashTableIterator iterator);


/**
 * @brief      Control if HashTable have a alement to the next position
 *
 * @param[in]  iterator  The iterator
 *
 * @return     @c false if the next is NULL or @c true otherwise
 */
bool hash_table_iterator_has_next(HashTableIterator iterator);


/**
 * @brief      Move the iteratore to the next element
 *
 * @param[in]  iterator  The iterator
 *
 * @return     @c true if the capacity of the HashTable isn't full or @c false otherwise
 */
bool hash_table_iterator_next(HashTableIterator iterator);

/**
 * @brief      Reinitialize the iterator
 *
 * @param[in]  iterator  The iterator
 */
void hash_table_iterator_reset(HashTableIterator iterator);

#endif