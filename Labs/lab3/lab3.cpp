/*****************************************
 ** File:    lab3.cpp
 ** Project: CMSC 202 Lab 3, Spring 2024
 **
 ** Lab 3 involves using arrays. In this file you need to
 ** implement the getLargestNum() and getAverageNum() functions. 
 ** The implementation of getTotalNum() is provided. 
 ***********************************************/

#include <iostream>
using namespace std;

// Global Constants
const int NUM_DAYS = 7; // Number of days in the week
const int NUM_HOURS = 24; // Max hours in a day

// Function Name: getLargestNum
// Pre-conditions: Requires an array
// Post-conditions: Returns the largest number in the array
int getLargestNum(int[]);

// Function Name: getTotalNum
// Pre-conditions: Requires an array
// Post-conditions: Returns the cumulative number in the array
int getTotalNum(int[]);

// Function Name: getAverageNum
// Pre-conditions: Requires an array
// Post-conditions: Returns the average number in the array
double getAverageNum(int[]);

// Implement main here
int main() {
  // Declare array (hours)
    int hours[NUM_HOURS] = {0};
  // Declare necessary variable
  // Prompt the user for hours spent online each day for every day of the week
    for (int i = 0; i < NUM_DAYS; ++i) {
        cout << "Enter screentime for day " << i + 1 << ":" << endl;
        cin >> hours[i];
        
        while(hours[i] < 0 || hours[i] > NUM_HOURS) {
        cout << "Try again with a number between 0 and 24: " << endl;
        cin >> hours[i]; 
        }

     }
    // Check for valid input (non-negative and below max hours in a day)

      // Otherwise, insert the input into the array
    
  // Display results with function calls
  getLargestNum(hours);
  getTotalNum(hours);
  getAverageNum(hours);
  
  return 0;
}

// Implement getLargestNum here
// Function that returns the largest number in an array
int getLargestNum(int hours[]) {
    int max_num = 0;
    for (int i = 0; i < NUM_HOURS; ++i) {
        if(max_num < hours[i]){
            max_num = hours[i];
        }
    }
    cout << "Most amount of time spent in one day: " << max_num << endl; 
    return max_num; 
    
}

// Implementation of function to calculate and return the total time
// getTotalNum is provided
int getTotalNum(int array[]) {
  int total = 0;

  // Calculate the total time
  for (int i = 0; i < NUM_DAYS; i++) {
    total += array[i];
  }
cout << "Total time spent in the week: " << total << endl;
  return total;
  
}

// Implement getAverageNum() here
// Function that returns the average number in an array
// Hint: Remember that you can use getTotalNum in this function 
// Hint: What does this function return? How do we ensure that happens?
double getAverageNum(int hours[]){
    int total = getTotalNum(hours);
    double avg = double(total) / NUM_DAYS;
    
    cout << "Average time spent per day: " << avg << endl;
    return avg;
    
}