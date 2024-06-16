#include "utils.h"

// creates a request with random IP addresses and a random processing time
std::string generateRandomIP() {
    return std::to_string(rand() % 256) + "." + 
           std::to_string(rand() % 256) + "." + 
           std::to_string(rand() % 256) + "." + 
           std::to_string(rand() % 256);
}

request generateRandomRequest() {
    return request(generateRandomIP(), generateRandomIP(), rand() % 10 + 1);
}
