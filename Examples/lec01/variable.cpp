/*
** Title: variable.cpp
** Author: Jeremy Dixon
** Date: 8/30/2023
** Description: This introduces variables in C++
** Course/Section: CMSC 202
*/

#include <iostream> //includes cin and cout
#include <string> //includes string
using namespace std;

int main () {
  int age = 10; //declare an integer variable and initialize to 10
  cout << "What is your age?" << endl;
  cin >> age;
  cout << "You are " << age << " years old" << endl;

  char myChar = ' ';
  bool isHappy = true;
  double myMoney = 100.01;
  string myName = "Jeremy Dixon";
  
  return 0;
}
