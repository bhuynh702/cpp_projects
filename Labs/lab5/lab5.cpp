/************************************************************************
** File: lab5.cpp
** Description: Uses a Hotel to demonstrate how classes work in C++
************************************************************************/

#include "Hotel.h"
#include <iostream>
#include <string>

// Declare DisplayInfo here (provided)
void DisplayInfo(Hotel myHotel);

int main() {
  // Creates Hotel object
  Hotel myHotel;
  // Constant for number of rooms and suites
  const int NUM_ROOMS = 10;
  const int NUM_SUITES = 5;
  const double PRICE_ROOM = 104.25;
  const double PRICE_SUITE = 227.50;
  // Use setters to populate member variables of the hotel
  // Make 10 rooms with a price of 104.25 a room using constants
  myHotel.setRooms(NUM_ROOMS);
  myHotel.setRoomPrice(PRICE_ROOM);
  // Make 5 suites with a price of 227.50 a suite using constants
  myHotel.setSuites(NUM_SUITES);
  myHotel.setSuitePrice(PRICE_SUITE);
  
  // Displays inventory in the hotel
  DisplayInfo(myHotel);

  // Sell a single room
  cout << "Selling a regular room!" << endl;
  myHotel.SellRoom();
  DisplayInfo(myHotel);

  // Sell a single suite
  cout << "Selling a suite to a high roller!" << endl;
  myHotel.SellSuite();
  DisplayInfo(myHotel);

  // Sells the rest of the items and displays overall revenue
  cout << "Selling the rest of the rooms!" << endl;
  myHotel.SellAll();

  // Displays the total revenue after selling all of the rooms
  cout << "\nToday's Revenue: $" << myHotel.GetRevenue() << "\n" << endl;
  
  return 0;
}

//Implement displayInfo here
//Hint use precision or setprecision and fixed to show currency
void DisplayInfo(Hotel myHotel){
  cout << "*Hotel Information*" << endl;
  cout << "Rooms Available: " << myHotel.GetRooms() << endl;
  cout << "Suites Available: " << myHotel.GetSuites() << endl;
  cout.precision(2);
  cout << "Each Room costs: " << myHotel.GetRoomPrice() << endl;
  cout << "Each Suite costs: " << myHotel.GetSuitePrice() << endl;
  cout << "Current Revenue: " << myHotel.GetRevenue() << endl;
}
