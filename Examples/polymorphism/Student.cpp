#ifndef STUDENT_CPP
#define STUDENT_CPP 
#include "Person.cpp"
#include <iostream>
#include <string>
using namespace std;

class Student: public Person{
    public:
    void Print(){
        cout << "Student: " << Getfname() << " " << Getlname() << endl;
    }
    private:
};

#endif