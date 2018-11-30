#ifndef __SWAPPING_H__
#define __SWAPPING_H__

#include "../standard_libraries.h"

/**
 * @brief         Swaps two elements.
 *
 * @param[in,out] ptr1         The pointer to the first element.
 * @param[in,out] ptr2         The pointer to the second element.
 * @param[in]     elementSize  The size of the elements.
 */
void bytewise_swap(void* ptr1, void* ptr2, size_t elementSize);

#endif