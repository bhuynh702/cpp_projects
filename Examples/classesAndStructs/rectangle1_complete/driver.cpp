/*Title: driver.cpp
Author: CMSC202
Date: 9/25/2023
Description: This is building a Rectangle using a class in c++.
*/
#include "Rectangle.h"

int main () {
  Rectangle a; //builds a new rectangle
  a.SetHeight(10); //sets rectangle height to 10
  a.SetWidth(5); //sets rectangle width to 5
  cout << "Height = " << a.GetHeight() << endl; //Outputs height
  cout << "Width = " << a.GetWidth() << endl; //Outputs width
  cout << "Area = " << a.CalcArea() << endl; //Outputs calculated area
  cout << "Perimeter = " << a.CalcPerimeter() << endl; //Outputs calculated perimeter
  a.RotateSides(); //Rotates the sides
  cout << "Height = " << a.GetHeight() << endl; //Outputs height
  cout << "Width = " << a.GetWidth() << endl; //Outputs width
  //The next line outputs if the rectangle is a square or not using a ternary operator
  cout << "This rectangle is " <<(a.IsSquare()?"":"not") << " a square" << endl;
  return 0;
}
