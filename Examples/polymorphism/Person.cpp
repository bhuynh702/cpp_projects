#ifndef PERSON_CPP
#define PERSON_CPP
#include <iostream>
#include <string>
using namespace std;

class Person{
    public:
    string Getfname(){ return m_fname; }
    string Getlname(){return m_lname;} 
    void Setfname(string name){m_fname = name;}
    void Setlname(string name){m_lname = name;}
    virtual void Print(){
        cout << "Person: " << m_fname << " " << m_lname << endl;
    }
    private: 
    string m_fname;
    string m_lname;
};

#endif