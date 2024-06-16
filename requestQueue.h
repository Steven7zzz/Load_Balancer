#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include "request.h"

// pretty straightforward, no comment needed
class requestQueue {
private:
    std::queue<request> queue;
public:
    void addRequest(const request& req);
    request getNextRequest();
    bool isEmpty() const;
};

#endif