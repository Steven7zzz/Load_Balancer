#include "utils.h"

/**
 * @brief Generate a random IP address.
 *
 * This function generates a random IPv4 address in string format.
 *
 * @return Randomly generated IP address as a string.
 */
std::string generateRandomIP() {
    return std::to_string(rand() % 256) + "." + 
           std::to_string(rand() % 256) + "." + 
           std::to_string(rand() % 256) + "." + 
           std::to_string(rand() % 256);
}

/**
 * @brief Generate a random request.
 *
 * This function creates a request object with:
 * - Random IP address for input
 * - Random IP address for output
 * - Random processing time between 5 and 9 clock cycles
 *
 * @return Randomly generated request object.
 */
request generateRandomRequest() {
    return request(generateRandomIP(), generateRandomIP(), rand() % 5 + 5);
}
