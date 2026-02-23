/*
This is an example of inheritance.
04/09/2024
*/
#ifndef PERSON_CPP
#define PERSON_CPP
#include <iostream>
#include <string>
using namespace std;

class Person{ // parent class 
    public:
        string GetFName(){
            return m_fName;
        }
        string GetLName(){
            return m_lName;
        }
        void SetFName(string fName){
            m_fName = fName;
        }
        void SetLName(string lName){
            m_lName = lName;
        }
    private:
        string m_fName;
        string m_lName; 
}; // don't forget semicolon at the end of class definition

#endif
