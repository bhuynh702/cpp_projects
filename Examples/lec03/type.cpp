/*Title: Type Casting and Short Hand
Author: CMSC 202
Date: 9/6/2023
Description: This is practicing type casting and short hand in c++.
*/

#include <iostream> //This is the Standard Input / Output Streams Library
using namespace std; //This is the namespace for our code

int main () {
  cout << "17/5.5 = " << (17/5.5) << endl; //Type Cast - Implicit
  char newChar = '10'; //Type Cast - Explicit
  cout << (newChar) << static_cast<int>(newChar) << endl; //What did this output?
  //It cast the character '0' to it's ascii value of 048

  //Incrementer Example
  int intA = 10;
  cout << "intA++ == intA++ = " << (intA++ == intA++) << endl;
  cout << "intA = " << intA << endl;
  cout << "++intA == intA++ = " << (++intA == intA++) << endl;
  cout << "intA = " << intA << endl;
  return 0;
}
