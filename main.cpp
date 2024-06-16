#include "loadBalancer.h"
#include "utils.h"
#include <ctime>

int main() {
    srand(time(0));
    int numServers, runTime;

    // take user input for the number of servers and the runtime.
    std::cout << "Enter the number of servers: ";
    std::cin >> numServers;
    std::cout << "Enter the run time (in clock cycles): ";
    std::cin >> runTime;

    // queue.setCapacity(numServers * 100); 

    // initialize the load balancer with the specified number of servers.
    loadBalancer loadBalancer(numServers, numServers * 100);

    // add initial set of requests to the load balancer.
    for (int i = 0; i < numServers * 100; ++i) {
        loadBalancer.addRequest(generateRandomRequest());
    }

    // runs the load balancer simulation for the specified number of clock cycles
    loadBalancer.run(runTime);

    loadBalancer.saveLogToFile("load_balancer_log.txt");

    return 0;
}
