/*Title: Formatting output
Author: CMSC 202
Date: 9/1/2023
Description: This is practicing formatting output in c++.
*/

#include <iostream> //This is the Standard Input / Output Streams Library
#include <iomanip>
using namespace std; //This is the namespace for our code

int main () { //This is our required, main function in C++

  char myString[] = "This is the first";
  cout << myString << endl;

  double price = 55.13; //Declaration and initialization of a double
  double tax = 0.06; //Declaration and initialization of a double
  double total = price * (1+tax); //Declaration and initialization of a double
  cout << "The total is $" << total << endl; //Outputting without formatting
  cout.setf(ios::fixed); //Changing formatting of cout
  cout.setf(ios::showpoint);
  cout.precision(2);
  cout << "The formatted total is $" << total << endl; //Outputting with formatting
  return 0;
}
