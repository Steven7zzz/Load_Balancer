#include "requestQueue.h"

// add a new request to the queue.
void requestQueue::addRequest(const request& req) {
    queue.push(req);
}


// get and remove the next request from the queue.
request requestQueue::getNextRequest() {
    request req = queue.front();
    queue.pop();
    return req;
}


// get if the queue is empty.
bool requestQueue::isEmpty() const {
    return queue.empty();
}

// get if the queue is full.
bool requestQueue::isFull() const {
    return queue.size() >= capacity;
}