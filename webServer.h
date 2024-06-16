#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "request.h"

class webServer {
private:
    bool busy; // whether the server is currently processing a request.
    int remainingTime; // the remaining time to complete the current request.
    std::string currentRequest;
public:
    webServer(); 
    bool isBusy() const; 
    void processRequest(const request& req); 
    void tick(); 
    std::string getCurrentRequest() const;
    bool justFinished;
};

#endif