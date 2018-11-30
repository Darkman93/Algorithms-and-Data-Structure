#include "hash_table_debug.h"
#include "hash_table.h"
#include "hash_table_defs.h"
#include "../list_map/list_map.h"

size_t hash_table_get_capacity(HashTable htable)
{
  return htable->capacity;
}

size_t hash_table_count(HashTable htable)
{
  size_t count = 0;
  for (size_t i=0; i < htable->capacity; ++i)
  {
    if (htable->table[i])
    {
      // @todo magari meglio usare un list_map_iterator per contare uno ad uno
      count += list_map_size(htable->table[i]);
    }
  }
  return count;
}

void hash_table_size_vs_capacity(HashTable htable)
{
  printf("[%zu - %zu]\n", htable->size, htable->capacity);
}

void hash_table_collion_list_statistics(HashTable htable)
{
  if ( false
    || htable->size == 822
    || htable->size == 4908200
    || htable->size == 19997945
  )
  {
    size_t length;
    size_t sum  = 0;
    size_t max  = 0;
    size_t rows = 0;

    for (size_t i=0; i < htable->capacity; ++i)
    {
      if (htable->table[i])
      {
        length = list_map_size(htable->table[i]);
        max = length > max ? length : max;
        sum += length;
        ++rows;

        //printf("%zu,%zu\n", i, length); fflush(stdout);
      }
    }

    printf("\n");
    printf("CollionList - lunghezza massima: %zu\n", max);
    printf("CollionList - lunghezza media:   %lf\n", ((double) sum)/rows);
  }
}
