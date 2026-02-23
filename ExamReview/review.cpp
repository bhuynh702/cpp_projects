#include <iostream>
#include <vector>
using namespace std;

// (A Hole is a simple class with a number, yardage, and par.)
class Hole { 
    public: 
    Hole() : m_number(0), m_yardage(0), m_par(0) {} 
    Hole(int number, double yardage, int par): m_number(number), m_yardage(yardage), m_par(par) {} 
    int GetNumber() {return m_number;} 
    double GetYardage() {return m_yardage;} 
    int GetPar() {return m_par;} 
    void SetNumber(int number) {m_number = number;} 
    void SetYardage(double yardage) {m_yardage = yardage;} 
    void SetPar(int par) {m_par = par;} 

    private: 
    int m_number; 
    double m_yardage; 
    int m_par; 
}; 

// Write the C++ code that builds a class called GolfCourse. 
// The golf course has normal constructors,  mutators, and accessors. 
// It has member variables that indicate its name, address, 
// and a vector of pointers to some number of Holes 

// Write the C++ code that creates the Rule of Three for the class above. 
// Destructor, Copy Constructor, Overloaded Constructor 
class GolfCourse { 
    public:
    GolfCourse(): m_name(""), m_address(""){}
    GolfCourse(string name, string address): m_name(name), m_address(address){}
    void SetName(string name){ m_name = name; }
    void SetAddress(string address){ m_address = address; }
    string GetName() { return m_name; }
    string GetAddress() { return m_address; }
    
    // Create a function  named “AddHole” that dynamically allocates 
    // a new Hole object and inserts it into the vector.
    void AddHole(int number, double yardage, int par){
        m_holes.push_back(new Hole(number, yardage, par));
    }

    private:
    string m_name;
    string m_address;
    vector<Hole*> m_holes;
};

// Destructor
GolfCourse::~GolfCourse(){
    for(int i = 0; i < (int)m_holes.size(); i++){
        delete m_holes[i];
        m_holes[i] = nullptr; 
    }
}
// Copy Constructor
GolfCourse::GolfCourse(const GolfCourse& rhs){
    m_name = rhs.m_name;
    m_address = rhs.m_address;
    for(int i = 0; i < (int)rhs.m_holes.size(); i++){
        m_holes.push_back(new Hole(rhs.m_holes[i]->GetNumber(), 
        rhs.m_holes[i]->GetYardage(), rhs.m_holes[i]->GetPar()));
    }
}
// Overloaded Operator 
GolfCourse& GolfCourse::operator=(const GolfCourse& rhs){
    if(this == &rhs){
        return *this;
    }
    m_name = rhs.m_name;
    m_address = rhs.m_address; 
    for(int i = 0; i < (int)m_holes.size(); i++){
        delete m_holes[i];
        m_holes[i] = nullptr; 
    }
    for(int i = 0; i < (int)rhs.m_holes.size(); i++){
        m_holes.push_back(new Hole(rhs.m_holes[i]->GetNumber(), 
        rhs.m_holes[i]->GetYardage(), rhs.m_holes[i]->GetPar()));
    }
    return *this;
}

int main () {
    // In main, allocate 18 holes into the golf course. 
    GolfCourse gc("UMBC", "1000 Hilltop Circle");
    int numHoles = 18; 
    
    for(int i = 0; i < numHoles; i++){
        gc.AddHole(i + 1, 200, 3);
    }



    return 0;
}