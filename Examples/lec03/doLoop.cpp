/*Title: Do While Loops
Author: CMSC 202
Date: 9/6/2023
Description: This is practicing do...while loops in c++.
*/

#include <iostream>
using namespace std;

int main () {
  int choice = 0; //Used for user input
  do{
    cout << "1. Attack Monster" << endl;
    cout << "2. Hug Puppy" << endl;
    cout << "3. Earn A" << endl;
    cin >> choice;
	(choice < 1 || choice > 3)?cout << "Must be between 1 and 3" << endl:cout << "Thank you" << endl; //Ternary Operator
  }while(choice < 1 || choice > 3); //checks to see if between 1 and 3
  cout << "You chose " << choice << endl;
  return 0;
}
