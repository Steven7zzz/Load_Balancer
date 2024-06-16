#include "webServer.h"

/**
 * @brief Default constructor for webServer.
 *
 * Initializes the server as not busy with no remaining time.
 */
webServer::webServer() : busy(false), remainingTime(0) {}

/**
 * @brief Check if the server is currently busy processing a request.
 *
 * @return true if the server is busy, false otherwise.
 */
bool webServer::isBusy() const {
    return busy;
}

/**
 * @brief Start processing a new request.
 *
 * Sets the server to busy, initializes remaining processing time,
 * and records details of the current request.
 *
 * @param req The request to be processed.
 */
void webServer::processRequest(const request& req) {
    busy = true;
    justFinished = false;
    remainingTime = req.time;
    currentRequest = req.ipInput + " -> " + req.ipOutput + " with time " + std::to_string(req.time);
}

/**
 * @brief Simulate the passage of time while processing a request.
 *
 * Decrements the remaining processing time each clock cycle.
 * Updates the busy status and sets justFinished flag when the request is completed.
 */
void webServer::tick() {
    if (busy && remainingTime > 0) {
        remainingTime--;
        if (remainingTime == 0) {
            busy = false;
            justFinished = true;
        }
    }
}

/**
 * @brief Get details of the current request being processed.
 *
 * @return String representation of the current request.
 */
std::string webServer::getCurrentRequest() const {
    return currentRequest;
}
