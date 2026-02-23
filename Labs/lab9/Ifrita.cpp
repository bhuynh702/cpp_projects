#include "Ifrita.h"
#include <iostream> //Required library
#include <string> //Required library
using namespace std;

Ifrita::Ifrita(){
m_toxin = "";
}

Ifrita::Ifrita(string name, int age, string toxin):Bird(name, age){
m_toxin = toxin; 
}
  
void Ifrita::Display(){
cout << "Don't handle that Ifrita; they have " << m_toxin << " in their feathers and skin!" << endl;
}