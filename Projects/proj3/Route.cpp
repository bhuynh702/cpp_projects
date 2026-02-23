/*
*/
#include "Route.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Default Constructor
  Route::Route(){
    m_name = "";
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
  }
  // Name: SetName(string)
  // Desc: Sets the name of the route (usually first
  //   airport to last airport)
  // Preconditions: None
  // Postconditions: Sets name of route
  void Route::SetName(string name){
    m_name = name; 
  }
  // Name: ~Route() - Destructor
  // Desc: Used to destruct a strand of Route
  // Preconditions: There is an existing Route strand with at least
  //   one airport
  // Postconditions: Route is deallocated (including all
  //   dynamically allocated airports) to have no memory leaks! 
 Route::~Route(){
  Airport* current = m_head;
  Airport* next;

  // iterate through linked list 
  while(current != nullptr){ 
    next = current->GetNext();
    delete current; // delete each node
    current = next; 
  }
  //reset head and tail of linked list
  m_head = nullptr;
  m_tail = nullptr;
 }
  // Name: InsertEnd (string, string, double double)
  // Desc: Creates a new airport using the data passed to it.
  //   Inserts the new airport at the end of the route
  // Preconditions: Takes in a Airport
  //                Requires a Route
  // Postconditions: Adds the new airport to the end of a route
  void Route::InsertEnd(string code, string name, string city, string country, double north, double west){
  Airport* temp = new Airport(code, name, city, country, north, west); // dynamically allocate new Airport pointer 
  // populate with data 
  temp->SetNext(nullptr); 
  if(m_head == nullptr){
    m_tail = temp;
    m_head = temp;
  }else{
    m_tail->SetNext(temp); 
    m_tail = temp; 
  }
  m_size++; // increment size 
  }
  // Name: RemoveAirport(int index)
  // Desc: Removes a airport from the route at the index provided
  //   Hint: Special cases (first airport, last airport, middle airport)
  // Preconditions: Index must be less than the size of the route
  //   Cannot make route less than two airports. If the route has
  //   two or fewer airports, fails.
  // Postconditions: Name may be updated. Size is reduced.
  //   Route has one less airport.
  void Route::RemoveAirport(int index){
    Airport *current = m_head;
    Airport *next;
    Airport *previous;
    
    if(index == 0){ // if removing head
      m_head = current->GetNext(); // make temp point to next and set next equal to m_head
      delete current;
    }else if(index == m_size - 1){ // if index is equal to the size (minus 1 b/c last index = size - 1)
      for (int i = 0; i < m_size - 2; i++){ // will access the node before the last one
        current = current->GetNext(); 
      }
      previous = current;
      previous->SetNext(nullptr); 
      delete m_tail;
      m_tail = previous;
    }else{
      for (int i = 0; i < index - 1; i++){
        current = current->GetNext();
      }
      previous = current;
      current = current->GetNext();
      next = current->GetNext();
      previous->SetNext(next);
      delete current;
    }
    m_size--; // decrement m_size 
  }
  // Name: GetName()
  // Desc: Returns the name of the route (Usually starting
  //  airport to last airport)
  //  For example: Baltimore to Boston
  // Preconditions: Requires a Route
  // Postconditions: Returns m_name;
  string Route::GetName(){
    if (m_head != nullptr){
      return m_name;
    }
    return m_name;
  }
  // Name: UpdateName()
  // Desc: Updates m_name based on the name of the first airport
  //   in the route and the last airport in the route
  //       For example: Baltimore to Boston
  // Preconditions: Requires a Route with at least two airports
  // Postconditions: Returns m_name;
  string Route::UpdateName(){
    string firstAirport;
    string lastAirport;
    if (m_head != nullptr && m_size >= 2){
      firstAirport = m_head->GetCity();
      lastAirport = m_tail->GetCity();
      m_name = firstAirport + " to " + lastAirport;
    }
    return m_name;
  }
  // Name: GetSize()
  // Desc: Returns the number of airports in a route
  // Preconditions: Requires a Route
  // Postconditions: Returns m_size;
  int Route::GetSize(){
    return m_size;
  }
  // Name: ReverseRoute
  // Desc: Reverses a route
  // Preconditions: Reverses the Route
  // Postconditions: Route is reversed in place; nothing returned
  void Route::ReverseRoute(){
    Airport* current = m_head;
    Airport* prev = nullptr;
    Airport* next = nullptr;

    while (current != nullptr){
      next = current->GetNext();
      current->SetNext(prev); 
      prev = current;
      current = next;
    }
    m_tail = m_head;
    m_head = prev;
  }
  // Name: GetData (int)
  // Desc: Returns an airport at a specific index
  // Preconditions: Requires a Route
  // Postconditions: Returns the airport from specific item
  Airport* Route::GetData(int index){
    Airport *temp = m_head;
    for (int i = 0; i < index; i++){
      if (temp != nullptr){
        temp = temp->GetNext();  
      }
    }
    return temp;
  }
  // Name: DisplayRoute
  // Desc: Displays all of the airports in a route
  // Preconditions: Requires a Route
  // Postconditions: Displays all of the airports in a route
  // Formatted: Baltimore, Maryland (N39.209 W76.517)
  void Route::DisplayRoute(){
    Airport *temp = m_head;
    int count = 0;
    while (temp != nullptr && count < m_size){
      cout << count + 1 << ". " << temp->GetCode() << ", " 
      << temp->GetName() << ", "
      << temp->GetCountry() << " ("
      << "N" << temp->GetNorth() << ", "
      << "W" << temp->GetWest() << ")" << endl;
      temp = temp->GetNext();
      count++;
    }
  }