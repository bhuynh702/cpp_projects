  /*Title: File I/O
Author: CMSC 202
Date: 9/11/2023
Description: This is practicing file I/O in c++.
*/
#include <iostream>
#include <fstream> //Required to open/close and read a file
#include <string> //Required to use a string
using namespace std;

int main () {
    string firstName; //Declaration of a string
    string lastName; //Declaration of a string
    int age;
    ifstream myfile ("example.txt"); //Declares new var and opens a file
    
    if (myfile.is_open()) { //Checks to see if the file exists and was opened
      while(myfile >> firstName){ //Keeps reading a name as long as there is another line
        myfile >> lastName >> age; //Reads the rest of the line
        cout << "Your name is: " << firstName << " " << lastName << endl; //Outputs the first and last names
        cout << "You are: " << age << " years old." << endl; //Outputs the age
      }
    }else {
      cout << "Unable to open file" << endl; //If the input file does not exist, notifies user
    }
      myfile.close(); //Closes the file
  return 0;
}