#include "Penguin.h"
#include <iostream>
#include <string>
using namespace std;

Penguin::Penguin(){ //Default constructor
m_diveDepth = 0;
}            
  
Penguin::Penguin(string name, int age):Bird(name, age){//Name, Age
m_diveDepth = rand() % MAX_DIVE;
}  

int Penguin::GetDiveDepth(){
return m_diveDepth;
}     
  
void Penguin::SetDiveDepth(int diveDepth){
m_diveDepth = diveDepth;    
}
  
void Penguin::Dive(){
cout << "The Penguin dives " << m_diveDepth << " meters!" << endl;
} 
