/*Title: Precision
Author: CMSC 202
Date: 9/1/2023
Description: This is practicing arithmetic precision in c++.
*/
#include <iostream>
using namespace std;

int main () {
  double myDouble = 10.0/3; //This one is interesting - it should be 3.33333 (repeating)
  cout << myDouble << endl;
  myDouble = myDouble * 3; //What does C++ do when you multiply 3.33333 * 3? Does it display 10 or 9.99999?
  cout << myDouble << endl;
  return 0;
}
