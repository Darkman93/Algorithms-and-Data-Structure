#include "hash_table_factory.h"

HashTable create_hash_table(CompareFunction compareKey, HashFunction hash)
{
  return new_hash_table(HASH_TABLE_INITIAL_CAPACITY, HASH_TABLE_LOAD_FACTOR_TRESHOLD, compareKey, hash);
}

HashTable create_hash_table_customized(size_t initialCapacity, float loadFactorTreshold, CompareFunction compareKey, HashFunction hash)
{
  // @todo asserts on initialCapacity and loadFactorTreshold
  // initialCapacity > 1
  // loadFactorTreshold >= 1
  /*
  if (initialCapacity < PRIORITY_QUEUE_MIN_CAPACITY && initialCapacity > PRIORITY_QUEUE_MAX_CAPACITY)
  {
    printf("Impossible create hash table: wrong initial capacity\n");
    exit(EXIT_FAILURE);
  }
  */

  return new_hash_table(initialCapacity, loadFactorTreshold, compareKey, hash);
}
