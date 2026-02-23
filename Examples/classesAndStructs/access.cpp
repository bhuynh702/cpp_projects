/*Title: access.cpp
Author: CMSC 202
Date: 9/25/2023
Description: This is showing class access modifiers (public and private) in c++.
*/

#include <iostream>
#include <cmath>
using namespace std;
 
class Circle {
public:
  void SetRadius( double rad ); //Setter (or mutator) - used to edit private member variables
  double GetArea( void ); //Another way of saying no parameters
private:
  double m_radius; //Private member variable
};

 
// Main function for the program
int main() {
  Circle circle;
 
  // set box length without member function
  circle.SetRadius(10.0); // OK: because setRadius is public
  //circle.m_radius = 10.0; // NOT OK: because m_radius is private
  cout << "Area of circle : " << circle.GetArea() <<endl;
 
  return 0;
}

// Member functions definition
double Circle::GetArea(void) { //Notice - do not pass member variables to member functions
  return M_PI*(m_radius*m_radius);
}
 
void Circle::SetRadius( double rad ) {
  if(rad<=0){ //Check to make sure the radius of the circle is less than or equal to 0
    cout << "The radius should be a positive double" << endl;
    cout << "Radius set to 1.0" << endl;
    m_radius = 1.0;
  }else{
    m_radius = rad;
  }
}