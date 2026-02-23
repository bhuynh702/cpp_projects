#include "Rectangle.h"

//Default constructor
Rectangle::Rectangle(){
  cout << "Rectangle created using default constructor" << endl;
}

//Overloaded constructor
Rectangle::Rectangle(double height, double width){
  cout << "Rectangle created using overloaded constructor" << endl;
  SetHeight(height);
  SetWidth(width);
}

//Returns m_height
double Rectangle::GetHeight(){
  return (m_height);
}

//Returns m_width
double Rectangle::GetWidth(){
  return m_width;
}

//Checks to make sure value is positive and updates m_height
void Rectangle::SetHeight(double height){
  if(height > 0)
    m_height = height;
  else
    m_height = 1;
}
  
//Checks to make sure value is positive and updates m_width
void Rectangle::SetWidth(double width){
  if(width > 0)
    m_width = width;
  else
    m_width = 1;
}

//Returns Calculated area of Rectangle
double Rectangle::CalcArea(){
  return (m_height*m_width);
}

//Returns Calculated perimeter of Rectangle
double Rectangle::CalcPerimeter(){
  return (m_height*2)+(m_width*2);
}

//Returns true if square else false
bool Rectangle::IsSquare(){
  return (m_height==m_width);
}

//Switchs m_height and m_width values
void Rectangle::RotateSides(){
  double temp = GetHeight();
  SetHeight(GetWidth());
  SetWidth(temp);
}
