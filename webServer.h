/**
 * @file webServer.h
 * @brief Definition of the webServer class.
 */

#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "request.h"

/**
 * @brief The webServer class represents a server capable of processing requests.
 */
class webServer {
private:
    bool busy;                     ///< Flag indicating whether the server is currently processing a request.
    int remainingTime;             ///< Time remaining to complete the current request.
    std::string currentRequest;    ///< Details of the current request being processed.

public:
    /**
     * @brief Default constructor for webServer.
     */
    webServer();

    /**
     * @brief Check if the server is currently busy processing a request.
     * @return true if the server is busy, false otherwise.
     */
    bool isBusy() const;

    /**
     * @brief Start processing a new request.
     * @param req The request to be processed.
     */
    void processRequest(const request& req);

    /**
     * @brief Simulate the passage of time while processing a request.
     */
    void tick();

    /**
     * @brief Get details of the current request being processed.
     * @return String representation of the current request.
     */
    std::string getCurrentRequest() const;

    bool justFinished;  ///< Flag to indicate if the server has just finished processing a request.
};

#endif // WEBSERVER_H
