CXX := g++
CXXFLAGS := -ggdb3 -std=c++23 -Wall -Wextra -Wpedantic

all: main

main: main.cpp lenet.o mnist_reader.o network.cpp conv_layer.o pooling_layer.o fully_connected_layer.o
	$(CXX) $(CXXFLAGS) $^ -o $@

lenet.o: lenet.cpp 
	$(CXX) $(CXXFLAGS) $< -c -o $@

mnist_reader.o: mnist_reader.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

conv_layer.o: conv_layer.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

pooling_layer.o: pooling_layer.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

fully_connected_layer.o: fully_connected_layer.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

clean:
	rm -f *.o main 
