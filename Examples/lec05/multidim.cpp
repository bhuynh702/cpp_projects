/*Title: multidim.cpp
Author: CMSC 202
Date: 9/12/2023
Description: This is practicing using multidimensional arrays in c++.
*/
#include <iostream>
using namespace std;

const int x = 2; //constant for x axis
const int y = 3; //constant for y axis
//This is NOT consistent in computer science - not always identical to math

int main () {
  int test[x][y] = {2, 4, -5, 9, 0, 9}; //one way to declare multidimensional
  int test2[x][y] = { {2, 4, -5}, {9, 0, 9}}; //another way to declare 
                                            // multidimensional (little better)
  
  for(int i = 0; i < x; i++){ //outer loop
    for(int j = 0; j < y; j++){ //inner loop
      cout << test2[i][j] << " "; //output
    }
    cout << endl; //line break
  }
  return 0;
}