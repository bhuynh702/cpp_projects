#include <iostream> 
#include <string>
#include <vector>
using namespace std;

class Teacher{ 
    public:
    Teacher(string name): m_name(name){} // initialization list to set m_name to name
    string GetName(){
        return m_name; 
    }
    private:
    string m_name;
};

class Department{
    public:
    Department(){};

    void Add(Teacher *teacher){
        m_teacher.push_back(teacher);
    }

    friend ostream& operator << (ostream &out, const Department &dept){
        cout << "Department: " << endl;
        for (unsigned int i = 0; i < dept.m_teacher.size(); i++){
            cout << dept.m_teacher[i]->GetName() << " ";
        }
        return out;
    }
    private:
    vector <Teacher*> m_teacher;
};

int main(){
    Teacher *t1 = new Teacher("Abdul");
    Teacher *t2 = new Teacher("Jane");
    Teacher *t3 = new Teacher("Sammy");

    Department dept;
    Department dept2;

    dept.Add(t1);
    dept.Add(t2);
    dept.Add(t3);

    dept2.Add(t2);

    cout << dept << endl;
    cout << dept2 << endl;

    delete t1;
    delete t2;
    delete t3;

    return 0;
}