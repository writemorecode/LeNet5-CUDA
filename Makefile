CXX := g++
CXXFLAGS := -ggdb3 -std=c++23 -Wall -O2 -march=native

all: main

main: main.cpp lenet.o mnist_reader.o
	$(CXX) $(CXXFLAGS) main.cpp lenet.o mnist_reader.o -o main

lenet.o: lenet.cpp 
	$(CXX) $(CXXFLAGS) lenet.cpp -c -o lenet.o

mnist_reader.o: mnist_reader.cpp
	$(CXX) $(CXXFLAGS) mnist_reader.cpp -c -o mnist_reader.o

clean:
	rm -f *.o main 
