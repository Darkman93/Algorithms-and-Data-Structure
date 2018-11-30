#include "dictionary.h"
#include "dictionary_defs.h"

Dictionary new_dictionary(void* implementation, DictionaryVTable vtable)
{
  Dictionary dictionary = (Dictionary) malloc(sizeof(struct dictionary));
  if (!dictionary) {
    printf("Impossible allocate dictionary\n");
    exit(EXIT_FAILURE);
  }

  dictionary->implementation = implementation;
  dictionary->vtable         = vtable;
  return dictionary;
}

void destroy_dictionary(Dictionary* dictionary)
{
  (*dictionary)->vtable->destroy(&((*dictionary)->implementation));
  free(*dictionary);
  *dictionary = NULL;
}

void* dictionary_get(Dictionary dictionary, void* key)
{
  return dictionary->vtable->get(dictionary->implementation, key);
}

bool dictionary_is_empty(Dictionary dictionary)
{
  return dictionary->vtable->is_empty(dictionary->implementation);
}

void* dictionary_put(Dictionary dictionary, void* key, void* value)
{
  return dictionary->vtable->put(dictionary->implementation, key, value);
}

void* dictionary_remove(Dictionary dictionary, void* key)
{
  return dictionary->vtable->remove(dictionary->implementation, key);
}

size_t dictionary_size(Dictionary dictionary)
{
  return dictionary->vtable->size(dictionary->implementation);
}
