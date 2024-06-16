#include "loadBalancer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

std::string generateRandomIP() {
    return std::to_string(rand() % 256) + "." + 
           std::to_string(rand() % 256) + "." + 
           std::to_string(rand() % 256) + "." + 
           std::to_string(rand() % 256);
}

// creates a request with random IP addresses and a random processing time
request generateRandomRequest() {
    return request(generateRandomIP(), generateRandomIP(), rand() % 10 + 1);
}

int main() {
    srand(time(0));
    int numServers, runTime;

    // take user input for the number of servers and the runtime.
    std::cout << "Enter the number of servers: ";
    std::cin >> numServers;
    std::cout << "Enter the run time (in clock cycles): ";
    std::cin >> runTime;


    // initialize the load balancer with the specified number of servers.
    loadBalancer loadBalancer(numServers);

    // add initial set of requests to the load balancer.
    for (int i = 0; i < numServers * 100; ++i) {
        loadBalancer.addRequest(generateRandomRequest());
    }

    // runs the load balancer simulation for the specified number of clock cycles
    loadBalancer.run(runTime);

    return 0;
}
