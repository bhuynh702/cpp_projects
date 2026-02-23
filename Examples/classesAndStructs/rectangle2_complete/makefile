XX = g++
CXXFLAGS = -Wall

Rectangle1: Rectangle.o driver.cpp
	$(CXX) $(CXXFLAGS) Rectangle.o driver.cpp -o Rectangle1

Rectangle.o: Rectangle.cpp Rectangle.h
	$(CXX) $(CXXFLAGS) -c Rectangle.cpp

clean:
	rm *.o*
	rm *~ 

run:
	./Rectangle1
