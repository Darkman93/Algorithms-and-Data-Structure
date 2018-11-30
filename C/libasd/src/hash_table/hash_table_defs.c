#include "hash_table_defs.h"
#include "hash_table.h"
#include "hash_table_debug.h"
#include "../list_map/list_map_iterator.h"

//extern inline void hash_table_allocated(HashTable htable);
//bool size_t_overflowed(size_t base, size_t result);

ListMap* new_collision_list_table(size_t capacity)
{
  ListMap* table = (ListMap*) calloc(capacity, sizeof(ListMap));
  if (!table) error(EXIT_FAILURE, 0, "Malloc error in function %s", __func__);
  return table;
}

void destroy_collision_list_table(ListMap* table, size_t capacity)
{
  for (size_t i=0; i < capacity; ++i)
    if (table[i]) destroy_list_map(&table[i]);
  free(*table);
  *table = NULL;
}

size_t hash_table_index_of(HashTable htable, void* key)
{
  return key ? htable->hash(key) % htable->capacity : HASH_TABLE_NULL_INDEX;
}

// @todo questa funzione non mi convince RIVEDERE
// 'hash_table_index_of' viene ripetuto anche anche dal chiamante
void* hash_table_add(HashTable htable, void* key, void* value)
{
  size_t index = hash_table_index_of(htable, key);
  if (!htable->table[index]) htable->table[index] = new_list_map(htable->compareKey);
  return list_map_put(htable->table[index], key, value);
}

void hash_table_check_and_resize(HashTable htable)
{
  size_t newCapacity = 0;
  float  loadFactor  = (float) htable->size / htable->capacity;
  float resizeFactor = (float) 1 / htable->loadFactorTreshold;

  if (htable->size < HASH_TABLE_MAX_CAPACITY && loadFactor > htable->loadFactorTreshold)
  {
    newCapacity = htable->capacity * htable->loadFactorTreshold;
    if(newCapacity < htable->capacity) newCapacity = HASH_TABLE_MAX_CAPACITY;
    //if (size_t_overflowed(htable->capacity, newCapacity)) newCapacity = HASH_TABLE_MAX_CAPACITY;
  }
  else if ((htable->capacity * resizeFactor) > htable->initialCapacity && loadFactor < resizeFactor)
  {
    newCapacity = htable->capacity * resizeFactor;
  }

  if (newCapacity > 0)
  {
    hash_table_resize(htable, newCapacity);
    //hash_table_size_vs_capacity(htable); // DEBUG per visualizzare le riallocazioni
  }
}

void hash_table_resize(HashTable htable, size_t newCapacity)
{
  void *key, *value;

  //Keep track of the old table dimensions
  size_t   oldCapacity = htable->capacity;
  ListMap* oldTable    = htable->table;

  //Upgrade the table dimensions
  htable->capacity = newCapacity;
  htable->table    = new_collision_list_table(newCapacity);

  //Re-insert all the nodes
  // @todo cambiare questo codice usando direttamente HashTableIterator
  for(size_t i=0; i < oldCapacity; ++i)
  {
    if (oldTable[i])
    {
      ListMap*   collisionList = &oldTable[i];
      ListMapIterator iterator = new_list_map_iterator(*collisionList);
      list_map_iterator_next(iterator);
      while (!list_map_is_empty(*collisionList))
      {
        key   = list_map_iterator_current_key(iterator);
        value = list_map_iterator_current_value(iterator);
        list_map_iterator_remove(iterator);
        hash_table_add(htable, key, value);
      }
      destroy_list_map_iterator(&iterator);
      destroy_list_map(collisionList);
    }
  }
  destroy_collision_list_table(oldTable, oldCapacity);
  //*/

  // @todo check sulla nuova capacità
  /*
  // questo metodo non si può usare perché vanno ricalcolati gli hash
  size_t capacityBytes = newCapacity * sizeof(ListMap*);
  htable->capacity = newCapacity;
  htable->table    = realloc(htable->table, capacityBytes);
  if (!htable->table) {
    printf("hash_table_resize: impossible reallocate hash_table collisionList\n");
    exit(EXIT_FAILURE);
  }
  */
}

/*
bool size_t_overflowed(size_t base, size_t result)
{
  return base > result;
}
*/