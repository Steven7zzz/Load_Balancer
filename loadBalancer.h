#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "webServer.h"
#include "requestQueue.h"
#include <vector>
#include <fstream>

/**
 * @file loadBalancer.h
 * @brief Definition of the loadBalancer class.
 */

/**
 * @class loadBalancer
 * @brief Manages a pool of web servers and a queue of requests to balance loads.
 */
class loadBalancer {
private:
    std::vector<webServer> servers; ///< Pool of web servers.
    requestQueue requestQueue;      ///< Queue to manage incoming requests.
    int currentTime;                ///< Current time in clock cycles.
    std::vector<std::string> log;   ///< Vector to store log messages.

    // Private methods for internal use
    void addServer();     ///< Adds a new server to the pool.
    void removeServer();  ///< Removes a server from the pool.

public:
    /**
     * @brief Constructor to initialize the load balancer with specified parameters.
     *
     * @param numServers Number of servers to initialize.
     * @param queueCap Capacity of the request queue.
     */
    loadBalancer(int numServers, int queueCap);

    /**
     * @brief Adds a new request to the load balancer's request queue.
     *
     * @param req The request to add.
     */
    void addRequest(const request& req);

    /**
     * @brief Balances the load by distributing requests to available servers.
     */
    void balanceLoad();

    /**
     * @brief Runs the load balancer simulation for a specified number of clock cycles.
     *
     * @param cycles Number of clock cycles to run the simulation.
     */
    void run(int cycles);

    /**
     * @brief Saves the log messages to a text file.
     *
     * @param filename The name of the file to save the log to.
     */
    void saveLogToFile(const std::string& filename) const;
};

#endif // LOADBALANCER_H
