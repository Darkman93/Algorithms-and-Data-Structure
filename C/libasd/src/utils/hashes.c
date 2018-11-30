#include "hashes.h"

/*
 * Prototypes
 */

/**
 * @todo
 */
size_t rs_hash(void* key, size_t size);

/*
 * Public functions
 */

size_t hash_int(void* key)
{
  if(!key) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  return *(int*) key;
}

size_t hash_double(void* key)
{
  if(!key) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  return rs_hash(key, sizeof(double));
}

size_t hash_string(void* key)
{
  if(!key) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  return rs_hash(key, strlen((char*) key));
}

/*
 * Private functions
 */

size_t rs_hash(void* key, size_t size)
{
  unsigned int a = 63689;
  unsigned int b = 378551;
  unsigned int res = 0;
  char* k = (char*) key;
  for(size_t i = 0; i < size; ++i)
  {
    res = res * a + (*k);
    a = a * b;
    ++k;
  }
  return res;
}

/*
@todo usato solo per test

size_t hash_rs_int(void* key)
{
  if(!key) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  return rs_hash(key, sizeof(int));
}
*/