#include <iostream>
using namespace std;

int main () {
  int a = 10;
  int b = 20;

  double c = 5.5;
  double d = 7.9;

  int intTotal = 0;
  double doubleTotal = 0.0;

  cout << "a / b = " << a / b << endl; //What is the expected output?
  cout << "a / c = " << a / c << endl; //What is the expected output?

  intTotal = a / b;
  cout << "(intTotal)a / b = " << intTotal << endl; //Displays a single 0

  doubleTotal = a / b;
  cout << "(doubleTotal)a / b = " << doubleTotal << endl; //Only displays a single 0 with no 0.0

  doubleTotal = a + b + c * d;
  cout << "(doubleTotal) a + b + c *d = " << doubleTotal << endl;
  
  return 0;
}
