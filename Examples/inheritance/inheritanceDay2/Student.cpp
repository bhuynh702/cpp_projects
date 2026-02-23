#ifndef STUDENT_CPP
#define STUDENT_CPP 
#include "Person.cpp"
#include <iostream>
#include <string>
using namespace std;

class Student: public Person { // child class which inherits from Person
    public:
        int GetStuID(){ // has StuID data unique to Student class 
            return m_stuID; 
        }
        void SetStuID(int stuID){
            m_stuID = stuID;
        }
    private:
        int m_stuID;
};

#endif