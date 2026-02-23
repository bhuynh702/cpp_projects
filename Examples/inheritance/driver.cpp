#include "Person.cpp"
#include "Student.cpp"

int main(){
    Person newPerson; // build a new Person object (parent class)
    newPerson.SetFName("Brittany");
    newPerson.SetLName("Huynh");
    cout << "Person name: " << newPerson.GetFName() << " " << newPerson.GetLName() << endl;

    Student newStudent; // build a new Student object (child class)
    newStudent.SetFName("Joshua"); // uses setters from Person.cpp
    newStudent.SetLName("Dodd"); // child class can only access public members of parent class
    cout << "Student name: " << newStudent.GetFName() << " " << newStudent.GetLName() << endl;

    newStudent.SetStuID(1101);
    cout << "Student ID: " << newStudent.GetStuID() << endl;
    return 0;
}