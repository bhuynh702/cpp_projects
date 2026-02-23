/*Title: Incrementers
Author: CMSC 202
Date: 9/6/2023
Description: This is practicing incrementers in c++.
*/

#include <iostream>
using namespace std;

int main () {
  int a = 0;
  int b = 0;
  a = a++;
  b = ++b;
  cout << "a=" << a << endl;
  cout << "b=" << b << endl;

  return 0;
}