/*****************************************
 ** File:    lab4.cpp
 ** Project: CMSC 202 Lab 4, Spring 2024
 **
 ** Lab 4 involves passing data to void functions
 ** by reference and by using pointers.
 **
 ***********************************************/
#include<iostream>
using namespace std;

// Write Three Constants:
// Converter - Converts Kelvin to Celsius and Celsius to Kelvin
// Absolute zero of Kelvin
// Absolute zero of Celsius
double CONVERTER = 273.15;
int ZEROKEL = 0;
double ZEROCEL = -274.15; 

// Write two Function Prototypes for two functions described
void toCelsius(double &temperature);
void toKelvin(double *temperature);

//Main is provided
int main(){
  double temperature = 0.0; // Input for converting
  int choice = 0; // Menu choice

  cout << "Welcome to Temperature Conversion tool " << endl;
 
  do {
    cout << "Please select below: " << endl;
    cout << "1. Convert from Kelvin to Celsius" << endl;
    cout << "2. Convert from Celsius to Kelvin" << endl;
    cout << "3. Exit"<< endl;
    cin >> choice; 
    
    // Check for validation
    if (choice < 1 || choice > 3) {
      while (choice < 1 || choice > 3) {
        cout << "\nInvalid selection. Please re-enter: " << endl;
        cin >> choice;
      }
    }
    if (choice == 1){
      cout<<"\nTemperature in Kelvin: " ;
      cin >> temperature;
      toCelsius(temperature); //function call
      cout << "Temperature in Celsius: " << temperature << endl;
    }
    
    if (choice == 2){
      cout<<"\nTemperature in Celsius: " ;
      cin >> temperature;
      toKelvin(&temperature); //function call
      cout << "Temperature in Kelvin: " << temperature << endl;
    }
    
    cout << endl;
    
  }while(choice != 3);
  cout << "Have a good one!" << endl;  
  return 0;
}

// Write function toCelsius here
// Convert from Kelvin to Celsius using pass by reference
void toCelsius(double &temperature){
    temperature -= CONVERTER; 
    if (temperature < ZEROCEL){
      cout << "The temperature is below absolute zero." << endl;
    }
}


// Write function toKelvin here
// Convert from Celsius to Kelvin using pointers
void toKelvin(double *temperature){
    *temperature = *temperature + CONVERTER;
    if (*temperature < ZEROKEL){
      cout << "The temperature is below absolute zero." << endl;
    }
}