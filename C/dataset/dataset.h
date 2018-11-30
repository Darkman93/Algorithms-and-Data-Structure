#ifndef __DATASET_H__
#define __DATASET_H__

#include "../libasd/src/standard_libraries.h"
#include "recordset.h"

/*
 * Types
 */

typedef struct dataset *Dataset;

/*
 * Functions
 */

/**
 * @brief      Create an empty Dataset
 *
 * @param      recordset  The recordset
 * @param[in]  size       The size
 *
 * @return     A new Dataset
 */
Dataset new_dataset(Recordset* recordset, size_t size);

/**
 * @brief      Get size function
 *
 * @param[in]  dataset  The dataset
 *
 * @return     The @c size_t of Dataset
 */
size_t     dataset_getsize      (Dataset dataset);

/**
 * @brief      Get recordset function
 *
 * @param[in]  dataset  The dataset
 *
 * @return     The pointer @c recordset of Dataset
 */
Recordset* dataset_getrecordset (Dataset dataset);

/**
 * @brief      Loads a dataset.
 *
 * @param      filename  The filename
 *
 * @return     an array containing all recordset just read
 */
Dataset load_dataset(char* filename);


#endif