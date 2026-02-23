//
//  main.cpp
//  if-else-statements
//
//  Created by Brittany Huynh on 2/6/24.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // basic if-else if-else example:
    // keep the order of your if statements in mind,
    // go from most specific to the more general
    int x, y;
    cout << "Tell me an integer: ";
    cin >> x;
    cout << "Tell me another integer: ";
    cin >> y;
    
    if (x > 0 && y > 0)
    {
        cout << "both are positive" << endl;
    }
    else if (x > 0 || y > 0)
    {
        cout << "one is positive" << endl;
    }
    else
    {
        cout << "both are non-positive" << endl;
    }
    // Here's an example of nesting:
    string answer;
    cout << "Do you work at the Krusty Krab? ";
    cin >> answer;
    
    if (answer == "yes")
    {
        cout << "Do you own it? ";
        cin >> answer;
        if (answer == "yes")
        {
            cout << "You are Mr. Krabs." << endl;
        }
        else
        {
            cout << "Are you very grumpy? " << endl;
            cin >> answer;
            if (answer == "yes")
            {
                cout << "You are Squidward." << endl;
            }
            else
            {
                cout << "You are Spongebob." << endl;
            }
        }
    }
    else
    {
        cout << "You are Sandy." << endl;
        
        
        // This is a simple switch statement
        int choice = 0;
        cout << "Welcome to Candy Land" << endl;
        cout << "What kind of candy would you like?" << endl;
        cout << "1. Sweet" << endl;
        cout << "2. Chocolate" << endl;
        cout << "3. Sour" << endl;
        cin >> choice;
        
        switch (choice){
            case 1:
                cout << "You wanted sweet." << endl;
                break;
            case 2:
                cout << "You wanted chocolate." << endl;
                break;
            case 3:
                cout << "You wanted sour." << endl;
                break;
            default:
                break;
        }
        cout << "Thank you for visiting Candy Land!" << endl;
        return 0;
        
    }
}