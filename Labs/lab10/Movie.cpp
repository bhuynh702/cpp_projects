#ifndef MOVIE_CPP
#define MOVIE_CPP
#include "Movie.h"
#include <iostream>
using namespace std;

  // Constructor
  // Preconditions: None
  // Postconditions: None
Movie::Movie(){
    m_myTitle = "";
}
 
  // Destructor
  // Preconditions: None
  // Postconditions: None
Movie::~Movie(){
}
 
  // Overloaded Constructor
  // Preconditions: None
  // Postconditions: Member variables initialized
Movie::Movie(string name){
    m_myTitle = name;
    SetType("Movie");
}
 
  // CallMyName - Prints name
  // Preconditions: Has a name
  // Postconditions: None

void Movie::CallMyTitle(){
    cout << "I am a film named: " << m_myTitle << endl;
}
 
  // DescribeMe() - gives description of given movie
  // Preconditions: None
  // Postconditions: None
void Movie::DescribeMe(){
    cout << "I am a box office success!" << endl;
}

#endif