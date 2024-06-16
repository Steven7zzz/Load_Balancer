#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include "request.h"

// pretty straightforward, no comment needed
class requestQueue {
private:
    std::queue<request> queue;
    int capacity;
public:
    requestQueue(int cap = 1000) : capacity(cap) {}
    bool isEmpty() const;
    bool isFull() const;
    void addRequest(const request& req);
    request getNextRequest();
};

#endif