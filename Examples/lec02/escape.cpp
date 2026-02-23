/*Title: escape.cpp
Author: CMSC 202
Date: 9/1/2023
Description: This is practicing escape sequences output in c++.
*/

#include <iostream> //This is the Standard Input / Output Streams Library
using namespace std; //This is the namespace for our code

int main () { //This is our required, main function in C++
  int num1 = 10;
  int num2 = 20;
  int num3 = 30;
    cout << num1 << num2 << num3 << endl; //Output without tabs
  cout << "\t" << num1 << "\t" << num2 << "\t" << num3 << "\n"; //Creates a table of data with a new line
  cout << "\a\n"; //Outputs bell and a new line

  return 0;
}
