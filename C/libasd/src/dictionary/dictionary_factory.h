#ifndef __DICTIONARY_FACTORY_H__
#define __DICTIONARY_FACTORY_H__

#include "../function_types.h"
#include "../utils/hashes.h"
#include "dictionary.h"

// @todo commenti

/**
 *
 * @return dictionary implementaed with binary tree
 */
Dictionary create_dictionary_binary_tree(CompareFunction compareKey);

/**
 *
 * @return dictionary implementaed with hash table
 */
Dictionary create_dictionary_hash_table(CompareFunction compareKey, HashFunction hash);

/**
 *
 * @return dictionary implementaed with hash table
 */
Dictionary create_dictionary_hash_table_customized(size_t initialCapacity, float loadFactorTreshold, CompareFunction compareKey, HashFunction hash);

#endif
