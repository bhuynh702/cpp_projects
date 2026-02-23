#ifndef PAINTING_CPP
#define PAINTING_CPP
#include "Painting.h"
#include <iostream>
using namespace std;

  // Constructor
  // Preconditions: None
  // Postconditions: None
Painting::Painting(): m_myTitle(""){
}
 
  // Destructor
  // Preconditions: None
  // Postconditions: None
Painting::~Painting(){
}
 
  // Overloaded Constructor
  // Preconditions: None
  // Postconditions: Member variables initialized
Painting::Painting(string title){
  m_myTitle = title;
  SetType("Painting");
}
 
  // callMyName - Prints name
  // Preconditions: Has a name
  // Postconditions: None
void Painting::CallMyTitle(){
    cout << "I am a beautiful painting named: " << m_myTitle << endl;
}
 
  // describeMe() - gives description of given painting
  // Preconditions: None
  // Postconditions: None
void Painting::DescribeMe(){
    cout << "I am made of oil on a canvas and look like I belong in a museum." << endl;
}

#endif