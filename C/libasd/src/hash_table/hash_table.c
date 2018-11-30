#include "hash_table.h"
#include "hash_table_defs.h"
#include "hash_table_debug.h"
#include "../list_map/list_map.h"

HashTable new_hash_table(size_t initialCapacity, float loadFactorTreshold, CompareFunction compareKey, HashFunction hash)
{
  if(!compareKey || !hash || initialCapacity < 1 || loadFactorTreshold < 1) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);

  HashTable htable = (HashTable) malloc(sizeof(struct hash_table));
  if (!htable) error(EXIT_FAILURE, 0, "Malloc error in function %s", __func__);

  htable->compareKey = compareKey;
  htable->hash       = hash;

  htable->initialCapacity    = initialCapacity;
  htable->loadFactorTreshold = loadFactorTreshold;

  htable->capacity = initialCapacity;
  htable->size     = 0;
  htable->table    = new_collision_list_table(initialCapacity);
  return htable;
}

void destroy_hash_table(HashTable* htable)
{
  if (!*htable) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  destroy_collision_list_table((*htable)->table, (*htable)->capacity);
  free(*htable);
  *htable = NULL;
}

bool hash_table_contains_key(HashTable htable, void* key)
{
  if (!htable || !key) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  size_t index = hash_table_index_of(htable, key);
  return index != HASH_TABLE_NULL_INDEX && htable->table[index] ? list_map_contains_key(htable->table[index], key) : false;
}

void* hash_table_get(HashTable htable, void* key)
{
  if (!htable || !key) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  size_t index = hash_table_index_of(htable, key);
  return index != HASH_TABLE_NULL_INDEX && htable->table[index] ? list_map_get(htable->table[index], key) : NULL;
}

bool hash_table_is_empty(HashTable htable)
{
  if (!htable) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  return !(htable->size);
}

void* hash_table_put(HashTable htable, void* key, void* value)
{
  if (!htable || !key) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  void* replaced = hash_table_add(htable, key, value);
  if (!replaced)
  {
    ++(htable->size);
    hash_table_check_and_resize(htable);
    //hash_table_collion_list_statistics(htable); // DEBUG
  }
  return replaced;
}

void* hash_table_remove(HashTable htable, void* key)
{
  if (!htable || !key) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  void*  value = NULL;
  size_t index = hash_table_index_of(htable, key);
  if (index != HASH_TABLE_NULL_INDEX && htable->table[index])
  {
    value = list_map_remove(htable->table[index], key);

    if (list_map_is_empty(htable->table[index]))
      destroy_list_map(&htable->table[index]);

    if (value)
    {
      --(htable->size);
      hash_table_check_and_resize(htable);
    }
  }
  return value;
}

size_t hash_table_size(HashTable htable)
{
  if (!htable) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  return htable->size;
}