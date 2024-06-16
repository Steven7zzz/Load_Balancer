#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include "request.h"
#include <iostream>
#include <queue>

/**
 * @file requestQueue.h
 * @brief Definition of the requestQueue class.
 */

/**
 * @brief The requestQueue class represents a queue of requests.
 */
class requestQueue {
private:
    std::queue<request> queue; ///< Queue to store requests.
    int capacity;               ///< Maximum capacity of the queue.

public:
    /**
     * @brief Check if the queue is empty.
     *
     * @return true if the queue is empty, false otherwise.
     */
    bool isEmpty() const;

    /**
     * @brief Check if the queue is full.
     *
     * @return true if the queue is full, false otherwise.
     */
    bool isFull() const;

    /**
     * @brief Add a request to the queue.
     *
     * @param req The request to add to the queue.
     */
    void addRequest(const request& req);

    /**
     * @brief Get the next request from the queue.
     *
     * @return The next request in the queue.
     */
    request getNextRequest();

    /**
     * @brief Set the maximum capacity of the queue.
     *
     * @param cap The maximum capacity to set for the queue.
     */
    void setCapacity(int cap) { capacity = cap; }
};

#endif // REQUESTQUEUE_H
