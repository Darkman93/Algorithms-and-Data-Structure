#include "dictionary_hash_table_adapter.h"
#include "../../hash_table/hash_table.h"
#include "../dictionary_defs.h"

DictionaryVTable new_dictionary_hash_table_vtable()
{
  DictionaryVTable vtable = (DictionaryVTable) malloc(sizeof(struct dictionary_vtable));
  if (!vtable) {
    printf("Impossible allocate dictionary_vtable\n");
    exit(EXIT_FAILURE);
  }

  vtable->destroy  = destroy_dictionary_hash_table;
  vtable->get      = dictionary_hash_table_get;
  vtable->is_empty = dictionary_hash_table_is_empty;
  vtable->put      = dictionary_hash_table_put;
  vtable->remove   = dictionary_hash_table_remove;
  vtable->size     = dictionary_hash_table_size;
  return vtable;
}

void destroy_dictionary_hash_table(void* htable)
{
  destroy_hash_table((HashTable*) htable);
}

void* dictionary_hash_table_get(void* htable, void* key)
{
  return hash_table_get((HashTable) htable, key);
}

bool dictionary_hash_table_is_empty(void* htable)
{
  return hash_table_is_empty((HashTable) htable);
}

void* dictionary_hash_table_put(void* htable, void* key, void* value)
{
  return hash_table_put((HashTable) htable, key, value);
}

void* dictionary_hash_table_remove(void* htable, void* key)
{
  return hash_table_remove((HashTable) htable, key);
}

size_t dictionary_hash_table_size(void* htable)
{
  return hash_table_size((HashTable) htable);
}
