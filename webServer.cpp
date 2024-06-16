#include "webServer.h"

// initializes the server as not busy with no remaining time
webServer::webServer() : busy(false), remainingTime(0) {}


// get the busy status of the server
bool webServer::isBusy() const {
    return busy;
}


// starts processing a request and sets the remaining processing time.
void webServer::processRequest(const request& req) {
    busy = true;
    remainingTime = req.time;
}


// decrements the remaining time each clock cycle and updates the busy status.
void webServer::tick() {
    if (busy && remainingTime > 0) {
        remainingTime--;
        if (remainingTime == 0) {
            busy = false;
        }
    }
}
