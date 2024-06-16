#include "requestQueue.h"

/**
 * @brief Add a new request to the queue.
 *
 * @param req The request to add to the queue.
 */
void requestQueue::addRequest(const request& req) {
    queue.push(req);
}

/**
 * @brief Get and remove the next request from the queue.
 *
 * @return The next request in the queue.
 */
request requestQueue::getNextRequest() {
    request req = queue.front();
    queue.pop();
    return req;
}

/**
 * @brief Check if the queue is empty.
 *
 * @return true if the queue is empty, false otherwise.
 */
bool requestQueue::isEmpty() const {
    return queue.empty();
}

/**
 * @brief Check if the queue is full.
 *
 * @return true if the queue is full, false otherwise.
 */
bool requestQueue::isFull() const {
    return queue.size() >= capacity;
}