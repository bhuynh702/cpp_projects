//
//  main.cpp
//  Lab02
//
//  Created by Brittany Huynh on 2/12/24.
//

#include <iostream> //Library import
using namespace std; //Defining namespace for std

//double addTwo(double, double); //Function Prototype
//
//int main () {
//  double d = 4.0; //Declare and Initialize double
//  double e = 2.5; //Declare and Initialize double
//  cout << addTwo(d, e) << endl; //Function Call
//  return 0;
//}
//
//double addTwo(double val1, double val2){ //Header
//    return (val1+val2); //Function Body
//}

int sumOfInts();
void divisibleByThree(int num);

int main () {
    divisibleByThree(sumOfInts());
}

int sumOfInts() {
    int ints = 0;
    
    cout << "How many ints would you like to add together? " << endl;
    cin >> ints;
    
    int entered = 0, sum = 0, count = 0;
    do{
        
        cout << "Enter an int: " << endl;
        cin >> entered;
        sum += entered;
        count++;
    }while(count < ints);
        cout << "Sum: " << sum << endl;
    return sum;
}

void divisibleByThree(int num) {
    if(num % 3 == 0) {
        cout << num << " is divisible by 3!" << endl;
    }
    else {
        cout << num << " is not divisible by 3." << endl;
    }
}