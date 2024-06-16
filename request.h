#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>
#include <queue>
#include <string>

struct request {
    std::string ipInput; // IP address of the requester.
    std::string ipOutput; // IP address of the recipient.
    int time; // the time in clock cycles required to process the request.

    // constractor 
    request(std::string in, std::string out, int t) :
    ipInput(in), ipOutput(out), time(t) {}
};

#endif