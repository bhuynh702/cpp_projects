CXX = g++
CXXFLAGS = -Wall -g

lab10: Art.o Movie.o Painting.o lab10.cpp
	$(CXX) $(CXXFLAGS) Art.o Movie.o Painting.o lab10.cpp -o lab10

Painting.o: Art.o Painting.cpp
	$(CXX) $(CXXFLAGS) -c Painting.cpp

Movie.o: Art.o Movie.cpp
	$(CXX) $(CXXFLAGS) -c Movie.cpp

Art.o: Art.cpp 
	$(CXX) $(CXXFLAGS) -c Art.cpp

clean: 
	rm *.o
	rm *~

run: 
	./lab10