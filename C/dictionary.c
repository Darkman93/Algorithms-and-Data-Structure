#include "standard_libraries.h"
#include "asd.h"
#include "dataset.h"


//
// Configuration
//
char* recordsFilename = "data/records.csv";
//char* recordsFilename = "data/records_500.csv";

int   startFromStruct = 0, /* default 0 */ numOfStructs = 3; /* default 3 */
int    startFromField = 0, /* default 0 */ numOfFields  = 3; /* default 3 */
size_t numberOfAccess = 1000000; /* default 1000000 */

char*             structName[] = {"Binary-Tree", "Hash-Table", "Pre-allocated Hash-Table"};
char*              fieldName[] = {"Field 1", "Field 2", "Field 3"};
CompareFunction fieldCompare[] = {compare_string, compare_int, compare_double};
HashFunction       fieldHash[] = {hash_string, hash_int, hash_double};

int hash_table_customized_size      = 20000000;
int hash_table_customized_threshold = 5;


//
// Prototypes
//
void*      get_field_ptr(Recordset record, int field);
Dictionary create_data_structure(int type, CompareFunction compare, HashFunction hash);


//
// Main
//
int main(int argc, char  *argv[])
{
  printf("#EXERCISE 2\n\n");
  printf("Dictionaries implemented with Binary-Trees and Hash-Tables.\n\n");

  //
  // Load dataset
  printf("Loading dataset ... "); fflush(stdout);
  Dataset dataset = load_dataset(recordsFilename);
  printf("COMPLETED\n\n"); fflush(stdout);

  size_t     datasetSize = dataset_getsize(dataset); // Size of the dataset
  Recordset*     records = dataset_getrecordset(dataset); // The data

  Dictionary dictionary;
  void* key;
  void* value;
  void* result; // Used to check if the element was inserted or updated
  size_t randomIndex;

  size_t read = 0, inserted = 0, access = 0, deletion = 0;

  time_t t;
  srand((unsigned) time(&t));

  //
  // For every data-structure

  for(int s = startFromStruct; s < numOfStructs; ++s)
  {
    printf("##%s implementation\n", structName[s]);
    fflush(stdout);

    //
    // For every field of the records

    for(int f = startFromField; f < numOfFields; ++f)
    {
      dictionary = create_data_structure(s, fieldCompare[f], fieldHash[f]);


      //
      // Insertions tests
      //
      printf("\n***\n");
      printf("%zu **insertions** using **%s** as Key\n", datasetSize, fieldName[f]);
      fflush(stdout);

      start_tests();
      for (int i=0; i < datasetSize; ++i)
      {
        key    = get_field_ptr(records[i], f);
        value  = records[i];
        result = dictionary_put(dictionary, key, value);
        if (!result) ++inserted;
        ++read;
      }
      end_tests();

      printf("=> records %zu/%zu (inserted/read)\n\n", inserted, read);
      fflush(stdout);


      //
      // Random access tests
      //
      printf("%zu random **access** using **%s** as key\n", numberOfAccess, fieldName[f]);
      fflush(stdout);

      start_tests();
      for (int i=0; i < numberOfAccess; ++i)
      {
        randomIndex = rand() % datasetSize;
        key    = get_field_ptr(records[randomIndex], f);
        result = dictionary_get(dictionary, key);
        if(result) ++access;
      }
      end_tests();

      printf("=> %zu/%zu hits\n\n", access, numberOfAccess);
      fflush(stdout);


      //
      // Random deletion tests
      //
      printf("%zu random **deletion** using **%s** as key\n", numberOfAccess, fieldName[f]);
      fflush(stdout);

      start_tests();
      for (int i=0; i < numberOfAccess; ++i)
      {
        randomIndex = rand() % datasetSize;
        key    = get_field_ptr(records[randomIndex], f);
        result = dictionary_remove(dictionary, key);
        if(result) ++deletion;
      }
      end_tests();

      printf("=> %zu/%zu hits\n\n", deletion, numberOfAccess);
      fflush(stdout);

      destroy_dictionary(&dictionary);
      read = inserted = access = deletion = 0;
    }

    printf("\n");
  }

  return EXIT_SUCCESS;
}


//
// Helper functions
//

void* get_field_ptr(Recordset record, int field)
{
  if(field == 0) return record->field1;
  if(field == 1) return &record->field2;
  return &record->field3;
}

Dictionary create_data_structure(int type, CompareFunction compare, HashFunction hash)
{
  int t = type % 3;
  if(t == 0) return create_dictionary_binary_tree(compare);
  if(t == 1) return create_dictionary_hash_table(compare, hash);

  int size      = hash_table_customized_size;
  int threshold = hash_table_customized_threshold;
  return create_dictionary_hash_table_customized(size, threshold, compare, hash);
}
