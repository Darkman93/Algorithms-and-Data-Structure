#ifndef __FILES_H__
#define __FILES_H__

#include "../standard_libraries.h"

/**
 * @brief      Calculate the number of lines of a file.
 *
 * @param[in]  fp    The pointer to the file.
 *
 * @return     The number of lines of the file.
 */
size_t line_counter(FILE* fp);

#endif