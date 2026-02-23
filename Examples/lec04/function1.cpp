/*Title: function1
Author: CMSC 202
Date: 9/11/2023
Description: This is practicing functions in c++.
*/
#include <iostream>
using namespace std;

//Function Prototype or Function Declaration
int addition (int a, int b); //Function Signature would be addition(int, int)

//Our main function
int main ()
{
  int z; //integer declaration
  z = addition (1,3); //Call to function
  cout << "The result is " << z << endl; //Output to console
}

//Function Definition
int addition (int a, int b) //Notice - must match prototype/declaration
{
  int r; //integer declaration
  r = a + b; //arithmetic operation
  return r; //returns integer from function call
}