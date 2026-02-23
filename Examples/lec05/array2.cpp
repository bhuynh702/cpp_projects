/*Title: array2.cpp
Author: CMSC 202
Date: 9/12/2023
Description: This is practicing passing arrays to functions in c++.
*/
#include <iostream>
using namespace std;
 
// function prototype/declaration
double calcAverage(int arr[], int size);

int main () {
   // declare and initialize array with a size of 5
   int balance[5] = {50, 60, 70, 65, 53};
   double avg;//declare (notice it is NOT initialized) variable
			  //to hold calculated average

   // pass array and size to function
   avg = calcAverage( balance, 5 ) ;
 
   cout << "Average value is: " << avg << endl; //outputs to console
    
   return 0;
}

//function definition
double calcAverage(int arr[], int size) {
   int i = 0; //loop counter
   int sum = 0; //declare and initialize aggregator (holds the sum)       
   double avg = 0.0; //declare and initialize variable to hold calculated average

   for (i = 0; i < size; ++i) { //Loop over entire array
      sum += arr[i]; //aggregate total
   }

   avg = double(sum) / size; //calculates average (including casting as double)

   return avg; //returns a double from function
}