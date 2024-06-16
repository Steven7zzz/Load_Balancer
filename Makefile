CXX = g++
CXXFLAGS = -Wall -std=c++11

all: main

main: main.o LoadBalancer.o WebServer.o RequestQueue.o Utils.o
	$(CXX) $(CXXFLAGS) -o main main.o LoadBalancer.o WebServer.o RequestQueue.o Utils.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

LoadBalancer.o: LoadBalancer.cpp LoadBalancer.h
	$(CXX) $(CXXFLAGS) -c LoadBalancer.cpp

WebServer.o: WebServer.cpp WebServer.h
	$(CXX) $(CXXFLAGS) -c WebServer.cpp

RequestQueue.o: RequestQueue.cpp RequestQueue.h
	$(CXX) $(CXXFLAGS) -c RequestQueue.cpp

Utils.o: Utils.cpp Utils.h
	$(CXX) $(CXXFLAGS) -c Utils.cpp

clean:
	rm -f *.o main
