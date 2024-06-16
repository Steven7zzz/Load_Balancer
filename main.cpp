#include "loadBalancer.h"
#include "utils.h"
#include <ctime>

/**
 * @file main.cpp
 * @brief A simulation of a load balancer for processing web requests.
 */

/**
 * @brief Main function to run the load balancer simulation.
 *
 * This function initializes the load balancer, takes user input for number of servers
 * and runtime, generates initial requests, and runs the simulation.
 *
 * @return 0 on successful execution.
 */
int main() {
    srand(time(0)); // Seed the random number generator with current time

    int numServers, runTime;

    // Take user input for the number of servers and the runtime.
    std::cout << "Enter the number of servers: ";
    std::cin >> numServers;
    std::cout << "Enter the run time (in clock cycles): ";
    std::cin >> runTime;

    // Initialize the load balancer with the specified number of servers.
    loadBalancer loadBalancer(numServers, numServers * 100);

    // Add initial set of requests to the load balancer.
    for (int i = 0; i < numServers * 100; ++i) {
        loadBalancer.addRequest(generateRandomRequest());
    }

    // Run the load balancer simulation for the specified number of clock cycles.
    loadBalancer.run(runTime);

    // Save simulation log to a text file.
    loadBalancer.saveLogToFile("load_balancer_log.txt");

    return 0;
}
