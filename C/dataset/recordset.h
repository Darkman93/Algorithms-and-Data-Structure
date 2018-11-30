#ifndef __RECORDSET_H__
#define __RECORDSET_H__

#include "../libasd/src/standard_libraries.h"

/*
 * Types
 */

typedef struct recordset *Recordset;

/*
 * Data Structures
 */

struct recordset
{
  int    id;      // The id of the record.
  char*  field1;  // The string field.
  int    field2;  // The integer field.
  double field3; // The float filed.
};

/*
 * Functions
 */

Recordset new_recordset(int id, char* field1, int field2, double field3);

int recordset_compare_id         (void* ptr1,  void* ptr2);
int recordset_compare_id_ptr     (void* ptr1,  void* ptr2);
int recordset_compare_field1     (void* ptr1,  void* ptr2);
int recordset_compare_field1_ptr (void* ptr1,  void* ptr2);
int recordset_compare_field2     (void* ptr1,  void* ptr2);
int recordset_compare_field2_ptr (void* ptr1,  void* ptr2);
int recordset_compare_field3     (void* ptr1,  void* ptr2);
int recordset_compare_field3_ptr (void* ptr1,  void* ptr2);

#endif
