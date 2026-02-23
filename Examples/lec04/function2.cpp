/*Title: function2
Author: CMSC 202
Date: 9/11/2023
Description: This is practicing using predefined libraries and functions in c++.
*/

#include <iostream>
#include <cmath> //library needed for "pow" function
using namespace std;

int rPow(int, int); //function prototype or declaration

int main () {
	//Example 1: Using predefined library
	int base = 0; //declaration and initialization - What to change for doubles?
	int exponent = 0; //declaration and initialization
	cout << "What is the base?" << endl; //user prompt
	cin >> base; //console input
	cout << "What is the exponent?" << endl; //user prompt
	cin >> exponent; //console input
	cout << base << " raised to the power of " << exponent << " is " 
		 << pow(base, exponent) << endl; //console output

	//Example 2: Using a recursive function
	cout << "What is the base?" << endl; //user prompt
	cin >> base; //console input
	cout << "What is the exponent?" << endl; //user prompt
	cin >> exponent; //console input
	
  	cout << base << " raised to the power of " << exponent << " is " 
		 << rPow(base, exponent) << endl; //console output with a recursive call
  return 0;
}

int rPow(int base, int exponent) { //recursive function
    if (exponent <= 0) //base case
		return 1;
    return base * rPow(base, --exponent); //recursive case
}