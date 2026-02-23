#include <iostream>
#include <string>
using namespace std;

struct movie
{
   string title;
   int year;
   string director;
};

class Rectangle {
  int width, height; //Private by default
 public: //Specifying that these are public
  void SetValues (int,int); //Public Function
  int CalcArea () {return width*height;} //Public Function
} rect;

void Rectangle::SetValues(int x, int y){
  width = x;
  height = y;
}

int main ()
{
  movie movie1; //Creates a new movie with struct

  movie1.title = "Snowden"; //Sets name
  movie1.year = 2016; //Sets year
  movie1.director = "Oliver Stone"; //Sets director
  cout << movie1.title << " was directed by "
       << movie1.director << " in " 
       << movie1.year << "." << endl; //Outputs

  rect.SetValues(10, 5);
  cout << "The area is: " << rect.CalcArea() << endl;
  return 0;
}


