#include "recordset.h"

Recordset new_recordset(int id, char* field1, int field2, double field3)
{
  Recordset record = (Recordset) malloc(sizeof(struct recordset));
  if (!record) {
    printf("Impossible create recordset'\n");
    exit(EXIT_FAILURE);
  }

  record->id     = id;
  record->field1 = field1;
  record->field2 = field2;
  record->field3 = field3;

  return record;
}

int recordset_compare_id(void* ptr1,  void* ptr2)
{
  Recordset el1 = (Recordset) ptr1;
  Recordset el2 = (Recordset) ptr2;

  if (el1->id < el2->id)
  {
    return -1;
  }

  if (el1->id == el2->id)
  {
    return 0;
  }

  return 1;
}

int recordset_compare_id_ptr(void* ptr1,  void* ptr2)
{
  Recordset* el1 = (Recordset*) ptr1;
  Recordset* el2 = (Recordset*) ptr2;
  return recordset_compare_id(*el1, *el2);
}

int recordset_compare_field1(void* ptr1,  void* ptr2)
{
  Recordset el1 = (Recordset) ptr1;
  Recordset el2 = (Recordset) ptr2;

  //printf("[%s ... %s]\n", el1->field1, el2->field1); // DEBUG

  return strcmp(el1->field1, el2->field1);
}

int recordset_compare_field1_ptr(void* ptr1,  void* ptr2)
{
  Recordset* el1 = (Recordset*) ptr1;
  Recordset* el2 = (Recordset*) ptr2;
  return recordset_compare_field1(*el1, *el2);
}

int recordset_compare_field2(void* ptr1,  void* ptr2)
{
  Recordset el1 = (Recordset) ptr1;
  Recordset el2 = (Recordset) ptr2;

  //printf("[%d ... %d]\n", el1->field2, el2->field2); // DEBUG

  if (el1->field2 < el2->field2)
  {
    return -1;
  }

  if (el1->field2 == el2->field2)
  {
    return 0;
  }

  return 1;
}

int recordset_compare_field2_ptr(void* ptr1,  void* ptr2)
{
  Recordset* el1 = (Recordset*) ptr1;
  Recordset* el2 = (Recordset*) ptr2;
  return recordset_compare_field2(*el1, *el2);
}

int recordset_compare_field3(void* ptr1,  void* ptr2)
{
  Recordset el1 = (Recordset) ptr1;
  Recordset el2 = (Recordset) ptr2;

  //printf("[%lf ... %lf]\n", el1->field3, el2->field3); // DEBUG

  if (el1->field3 < el2->field3)
  {
    return -1;
  }

  if (el1->field3 == el2->field3)
  {
    return 0;
  }

  return 1;
}

int recordset_compare_field3_ptr(void* ptr1,  void* ptr2)
{
  Recordset* el1 = (Recordset*) ptr1;
  Recordset* el2 = (Recordset*) ptr2;
  return recordset_compare_field3(*el1, *el2);
}
