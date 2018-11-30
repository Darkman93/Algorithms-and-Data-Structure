#include "list_map.h"
#include "list_map_defs.h"
#include "list_map_debug.h"

size_t list_map_count(ListMap list)
{
  size_t count = 0;
  ListNode current = list->head;
  while (current) {
    ++count;
    current = current->next;
  }
  return count;
}
