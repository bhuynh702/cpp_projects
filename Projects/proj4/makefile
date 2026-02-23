CXX = g++
CXXFLAGS = -Wall -g

proj4: Game.o Item.o Armor.o Weapon.o Engine.o Planet.o Enemy.o Gas.o Mining.o Ship.o proj4.cpp
	$(CXX) $(CXXFLAGS) Game.o Item.o Armor.o Weapon.o Engine.o Planet.o Enemy.o Gas.o Mining.o Ship.o proj4.cpp -o proj4

Game.o: Item.o Armor.o Weapon.o Engine.o Planet.o Enemy.o Gas.o Mining.o Ship.o Game.h Game.cpp
	$(CXX) $(CXXFLAGS) -c Game.cpp

Ship.o: Item.o Armor.o Engine.o Weapon.o Ship.cpp Ship.h
	$(CXX) $(CXXFLAGS) -c Ship.cpp

Weapon.o: Item.o Weapon.cpp Weapon.h
	$(CXX) $(CXXFLAGS) -c Weapon.cpp

Engine.o: Item.o Engine.cpp Engine.h
	$(CXX) $(CXXFLAGS) -c Engine.cpp

Armor.o: Item.o Armor.cpp Armor.h
	$(CXX) $(CXXFLAGS) -c Armor.cpp

Item.o: Item.cpp Item.h
	$(CXX) $(CXXFLAGS) -c Item.cpp

Mining.o: Planet.o Mining.cpp Mining.h
	$(CXX) $(CXXFLAGS) -c Mining.cpp

Enemy.o: Planet.o Enemy.cpp Enemy.h
	$(CXX) $(CXXFLAGS) -c Enemy.cpp

Gas.o: Planet.o Gas.cpp Gas.h
	$(CXX) $(CXXFLAGS) -c Gas.cpp

Planet.o: Planet.cpp Planet.h
	$(CXX) $(CXXFLAGS) -c Planet.cpp

clean: 
	rm *.o
	rm *~

run: 
	./proj4 proj4_items.txt proj4_planets.txt

val1:
	valgrind ./proj4 proj4_items.txt proj4_planets.txt
