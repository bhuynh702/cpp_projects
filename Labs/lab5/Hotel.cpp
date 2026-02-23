#include "Hotel.h"

/*************************************************************** 
** File: Hotel.cpp
** Description: This file contains the Hotel class function definitions
***************************************************************/

//Constructor - Already implemented for you
Hotel::Hotel() {
  cout << "It is your first day managing the Chesapeake Hall Hotel.\n";
  cout << "Time to sell some rooms!\n";
  m_revenue = 0; // money made so far
  m_rooms = 0; // rooms available
  m_roomPrice = 0; // price for a single room
  m_suites = 0; // suites available
  m_suitePrice = 0; // price for a single suite
}

//Implement Getters here
//(get suite count, room price, suite price, revenue)
double Hotel::GetRoomPrice(){
  return m_roomPrice;
}

double Hotel::GetSuitePrice(){
  return m_suitePrice;
}

double Hotel::GetRevenue(){
  return m_revenue:
}

//Getter for m_rooms already implemented for you
// int Hotel::GetRoomsCount() {
//   return m_rooms;
// }

//Implement Setters here
//(set suites count, room price, suite price, revenue)
  //Sets Number of Rooms Available
void Hotel::setRooms(int rooms) {
  m_rooms = rooms; 
}
  //Sets Number of Suites Available
void Hotel::setSuites(int suites) {
  m_suites = suites;
}
  //Sets Room Price
void Hotel::setRoomPrice(double roomPrice) {
  m_roomPrice = roomPrice;
}
  //Sets Suite Price
void Hotel::setSuitePrice(double suitePrice) {
  m_suitePrice = suite Price;
}
  //Sets Total Revenue
void Hotel::setRevenue(double revenue) {
  m_revenue = revenue; 
}

//Setter for m_rooms already implemented for you
void Hotel::SetRoomsCount(int rooms) {
  m_rooms = rooms;
}

//Implement SellRoom here
void Hotel::SellRoom(){
  m_rooms--;
  m_revenue += m_roomPrice; 
}

//Implement SellSuite here
void Hotel::SellSuite(){
  m_suites--;
  m_revenue += m_suitePrice;
}

//SellAll already implemented for you
void Hotel::SellAll(){
  double revenue = m_rooms * m_roomPrice + m_suites * m_suitePrice;
  m_revenue += revenue;
  m_rooms = 0;
  m_suites = 0;
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  cout << "You just sold rooms with a total value of: $" << revenue << endl;
}
