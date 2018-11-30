#include "strings.h"

char* new_string(char* buffer)
{
	if(!buffer) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  size_t strLen = strlen(buffer) + 1; // add space for '\0'
  char*  newStr = (char*) malloc(strLen*sizeof(char));
  if(!newStr) error(EXIT_FAILURE, 0, "Malloc error in function %s", __func__);
  strncpy(newStr, buffer, strLen);
  return newStr;
}