#ifndef __HASHES_H__
#define __HASHES_H__

#include "../standard_libraries.h"
#include "../function_types.h"

/**
 * @brief      Hash an @c int.
 *
 * @param[in]  key   The pointer to the @c int.
 *
 * @return     The digest of the @c int.
 */
size_t hash_int(void* key);

/**
 * @brief      Hash a @c double.
 *
 * @param[in]  key   The pointer to the @c double.
 *
 * @return     The digest of the @c double.
 */
size_t hash_double(void* key);

/**
 * @brief      Hash a @c string.
 *
 * @param[in]  key   The pointer to the @c string.
 *
 * @return     The digest of the @c string.
 */
size_t hash_string(void* key);

//@todo usato solo per test
/**
 * @brief      Hash an @c int.
 *
 * @param[in]  key   The pointer to the @c int.
 *
 * @return     The digest of the @c int.
 */
//size_t hash_raw_int(void* key);

#endif