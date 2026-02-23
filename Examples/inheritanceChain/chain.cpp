/*
This is an example of inheritance with multiple subclasses. 
*/
#include <iostream>
#include <string>
using namespace std;

class Instrument{ // parent class 
    public:
        Instrument(){ // default constructor 
            cout << "Instrument (default)" << endl;
            m_name = "blah";
        }
        Instrument(string name){
            cout << "Instrument: " << name << endl;
            m_name = name;
        }
    private: 
        string m_name;
};

class Woodwind: public Instrument{ // child class
    public:
    Woodwind(){
        m_NumReeds = 0;
    }
    Woodwind(string name, int NumReeds): Instrument(name){ // must inherit Instrument here if
    // you want to use the code from parent class 
        cout << "Woodwind: " << name << endl;
        m_NumReeds = NumReeds;
    }
    private:
    int m_NumReeds;
};

class Oboe: public Woodwind{ // grandchild class 
    public:
        Oboe(string name, int NumReeds, string type): Woodwind(name, NumReeds){
            cout << "Oboe: " << name << endl;
            cout << "Type: " << type << endl;
        }
    private:
        string m_type;
};

int main(){
    Woodwind myInstrument("Saxophone", 1); 
    Oboe myOboe("Ol' Reliable", 2, "Soprano");

    return 0;
}