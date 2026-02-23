#ifndef ART_CPP
#define ART_CPP
#include <iostream>
#include "Art.h"
using namespace std;

  // Constructor
  // Preconditions: None
  // Postconditions: None
Art::Art(){
    m_myType = "";
}
 
  // Destructor
  // Preconditions: None
  // Postconditions: None
Art::~Art(){    
}

  // getType() - returns myType
  // Preconditions: myType is initialized
  // Postconditions: None
string Art::GetType(){
    return m_myType;
}

void Art::CallMyType(){
    cout << "My type is: " << m_myType << endl;
}
 
  // setType() - sets value of myType
  // Preconditions: None
  // Postconditions: None
void Art::SetType(string type){
    m_myType = type;
}
 

#endif