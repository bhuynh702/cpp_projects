/*Title: scope.cpp
Author: CMSC 202
Date: 9/11/2023
Description: This is practicing block scope in c++.
*/
#include <iostream>
using namespace std;

int main() {
  int x = 3, y = 4; //Declares and initializes two outside ints
  { //Creates new code block
    int x = 7; //Declares an int inside the {}
    cout << "x in block is " << x << endl; //Uses the inside x
    cout << "y in block is " << y << endl; //Uses the outside x
  } //This makes the internal x go out of scope

  cout << "x in main is " << x <<  endl; //Uses the outside x
  
  return 0;
}
