#include "loadBalancer.h"
#include "utils.h"

/**
 * @file loadBalancer.cpp
 * @brief Implementation of the loadBalancer class methods.
 */

/**
 * @brief Constructor to initialize the load balancer with specified parameters.
 *
 * @param numServers Number of servers to initialize.
 * @param queueCap Capacity of the request queue.
 */
loadBalancer::loadBalancer(int numServers, int queueCap) : currentTime(0) {
    requestQueue.setCapacity(queueCap);
    log.push_back("Starting queue size: " + std::to_string(queueCap));
    for (int i = 0; i < numServers; ++i) {
        servers.emplace_back(); // using emplace_back because servers are class type 
    }
    log.push_back("LoadBalancer initialized with " + std::to_string(numServers) + " servers.");
}

/**
 * @brief Adds a new request to the load balancer's request queue.
 *
 * @param req The request to add.
 */
void loadBalancer::addRequest(const request& req) {
    if (!requestQueue.isFull()) {
        requestQueue.addRequest(req);
        log.push_back("Added request: " + req.ipInput + " -> " + req.ipOutput + " with time " + std::to_string(req.time));
    } else {
        log.push_back("Queue is full, cannot add request: " + req.ipInput + " -> " + req.ipOutput + " with time " + std::to_string(req.time));
    }
}

/**
 * @brief Adds a new server to the pool of servers.
 */
void loadBalancer::addServer() {
    servers.emplace_back();
    log.push_back("Added a new server. Total servers: " + std::to_string(servers.size()));
}

/**
 * @brief Removes a server from the pool of servers.
 */
void loadBalancer::removeServer() {
    if (!servers.empty()) {
        servers.pop_back();
        log.push_back("Removed a server. Total servers: " + std::to_string(servers.size()));
    }
}

/**
 * @brief Balances the load by distributing requests from the queue to available servers.
 */
void loadBalancer::balanceLoad() {
    for (auto& server : servers) {
        if (!server.isBusy() && !requestQueue.isEmpty()) {
            server.processRequest(requestQueue.getNextRequest());
            log.push_back("Server started processing request: " + server.getCurrentRequest());
        }
    }
}

/**
 * @brief Simulates the operation of the load balancer for a specified number of clock cycles.
 *
 * @param cycles Number of clock cycles to run the simulation.
 */
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

        // Add a random number of new requests to the queue
        for (int i = 0; i < rand() % 10; i++){
            addRequest(generateRandomRequest());
        }
        
        // Adjust number of servers based on queue status
        if (requestQueue.isFull() && servers.size() < 100) { // Cap at 100 servers to prevent excessive growth
            addServer();
        } else if (requestQueue.isEmpty() && servers.size() > 1) { // Ensure at least one server remains
            removeServer();
        }
    }
    log.push_back("Ending load balancer run.");
    log.push_back("Ending queue size: " + std::to_string(requestQueue.getSize()));
}

/**
 * @brief Saves the log messages to a text file.
 *
 * @param filename The name of the file to save the log to.
 */
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
