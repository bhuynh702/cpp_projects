/*Title: switch.cpp
Author: CMSC 202
Date: 9/6/2023
Description: This is practicing a simple switch statement in c++.
*/
#include <iostream>
using namespace std;

int main () {
  int choice = 0;
  cout << "Welcome to Candy Land" << endl;
  cout << "What kind of candy would you like?" << endl;
  cout << "1. Sweet" << endl;
  cout << "2. Chocolate" << endl;
  cout << "3. Sour" << endl;
  cin >> choice;

  switch (choice){
  case 1:
    cout << "You wanted sweet" << endl;
    break;
  case 2:
    cout << "You wanted chocolate" << endl;
    break;
  case 3:
    cout << "You wanted sour" << endl;
    break;
  default:
    break;
  }
  cout << "Thank you for visiting Candy Land" << endl;
  return 0;
}
