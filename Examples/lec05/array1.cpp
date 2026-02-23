/*Title: array1.cpp
Author: CMSC202
Date: 9/12/2023
Description: This is practicing arrays in c++.
*/
#include <iostream>
using namespace std;
const int NUM_NUMBERS = 5; //constant using the "const" keyword
#define NUM_NUMBERS2 5; //constant using preprocessor directives (not used)

int main() 
{
    int numbers[NUM_NUMBERS]; //declares a new array of size 5
	int sum = 0; //declares and initializes a new integer variable
    cout << "Enter " << NUM_NUMBERS << " numbers: "; //requests user input
    
    //  Storing 5 number entered by user in an array
    //  Finding the sum of numbers entered
    for (int i = 0; i < NUM_NUMBERS; ++i) //loops for each NUM_NUMBERS
    {
        cin >> numbers[i]; //stores input in array
        sum += numbers[i]; //aggregates input in variable
    }
    
    cout << "Sum = " << sum << endl;  //console output the sum  
    return 0;
}