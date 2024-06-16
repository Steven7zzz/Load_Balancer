#ifndef REQUEST_H
#define REQUEST_H

#include <string>

/**
 * @file request.h
 * @brief Definition of the request structure.
 */

/**
 * @struct request
 * @brief Structure to represent a request with IP addresses and processing time.
 */
struct request {
    std::string ipInput;   ///< IP address of the requester.
    std::string ipOutput;  ///< IP address of the recipient.
    int time;              ///< Time in clock cycles required to process the request.

    /**
     * @brief Constructor to initialize a request.
     *
     * @param in IP address of the requester.
     * @param out IP address of the recipient.
     * @param t Time in clock cycles required to process the request.
     */
    request(std::string in, std::string out, int t) :
        ipInput(in), ipOutput(out), time(t) {}
};

#endif // REQUEST_H
