#ifndef GAS_CPP
#define GAS_CPP
#include "Gas.h"
#include <iostream>
#include <string>
using namespace std; 

Gas::Gas(string name, int challenge): Planet(name, challenge){}

string Gas::GetType(){
    string gas = "gas";
    return gas;
}

#endif