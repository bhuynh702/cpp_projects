#ifndef CLASS1_CPP
#define CLASS1_CPP
#include <vector>
#include <string>
#include "Student.cpp"
#include "Person.cpp"
using namespace std;

class Class1{
    public:
    void PrintClass(){
        for(unsigned int i = 0; i < m_class.size(); i++){
            cout << i + 1 << ". " << m_class.at(i).GetLName() << endl;
        }
    }
    void AddStudent(Student newStudent){
        m_class.push_back(newStudent);
    }
    private:
    vector<Student> m_class;
};


#endif