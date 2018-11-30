#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include "../standard_libraries.h"


/**
 * @todo Detailed explanation.
 */
typedef struct dictionary* Dictionary;


/**
 * @todo
 */
void destroy_dictionary(Dictionary* dictionary);


/**
 * Returns the value to which the key is mapped in this dictionary.
 * The general contract for the isEmpty method is that if this dictionary contains an entry for the specified key,
 * the associated value is returned; otherwise, null is returned.
 * @return the value to which the key is mapped in this dictionary
 */
void* dictionary_get(Dictionary dictionary, void* key);

/**
 * Tests if this dictionary maps no keys to value.
 * The general contract for the is_empty method is that the result is true if and only if this dictionary contains no entries.
 * @return true if this dictionary maps no keys to values; false otherwise.
 */
bool dictionary_is_empty(Dictionary dictionary);

/**
 * Maps the specified key to the specified value in this dictionary. Neither the key nor the value can be null.
 * If this dictionary already contains an entry for the specified key, the value already in this dictionary for that key is returned,
 * after modifying the entry to contain the new element.
 * If this dictionary does not already have an entry for the specified key, an entry is created for the specified key and value,
 * and null is returned.
 * The value can be retrieved by calling the get method with a key that is equal to the original key.
 * @return the previous value to which the key was mapped in this dictionary, or null if the key did not have a previous mapping.
 */
void* dictionary_put(Dictionary dictionary, void* key, void* value);

/**
 * Removes the key (and its corresponding value) from this dictionary. This method does nothing if the key is not in this dictionary.
 * @return the value to which the key had been mapped in this dictionary, or null if the key did not have a mapping.
 */
void* dictionary_remove(Dictionary dictionary, void* key);

/**
 * Returns the number of entries (distinct keys) in this dictionary.
 * @return the number of keys in this dictionary.
 */
size_t dictionary_size(Dictionary dictionary);


#endif
