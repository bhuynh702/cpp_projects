//
//  main.cpp
//  loops_lecture

//  In this file we explore for and while loops

//  Created by Brittany Huynh on Thu Feb 8 2024


#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include <ctime>
using namespace std;

void ex1() {
    // for loop
    int j = 0;
    for (int i = 1; i <= 10; i++)
        cout << i << " ";
    j++;
    cout << j << endl;
    
    // while loop
    string something;
    cin >> something;
    while(something != "quit") {
        cin >> something;
    }
    do {
        cout << "Enter quit to stop: ";
        cin >> something;
    } while(something != "quit");
    
    // break keyword
    while(true) {
        cout << "Enter quit to exit: " << endl;
        cin >> something;
        if (something == "quit")
            break;
    }
    
    // continue keyword
    int total = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i % 2){
            continue;
        }
        total += i;
    }
    cout << "The total is: " << total << endl;
    
    cin >> something;
    while(something != "quit")
    {
        if (something == ""){
            continue;
        }
        else if (something[0] == 'a'){
            cout << "A is a vowel" << endl;
        }
        else if (something[0] == 'b') {
            cout << "B is a consonant" << endl;
        }
        cin >> something;
    }
}

void ex2() {
       
}

int main () {
    ex1();
    return 0;
}