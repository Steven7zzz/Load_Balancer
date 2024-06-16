#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include "request.h"

// pretty straightforward, no comment needed
class requestQueue {
private:
    std::queue<request> queue;
    int capacity;
public:
    bool isEmpty() const;
    bool isFull() const;
    void addRequest(const request& req);
    request getNextRequest();
    void setCapacity(int cap) { capacity = cap; }
};

#endif