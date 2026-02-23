#ifndef ENGINE_CPP
#define ENGINE_CPP
#include "Engine.h"
using namespace std;

// Name: Engine(string name, string type, int value)
  // Description: Creates a new Engine item
  // Preconditions: None
  // Postconditions: Can create a Engine
Engine::Engine(string name, string type, int value): Item(name, type, value){}
  // Name: Display
  // Description: Displays ENGINE, name, and value of engine item
  // Preconditions: None
  // Postconditions: Displays information about the engine
void Engine::Display(){
    cout << ENGINE << GetName() << "(" << GetValue() << ")" << endl;
}

#endif