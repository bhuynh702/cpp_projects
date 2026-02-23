/*Title: Variables
Author: CMSC 202
Date: 8/30/2023
Description: This is practicing variables in c++.
*/

#include <iostream> //This is the Standard Input / Output Streams Library
using namespace std; //This is the namespace for our code

int main () { //This is our required, main function in C++
  int newInteger; //This declares a new integer variable with garbage in it
  int newInteger2 = 0; //This declares a new integer variable with a 0 in it
  char newChar; //This declares a new character variable with garbage in it
  char newChar2 = 'C'; // This declares a new character variable with a 'C' in it
  bool newBool; //This declares a new boolean variable with garbage in it
  bool newBool2 = true; //This declares a new boolean variable with true in it
  bool newBool3 = 0.001; //This declares a new boolean variable with true in it
  bool newBool4 = "false";
  
  cout << "newInteger= " << newInteger << endl;
  cout << "newInteger2= " << newInteger2 << endl;
  cout << "newChar= " << newChar << endl;
  cout << "newChar2= " << newChar2 << endl;
  cout << "newBool= " << newBool << endl;
  cout << "newBool2= " << newBool2 << endl;
  cout << "newBool3= " << newBool3 << endl;
  cout << "newBool4= " << newBool4 << endl;
  return 0; 
}
