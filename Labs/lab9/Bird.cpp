#include "Bird.h"
#include <iostream> //Required library
#include <string> //Required library
using namespace std;

Bird::Bird(){ //Default constructor
m_species = "";
m_age = 0;
}                

Bird::Bird(string species, int age){ //Overloaded constructor
m_species = species;
m_age = age;
}

void Bird::Display(){ //Using the member variables, displays a brief description
cout << "Before you is a(n) " << m_age << " year-old " << m_species << "." << endl;
}        

string Bird::GetSpecies(){ //Getter for m_name
return m_species;
}     

int Bird::GetAge(){ //Getter for m_age
return m_age;
}        

void Bird::SetSpecies(string species){//Setter for m_name
m_species = species;
}
  
void Bird::SetAge(int age){
m_age = age;
}  