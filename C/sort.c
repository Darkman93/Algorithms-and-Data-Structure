#include "standard_libraries.h"
#include "asd.h"
#include "dataset.h"


//
// Configuration
//
char* recordsFilename = "data/records.csv";
//char* recordsFilename = "data/records_10.csv";

int startFromAlgorithm = 0, /* default 0 */ numOfAlgorithms = 3; /* default 3, otherwise 4 to 6 for include quadratic algorithms */
int     startFromField = 0, /* default 0 */ numOfFields     = 3; /* default 3 */

char*           algorithmName[] = {"Merge-sort", "Heap-sort", "Quick-sort", "Quick-sort-cormen", "Insertion-sort", "Selection-sort"};
SortFunction     sortFunction[] = {merge_sort, heap_sort, quick_sort, quick_sort_cormen, insertion_sort, selection_sort};

char*               fieldName[] = {"Field 1 (string)", "Field 2 (int)", "Field 3 (double)"};
CompareFunction  fieldCompare[] = {recordset_compare_field1_ptr, recordset_compare_field2_ptr, recordset_compare_field3_ptr};


//
// Main
//
int main(int argc, char  *argv[])
{
  printf("#EXERCISE 1\n\n");
  printf("Executes and measures sorting algorithms on three different types of data.\n\n");

  //
  // Load dataset
  printf("Loading dataset ... "); fflush(stdout);
  Dataset dataset = load_dataset(recordsFilename);
  printf("COMPLETED\n\n"); fflush(stdout);

  size_t      recsetSize = sizeof(Recordset);
  size_t     datasetSize = dataset_getsize(dataset);
  Recordset*     records = dataset_getrecordset(dataset);

  for (int a = startFromAlgorithm; a < numOfAlgorithms; ++a)
  {
    printf("##%s\n", algorithmName[a]);
    fflush(stdout);

    SortFunction sort = sortFunction[a];

    for (int f = startFromField; f < numOfFields; ++f)
    {
      CompareFunction compare = fieldCompare[f];

      printf("\n***\n");
      printf("Cloning records ... "); fflush(stdout);
      Recordset* clonedRecords = array_clone(records, datasetSize, recsetSize);
      printf("COMPLETED\n\n"); fflush(stdout);

      printf("Sorting by **%s**\n", fieldName[f]);
      fflush(stdout);

      start_tests();
      sort(clonedRecords, datasetSize, recsetSize, compare);
      end_tests();

      printf("\n");

      printf("Checking sorting ... "); fflush(stdout);
      bool sorted = array_sorted(clonedRecords, datasetSize, recsetSize, compare);
      printf("COMPLETED\n\n"); fflush(stdout);
      if (!sorted) {
        printf("Array not sorted\n");
        exit(EXIT_FAILURE);
      }

      printf("Freeing cloned record memory ... "); fflush(stdout);
      free(clonedRecords);
      printf("COMPLETED\n\n"); fflush(stdout);
    }
  }

  return EXIT_SUCCESS;
}
