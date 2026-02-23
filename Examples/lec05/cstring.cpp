/*Title: cstring.cpp
Author: CMSC 202
Date: 9/12/2023
Description: This is practicing cstrings in c++.
*/

#include <iostream> //This is the Standard Input / Output Streams Library
#include <cstring> //This is the cstring library to compare two cstrings
using namespace std; //This is the namespace for our code

int main () { //This is our required, main function in C++

  char myString[] = "This is the first cstring"; //This builds a cstring
  cout << myString << endl;

  char myString2[80] = "This is a second cstring"; //This builds a cstring
  cout << myString2 << endl;

  if(strcmp(myString,myString2)) //Needed to compare 2 cstrings in <cstring>
    cout << "Different" << endl;
  else
    cout << "Same" << endl;

  char newString1[] = "test1";
  char newString2[] = "test1";

  if(strcmp(newString1, newString2)) //We should NOT use newString1 == newString2
    cout << "Different" << endl; //It will compile but give us unexpected output
  else
    cout << "Same" << endl;

  const char* myString3 = "This is a third cstring"; //This also builds a constant cstring but we will learn later
  cout << myString3 << endl;

  char myString4[5]; //What is this being set to?
  for(int i = 0;i < 6; i++){
    cout << myString4[i];
  }
  cout << endl;

  return 0;
}
