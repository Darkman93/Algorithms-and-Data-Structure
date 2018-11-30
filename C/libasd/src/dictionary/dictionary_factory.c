#include "dictionary_factory.h"
#include "dictionary_defs.h"
#include "adapters/dictionary_binary_tree_adapter.h"
#include "adapters/dictionary_hash_table_adapter.h"
#include "../utils/comparators.h"
#include "../utils/hashes.h"
#include "../binary_tree/binary_tree.h"
#include "../hash_table/hash_table.h"
#include "../hash_table/hash_table_factory.h"


// @todo commenti

Dictionary create_dictionary_binary_tree(CompareFunction compareKey)
{
  BinaryTree       tree   = new_binary_tree(compareKey);
  DictionaryVTable vtable = new_dictionary_binary_tree_vtable();
  return new_dictionary(tree, vtable);
}

Dictionary create_dictionary_hash_table(CompareFunction compareKey, HashFunction hash)
{
  HashTable        htable = create_hash_table(compareKey, hash);
  DictionaryVTable vtable = new_dictionary_hash_table_vtable();
  return new_dictionary(htable, vtable);
}

Dictionary create_dictionary_hash_table_customized(size_t initialCapacity, float loadFactorTreshold, CompareFunction compareKey, HashFunction hash)
{
  HashTable        htable = create_hash_table_customized(initialCapacity, loadFactorTreshold, compareKey, hash);
  DictionaryVTable vtable = new_dictionary_hash_table_vtable();
  return new_dictionary(htable, vtable);
}
