#include "../libasd/src/utils/files.h"
#include "../libasd/src/utils/strings.h"
#include "recordset.h"
#include "dataset.h"

#define STR_BUFF_LEN 1000

struct dataset
{
  size_t     size;
  Recordset* records;
};

//
// Protypes
//
Recordset* new_recordset_array  (size_t size);
void       fill_recordset_array (FILE* fp, Recordset* records, size_t size);

//
// Private functions
//
Dataset new_dataset(Recordset* records, size_t size)
{
  Dataset dataset = (Dataset) malloc(sizeof(struct dataset));
  if (!dataset) {
    printf("Impossible create dataset'\n");
    exit(EXIT_FAILURE);
  }

  dataset->size    = size;
  dataset->records = records;

  return dataset;
}

size_t dataset_getsize(Dataset dataset)
{
  return dataset->size;
}

Recordset* dataset_getrecordset(Dataset dataset)
{
  return dataset->records;
}

Dataset load_dataset(char* filename)
{
  FILE* fp = fopen(filename, "r");
  if (!fp) {
    printf("Impossible open %s\n", filename);
    exit(EXIT_FAILURE);
  }

  Recordset* records = NULL;
  size_t     n_lines = line_counter(fp);
  if (n_lines > 0) {
    records = new_recordset_array(n_lines);
    fill_recordset_array(fp, records, n_lines);
  }

  fclose(fp);

  return new_dataset(records, n_lines);
}

//
// Private functions
//
Recordset* new_recordset_array(size_t n_lines)
{
  Recordset* records = (Recordset*) malloc(n_lines*sizeof(Recordset));
  if (!records) {
    printf("Impossible allocate %zd lines of recordsets\n", n_lines);
    exit(EXIT_FAILURE);
  }

  return records;
}

void fill_recordset_array(FILE* fp, Recordset* records, size_t size)
{
  int   id, field2;
  char* field1;
  double field3;
  char str_buff[STR_BUFF_LEN];

  for (size_t i=0; i < size; ++i)
  {
    int n_matched = fscanf(fp, "%d,%[^,],%d,%lf ", &id, str_buff, &field2, &field3);
    if (n_matched != 4) {
      printf("Error format csv line: %d field(s) matched\n", n_matched);
      exit(EXIT_FAILURE);
    }

    field1     = new_string(str_buff);
    records[i] = new_recordset(id, field1, field2, field3);
  }
}
