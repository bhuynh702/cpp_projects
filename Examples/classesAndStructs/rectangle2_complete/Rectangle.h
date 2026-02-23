/*Title: Rectangle.h
Author: CMSC202
Date: 9/25/2023
Description: This is the header file for the Rectangle class in c++.
*/
#ifndef RECTANGLE_H //header guard
#define RECTANGLE_H //header guard
#include <iostream>
using namespace std;

class Rectangle {
 public: // These are the public member functions
  Rectangle(); //Default constructor
  Rectangle(double height, double width); //Overloaded constructor
  double GetHeight(); //Accessor for height
  double GetWidth(); //Accessor for width
  void SetHeight(double height); //Mutator for height
  void SetWidth(double width); //Mutator for width
  double CalcArea(); //Calculates and returns area
  double CalcPerimeter(); //Calculates and returns perimeter
  bool IsSquare(); //Checks to see if the Rectangle is square
  void RotateSides(); //Switchs m_height and m_width
 private:
  double m_height; //Private member variable for height
  double m_width; //Private member variable for width
};

#endif //header guard
