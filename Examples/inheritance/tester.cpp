#ifndef TESTER_CPP
#define TESTER_CPP
#include <iostream>
#include <string>
using namespace std;

// Build a parent class fruit 
class Fruit{
    public:
    Fruit(){
        m_name = "";
    }
    Fruit(string name){
        cout << "Fruit: " << name << endl;
        m_name = name;
    }
    private:
    string m_name;
};

// Build a child class citrus that inherits from fruit 
class Citrus: public Fruit{
    public:
    Citrus(){
        m_color = "";
    }
    Citrus(string name, string color):Fruit(name){
        cout << "Citrus Fruits: " << name << endl;
        m_color = color;
    }
    string GetColor(){
        return m_color;
    }
    private:
    string m_color;
};

int main(){
    Citrus newFruit("Orange", "Orange");
    cout << "Color: " << newFruit.GetColor() << endl;

    return 0;
}

#endif