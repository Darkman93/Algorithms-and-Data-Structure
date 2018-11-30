#ifndef __DICTIONARY_DEFS_H__
#define __DICTIONARY_DEFS_H__

#include "../standard_libraries.h"
#include "dictionary.h"

typedef struct dictionary_vtable* DictionaryVTable;

typedef void*  (*DictionaryGetFunction)     (void* dictionary, void* key);
typedef bool   (*DictionaryIsEmptyFunction) (void* dictionary);
typedef void*  (*DictionaryPutFunction)     (void* dictionary, void* key, void* value);
typedef void*  (*DictionaryRemoveFunction)  (void* dictionary, void* key);
typedef size_t (*DictionarySizeFunction)    (void* dictionary);
typedef void   (*DictionaryDestroyFunction) (void* dictionary);

struct dictionary
{
  void*            implementation;
  DictionaryVTable vtable;
};

struct dictionary_vtable
{
  DictionaryGetFunction     get;
  DictionaryIsEmptyFunction is_empty;
  DictionaryPutFunction     put;
  DictionaryRemoveFunction  remove;
  DictionarySizeFunction    size;
  DictionaryDestroyFunction destroy;
};

Dictionary new_dictionary(void* implementation, DictionaryVTable vtable);

#endif
