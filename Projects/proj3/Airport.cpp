/*
*/

#include "Airport.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

  // Default Constructor
  Airport::Airport(){
    m_code = "";
    m_name = "";
    m_city = "";
    m_country = "";
    m_north = 0;
    m_west = 0;
    m_next = nullptr;
  }

  // Overloaded Constructor
  Airport::Airport(string code, string name, string city, string country, double north, double west){
    m_code = code; 
    m_name = name;
    m_city = city;
    m_country = country;
    m_north = north;
    m_west = west;
    m_next = nullptr;
  }
  // Name: ~Airport() - Destructor
  // Desc: Used to destruct a airport
  //**This function should be empty but must be implemented
  // Preconditions: There is an existing airport
  // Postconditions: Airport is deallocated and has no memory leaks!
  Airport::~Airport(){

  }

  // Returns the three letter code of the airport
  string Airport::GetCode(){
    return m_code;
  }

  // Returns the name of the airport
  string Airport::GetName(){
    return m_name;
  }
  // Name: GetNext()
  // Desc: Returns the pointer to the next airport
  // Preconditions: None (may return either airport or nullptr)
  // Postconditions: Returns m_next;
  Airport* Airport::GetNext(){
    return m_next;
  }

  // Returns the northern coordinates of the airport
  double Airport::GetNorth(){
    return m_north;
  }

  // Returns the western coordinates of the airport
  double Airport::GetWest(){
    return m_west;
  }

  // Returns the city of where the airport is located
  string Airport::GetCity(){
    return m_city;
  }

  // Returns the country of where the airport is located
  string Airport::GetCountry(){
    return m_country; 
  }
  // Name: SetNext()
  // Desc: Updates the pointer to a new target (either a airport or nullptr)
  // Preconditions: None
  // Postconditions: Sets the next airport
  void Airport::SetNext(Airport *newTarget){
    m_next = newTarget; 
  }