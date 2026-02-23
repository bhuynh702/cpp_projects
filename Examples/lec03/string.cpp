/*Title: string
Author: CMSC 202
Date: 9/6/2023
Description: This is practicing strings in c++.
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main () {
  string password1 = "password1";
  string input1 = "";

  //Method 1 - using strings
  cout << "Method 1 - Using Strings" << endl;
  cout << "Enter the password:" << endl;
  cin >> input1;
  if(password1 == input1){
    cout << "You are in the system" << endl;
  }else{
    cout << "Password1 failed." << endl;
  }

  //Method 2 - using c-string
  char password2[] = "password2";
  char input2[80];
  cout << "Method 2 - Using C-Strings" << endl;
  cout << "Enter the password2:" << endl;
  cin >> input2;
  if(!strcmp(password2, input2)){ //If same returns 0 if password2 > input2 returns <0 if password2 < input2 returns >0
    cout << "You are IN the system" << endl;
  }else{
    cout << "Password2 failed" << endl;
  }


  //Method 3 - using c-string and string
  string password3 = "password3";
  char input3[80];

  cout << "Method 3 - Comparing cstring and string" << endl;
  cout << "Enter the password:" << endl;
  cin >> input3;
  if(password3 == input3){
    cout << "You are in the system" << endl;
  }else{
    cout << "Password3 failed." << endl;
  }


  return 0;
}
