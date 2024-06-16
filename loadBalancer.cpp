#include "loadBalancer.h"
#include "utils.h"

// initializes the load balancer with number of servers and set queue capcity
loadBalancer::loadBalancer(int numServers, int queueCap) : currentTime(0) {
    requestQueue.setCapacity(queueCap);
    for (int i = 0; i < numServers; ++i) {
        servers.emplace_back(); // using emplace_back because servers are class type 
    }
    log.push_back("LoadBalancer initialized with " + std::to_string(numServers) + " servers.");
}


// add a new request to the request queue
void loadBalancer::addRequest(const request& req) {
    if (!requestQueue.isFull()) {
        requestQueue.addRequest(req);
        log.push_back("Added request: " + req.ipInput + " -> " + req.ipOutput + " with time " + std::to_string(req.time));
    } else {
        log.push_back("Queue is full, cannot add request: " + req.ipInput + " -> " + req.ipOutput + " with time " + std::to_string(req.time));
    }
}

void loadBalancer::addServer() {
    servers.emplace_back();
    log.push_back("Added a new server. Total servers: " + std::to_string(servers.size()));
}

void loadBalancer::removeServer() {
    if (!servers.empty()) {
        servers.pop_back();
        log.push_back("Removed a server. Total servers: " + std::to_string(servers.size()));
    }
}



// distributes requests from the queue to the servers, if any servers are not busy
void loadBalancer::balanceLoad() {
    for (auto& server : servers) {
        if (!server.isBusy() && !requestQueue.isEmpty()) {
            server.processRequest(requestQueue.getNextRequest());
            log.push_back("Server started processing request: " + server.getCurrentRequest());
        }
    }
}


// simulates the operation of the load balancer for a specified number of clock cycles
void loadBalancer::run(int cycles) {
    log.push_back("Starting load balancer run for " + std::to_string(cycles) + " cycles.");
    for (int i = 0; i < cycles; ++i) {
        balanceLoad();
        for (auto& server : servers) {
            std::string currentRequest = server.getCurrentRequest();
            server.tick();
            if (server.justFinished) {
                log.push_back("Server finished processing request: " + currentRequest);
                server.justFinished = false;
            }
        }
        currentTime++;

        for (int i = 0; i < rand() % 10; i++){
            addRequest(generateRandomRequest());
        }
        
        if (requestQueue.isFull() && servers.size() < 100) { // Cap at 100 servers to prevent excessive growth
            addServer();
        } else if (requestQueue.isEmpty() && servers.size() > 1) { // Ensure at least one server remains
            removeServer();
        }
    }
    log.push_back("Ending load balancer run.");
    log.push_back("Starting queue size: " + std::to_string(servers.size() * 100));
    log.push_back("Ending queue size: " + std::to_string(requestQueue.isEmpty() ? 0 : 1));
}

void loadBalancer::saveLogToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& entry : log) {
            outFile << entry << std::endl;
        }
        outFile.close();
    } else {
        std::cerr << "Unable to open file " << filename << std::endl;
    }
}
