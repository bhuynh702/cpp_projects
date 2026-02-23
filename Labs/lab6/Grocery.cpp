#include "Grocery.h"
#include <iostream>
#include <string>
using namespace std;

Grocery::Grocery(){
    m_name = "";
    m_type = 0;
} 

Grocery::Grocery(string name, int type){
    SetName(name);
    SetType(type);
} //overloaded constructor

    //GetName() returns the grocery item's name
string Grocery::GetName(){
    return m_name;
}

    //GetType() returns the type of the grocery item
int Grocery::GetType(){
    return m_type;
}

    //SetName() sets m_name to name
void Grocery::SetName(string name){
    m_name = name;
}

    //SetType() sets m_type to type
void Grocery::SetType(int type){
    m_type = type;
}