CXX = g++
CXXFLAGS = -Wall

lab5: Hotel.o lab5.cpp
$(CXX) $(CXXFLAGS) Hotel.o lab5.cpp -o lab5

Hotel.o: Hotel.cpp Hotel.h
$(CXX) $(CXXFLAGS) -c Hotel.cpp

run:
./lab5
