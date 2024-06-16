#include "loadBalancer.h"

// initializes the load balancer with number of servers
loadBalancer::loadBalancer(int numServers) : currentTime(0) {
    for (int i = 0; i < numServers; ++i) {
        servers.emplace_back(); // using emplace_back because servers are class type 
    }
}


// add a new request to the request queue
void loadBalancer::addRequest(const request& req) {
    requestQueue.addRequest(req);
}


// distributes requests from the queue to the servers, if any servers are not busy
void loadBalancer::balanceLoad() {
    for (auto& server : servers) {
        if (!server.isBusy() && !requestQueue.isEmpty()) {
            server.processRequest(requestQueue.getNextRequest());
        }
    }
}


// simulates the operation of the load balancer for a specified number of clock cycles
void loadBalancer::run(int cycles) {
    for (int i = 0; i < cycles; ++i) {
        balanceLoad();
        for (auto& server : servers) {
            server.tick();
        }
        currentTime++;
    }
}
