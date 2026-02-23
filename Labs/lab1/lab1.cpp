//
// Author: Brittany Huynh
// Email: bhuynh4@umbc.edu
// Date: 02/08/2024
// Description: This is the first lab for CMSC202 SP24


#include <iostream>
#include <string>
using namespace std;

int main () {
    
    int age = 0; // Intializing variable int age to 0
    string name;
    
    cout << "What is your dog's name?" << endl;
    getline(cin, name);
    
    cout << "What is your dog's age? " << endl;
    cin >> age;
    while(age < 0 || age > 25)
    {
        cout << "Try again with a number between 0 and 25." << endl;        
        cout << "What is your dog's age? " << endl;
        cin >> age;
    }
    
    int count = 0; // to track valid choices
    int answer = 0;
    do{
        cout << "What would you like to do?" << endl;
        cout << "1. Play fetch with " << name << endl;
        cout << "2. Feed " << name << endl;
        cout << "3. Pet " << name << endl;
        cin >> answer;
        if(answer < 1 || answer > 3){ // invalid choice
            cout << "Your answer should be between 1 and 3. " << endl;
        }
        else { // valid choices
            count++; // track my valid choices
            // What will happen if my valid choice is 1?
            if(answer == 1) {
                cout << name << " gets the stick and returns to you!" << endl;
            }
            // What will happen if my valid choice is 2?
            else if(answer == 2){
                cout << name << " hungrily eats their food." << endl;
            }
            else if(answer == 3){
                cout << "You happily pet " << name << endl;
            }
            // What will happen if my valid choice is 3?
        }
    }while(count < 3); // do all of the above while the count is less than 3, so it will execute 3 times
    cout << "You are a great pet owner! Good-bye." << endl;
    return 0;
}




