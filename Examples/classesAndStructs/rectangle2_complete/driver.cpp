/*Title: driver.cpp
Author: CMSC 202
Date: 9/25/2023
Description: This is building a Rectangle using a class in c++.
*/
#include "Rectangle.h"

int main () {
  Rectangle a; //builds a new Rectangle
  a.SetHeight(10); //Sets Rectangle height to 10
  a.SetWidth(5); //Sets Rectangle width to 5
  cout << "Height = " << a.GetHeight() << endl; //Outputs height
  cout << "Width = " << a.GetWidth() << endl; //Outputs width
  cout << "Area = " << a.CalcArea() << endl; //Outputs Calculated area
  cout << "Perimeter = " << a.CalcPerimeter() << endl; //Outputs Calculated perimeter
  a.RotateSides(); //Rotates the sides
  cout << "Height = " << a.GetHeight() << endl; //Outputs height
  cout << "Width = " << a.GetWidth() << endl; //Outputs width
  //The next line outputs if the Rectangle is a square or not using a ternary operator
  cout << "This Rectangle is " <<(a.IsSquare()?"":"not") << " a square" << endl;

  Rectangle b(10, 5); //builds a new Rectangle
  cout << "Height = " << b.GetHeight() << endl; //Outputs height
  cout << "Width = " << b.GetWidth() << endl; //Outputs width
  cout << "Area = " << b.CalcArea() << endl; //Outputs Calculated area
  cout << "Perimeter = " << b.CalcPerimeter() << endl; //Outputs Calculated perimeter
  a.RotateSides(); //Rotates the sides
  cout << "Height = " << b.GetHeight() << endl; //Outputs height
  cout << "Width = " << b.GetWidth() << endl; //Outputs width
  //The next line outputs if the Rectangle is a square or not using a ternary operator
  cout << "This Rectangle is " <<(b.IsSquare()?"":"not") << " a square" << endl;

  return 0;
}
