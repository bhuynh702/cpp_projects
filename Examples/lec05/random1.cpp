/*Title: random1.cpp
Author: CMSC 202
Date: 9/12/2023
Description: This is introducing psuedorandom numbers in C++.
*/
#include <cstdlib> //Required for rand
#include <ctime> //Required for time
#include <iostream>
using namespace std;


int main () {
  srand(time(NULL)); //Seeds random number generator (psuedo)
  cout << time(NULL) << endl; //Outputs time value
  const int MIN = 30;
  const int MAX = 50;
  const int NUM_ITERATIONS = 10;
  cout << rand() << endl; //Outputs a random number
  for(int i = 0; i < NUM_ITERATIONS; i++){
    cout << rand() % (MAX - MIN + 1) + MIN << endl; //Outputs a random number in a range
  }
  return 0;
}