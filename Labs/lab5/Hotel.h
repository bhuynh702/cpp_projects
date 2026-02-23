/***************************************************************
** Topic: Lab 5
** File: Hotel.h
** Description: This file contains the Hotel class declaration
***************************************************************/

#ifndef HOTEL_H //Header Guards
#define HOTEL_H //Header Guards

#include <iostream>
#include <string>
using namespace std;


// Declare the Hotel class here
// Make sure to include a generic constructor,
// getters and setters for all member variables,
// and the functions described in the document

class Hotel {
public:
  //Constructor for Hotel
Hotel();
  //Getters
  //Getter for Rooms Available
int GetRooms();
  //Getter for Suites Available
int GetSuites();
  //Getter for Room Price
double GetRoomPrice();
  //Getter for Suite Price
double GetSuitePrice();
  //Getter for Revenue
double GetRevenue();

  //Setters
  //Sets Number of Rooms Available
void setRooms(int rooms);
  //Sets Number of Suites Available
void setSuites(int suites);
  //Sets Room Price
void setRoomPrice(double roomPrice);
  //Sets Suite Price
void setSuitePrice(double suitePrice);
  //Sets Total Revenue
void setRevenue(double revenue);
  
  //Other
  //Sell Room
void SellRoom();

  //Sell Suite
void SellSuite();
  //Sell All
void SellAll();
  
//Declare five member variables
//(room count, suite count, room price, suite price, revenue)
private:
  int m_rooms;
  int m_suites;
  double m_roomPrice;
  double m_suitePrice;
  double m_revenue;

};

#endif //End of Header Guards
