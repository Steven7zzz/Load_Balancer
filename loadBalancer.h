#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "webServer.h"
#include "requestQueue.h"
#include <vector>
#include <fstream>

class loadBalancer {
private:
    std::vector<webServer> servers; // represent the pool of servers
    requestQueue requestQueue; // the queue to manage incoming requests
    int currentTime; // the current time in clock cycles
    std::vector<std::string> log; // Vector to store log messages
    
    // Private methods for internal use
    void addServer();
    void removeServer();
    
public:
    loadBalancer(int numServers, int queueCap); 
    void addRequest(const request& req); 
    void balanceLoad(); 
    void run(int cycles);
    void saveLogToFile(const std::string& filename) const;
};

#endif




