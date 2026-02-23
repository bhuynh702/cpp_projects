/*Title: Precision
Author: CMSC 202
Date: 9/1/2023
Description: This is practicing arithmetic precision in c++.
*/

#include <iostream> //This is the Standard Input / Output Streams Library
using namespace std; //This is the namespace for our code

int main () {
  int a = 10; //Declare and initialize the integer a to 10
  int b = 20; //Declare and initialize the integer b to 20
  int c = 30; //Declare and initialize the integer c to 30
  double d = 3.0; //Declare and initialize the double d to 3.0
  double total = 0.0; //Declare and initialize the double total to 0.0
  total = a + b + c * d; // Arithmetic calculation
  cout << "total = " << total << endl; //Output total
  cout << "a/d = " << a/d << endl; //Integer division or decimal division?
  cout << "(a/d)*d = " << (a/d)*d << endl; //Should it equal a? Be careful!
  return 0;
}
