#include "Person.cpp"
#include "Student.cpp"
#include <vector>

int main(){
    Person * newPerson = new Person();
    newPerson->Setfname("Brittany");
    newPerson->Setlname("Huynh");

    Person * newStudent = new Student();
    newStudent->Setfname("Joshua");
    newStudent->Setlname("Dodd");

    vector<Person*> newVector;
    newVector.push_back(newPerson);
    newVector.push_back(newStudent);
    for(unsigned int i = 0; i < newVector.size(); i++){
        cout << newVector.at(i)->Print() << " ";
    }

    return 0;
}