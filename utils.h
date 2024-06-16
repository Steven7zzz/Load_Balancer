#ifndef UTILS_H
#define UTILS_H

#include "request.h"
#include <cstdlib>

/**
 * @file utils.h
 * @brief Utility functions for generating random IP addresses and requests.
 */

/**
 * @brief Generate a random IP address.
 *
 * This function generates a random IPv4 address in string format.
 *
 * @return Randomly generated IP address as a string.
 */
std::string generateRandomIP();

/**
 * @brief Generate a random request.
 *
 * This function generates a random request containing:
 * - Random IP input address
 * - Random IP output address
 * - Random processing time
 *
 * @return Randomly generated request object.
 */
request generateRandomRequest();

#endif // UTILS_H
