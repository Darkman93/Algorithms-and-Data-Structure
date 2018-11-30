#include "files.h"

size_t line_counter(FILE* fp)
{
	if(!fp) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  char c;
  size_t nLines = 0;
  while ((c=fgetc(fp)) != EOF)
    if (c == '\n') ++nLines;
  rewind(fp);
  return nLines;
}