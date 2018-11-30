#include "hash_table_iterator.h"
#include "hash_table_defs.h"
#include "../unsigned_types.h"
#include "../list_map/list_map_iterator.h"

#define HASH_TABLE_LEFT_ZERO SIZE_T_LEFT_ZERO

/*
 * Data Structures
 */

struct hash_table_iterator
{
  HashTable htable;             // The Hash Table.
  size_t index;                 // The index of the current collision list.
  ListMapIterator listIterator; // The List Iterator of the current collision list.
};

/*
 * Functions
 */

HashTableIterator new_hash_table_iterator(HashTable htable)
{
  if (!htable) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  HashTableIterator iterator = (HashTableIterator) malloc(sizeof(struct hash_table_iterator));
  if (!iterator) error(EXIT_FAILURE, 0, "Malloc error in function %s", __func__);
  iterator->htable       = htable;
  iterator->index        = HASH_TABLE_LEFT_ZERO;
  iterator->listIterator = NULL;
  return iterator;
}

void destroy_hash_table_iterator(HashTableIterator* iterator)
{
  if (!*iterator) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  destroy_list_map_iterator(&(*iterator)->listIterator);
  free(*iterator);
  *iterator = NULL;
}

bool hash_table_iterator_has_next(HashTableIterator iterator)
{
  if (!iterator) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  if (!iterator->htable) return false;
  if (iterator->listIterator && list_map_iterator_has_next(iterator->listIterator)) return true;
  size_t nextIndex = iterator->index + 1;
  while (nextIndex < iterator->htable->capacity && !iterator->htable->table[nextIndex]) ++nextIndex;
  return nextIndex < iterator->htable->capacity;
}

void* hash_table_iterator_current_key(HashTableIterator iterator)
{
  if (!iterator) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  if (!iterator->htable) return NULL;
  return iterator->listIterator ? list_map_iterator_current_key(iterator->listIterator) : NULL;
}

void* hash_table_iterator_current_value(HashTableIterator iterator)
{
  if (!iterator) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  if (!iterator->htable) return NULL;
  return iterator->listIterator ? list_map_iterator_current_value(iterator->listIterator) : NULL;
}

bool hash_table_iterator_next(HashTableIterator iterator)
{
  if (!iterator) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  if (!iterator->htable) return false;
  if (iterator->listIterator && list_map_iterator_next(iterator->listIterator)) return true;
  size_t nextIndex = iterator->index + 1;
  while (nextIndex < iterator->htable->capacity && !iterator->htable->table[nextIndex]) ++nextIndex;
  if (nextIndex < iterator->htable->capacity)
  {
    destroy_list_map_iterator(&iterator->listIterator);
    iterator->listIterator = new_list_map_iterator(iterator->htable->table[nextIndex]);
    list_map_iterator_next(iterator->listIterator);
    iterator->index = nextIndex;
    return true;
  }
  return false;
}

void hash_table_iterator_reset(HashTableIterator iterator)
{
  if (!iterator) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  iterator->index = HASH_TABLE_LEFT_ZERO;
  destroy_list_map_iterator(&iterator->listIterator);
}
