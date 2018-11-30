#include "dictionary_binary_tree_adapter.h"
#include "../../binary_tree/binary_tree.h"
#include "../dictionary_defs.h"

DictionaryVTable new_dictionary_binary_tree_vtable()
{
  DictionaryVTable vtable = (DictionaryVTable) malloc(sizeof(struct dictionary_vtable));
  if (!vtable) {
    printf("Impossible allocate dictionary_vtable\n");
    exit(EXIT_FAILURE);
  }

  vtable->destroy  = destroy_dictionary_binary_tree;
  vtable->get      = dictionary_binary_tree_get;
  vtable->is_empty = dictionary_binary_tree_is_empty;
  vtable->put      = dictionary_binary_tree_put;
  vtable->remove   = dictionary_binary_tree_remove;
  vtable->size     = dictionary_binary_tree_size;
  return vtable;
}

void destroy_dictionary_binary_tree(void* tree)
{
  destroy_binary_tree((BinaryTree*) tree);
}


void* dictionary_binary_tree_get(void* tree, void* key)
{
  return binary_tree_get((BinaryTree) tree, key);
}

bool dictionary_binary_tree_is_empty(void* tree)
{
  return binary_tree_is_empty((BinaryTree) tree);
}

void* dictionary_binary_tree_put(void* tree, void* key, void* value)
{
  return binary_tree_put((BinaryTree) tree, key, value);
}

void* dictionary_binary_tree_remove(void* tree, void* key)
{
  return binary_tree_remove((BinaryTree) tree, key);
}

size_t dictionary_binary_tree_size(void* tree)
{
  return binary_tree_size((BinaryTree) tree);
}
