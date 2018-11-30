#ifndef __HASH_TABLE_FACTORY_H__
#define __HASH_TABLE_FACTORY_H__

#include "hash_table.h"
#include "../function_types.h"
#include "../standard_libraries.h"

/**
 * @brief      Creates an Hash Table with default initial capacity and
 *             load-factor treshold.
 *
 * @param[in]  compareKey  The function to compare keys.
 * @param[in]  hash         The hash function.
 *
 * @return     The new Hash Table.
 */
HashTable create_hash_table(CompareFunction compareKey, HashFunction hash);

/**
 * @brief      Creates an Hash Table.
 *
 * @param[in]  initialCapacity     The initial capacity.
 * @param[in]  loadFactorTreshold  The load-factor treshold.
 * @param[in]  compareKey         The function to compare keyes.
 * @param[in]  hash                The hash function.
 *
 * @return     The new Hash Table.
 */
HashTable create_hash_table_customized(size_t initialCapacity, float loadFactorTreshold, CompareFunction compareKey, HashFunction hash);

#endif
