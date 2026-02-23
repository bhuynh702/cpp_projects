#ifndef PLANET_CPP
#define PLANET_CPP
#include <iostream>
#include <string>
#include "Planet.h"
using namespace std;

Planet::Planet(string name, int challenge){
  m_name = name;
  m_challenge = challenge;
  m_isExplored = false;
}

Planet::~Planet(){}
  // Name: Battle()
  // Description: Describes battle between planet and ship
  //              1. Indicates that the battle is starting
  //              2. Randomly chooses the difficult based on m_challenge + 1
  //              3. Gets the ship's attack and defense
  //              4. Compares difficulty with the ship's attack
  //                 If difficult is greater, notifies player, and calculates
  //                 the delta and multiplies with FUEL_COST_DELTA
  //                 and modifies the ship fuel (penalty)
  //                 If ship attack is higher, increases fuel by FUEL_MULTI_WIN
  //                 and sets isExplored
  // Preconditions: None
  // Postconditions: Returns true if win, else false
bool Planet::Battle(Ship* myShip){
  cout << "Battle commencing!" << endl;
  int difficulty = rand() % m_challenge + 1;

  int attack = myShip->GetTotal("weapon");
  int defense = myShip->GetTotal("armor");

  int delta = (attack + defense) - difficulty;

  if(attack >= difficulty){
    cout << "Your planetary bombardment worked. You won!" << endl
    << "You've taken fuel from the defeated planet. You've earned " << delta * FUEL_MULTI_WIN << " fuel" << endl; 
    myShip->ModifyFuel(delta * FUEL_MULTI_WIN);
    SetIsExplored();
    return true;
  }else if(attack < difficulty){
    cout << "You attacked, but lost." << endl
    << "You've lost some fuel. You've lost " << delta * FUEL_COST_DELTA << " fuel" << endl;
    myShip->ModifyFuel(delta * FUEL_COST_DELTA);
    SetIsExplored();
  }
  return false;
}
  // Name: GetName()
  // Description: Returns planet name
  // Preconditions: None
  // Postconditions: Returns planet name
string Planet::GetName(){ return m_name;}
  // Name: SetIsExplored
  // Description: Sets IsExplored to true
  // Preconditions: None
  // Postconditions: Toggles from false to true when explored
void Planet::SetIsExplored(){
  m_isExplored = true;
}
  // Name: GetIsExplored
  // Description: Returns m_isExplored
  // Preconditions: None
  // Postconditions: Returns true if m_isExplored is true
bool Planet::GetIsExplored(){ 
  return m_isExplored; 
}
  // Name: GetChallenge
  // Description: Returns challenge of planet
  // Preconditions: None
  // Postconditions: Returns challenge of planet
int Planet::GetChallenge(){ return m_challenge; }
  // Name: Overloaded <<
  // Description: Prints the details of planet (name, type, and challenge)
  // Preconditions: None
  // Postconditions: returns an ostream with output of planet
ostream& operator<<(ostream& output, Planet& myPlanet){ 
  output << myPlanet.GetName() << " " << myPlanet.GetType() << " " << myPlanet.GetChallenge();
  return output; 
  }

#endif