#include "Person.cpp"
#include "Student.cpp"
#include "Class1.cpp"
#include <vector>
#include <string>
using namespace std;

int main(){
    Student newStudent1;
    newStudent1.SetFName("Samwise");
    newStudent1.SetLName("Gamgee");
    newStudent1.SetStuID(12345);
    cout << "Full name: " << newStudent1.GetFName() << " " << newStudent1.GetLName() << endl;
    
    Class1 newClass;
    newClass.AddStudent(newStudent1);
    newClass.PrintClass();

    return 0;
}