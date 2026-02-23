/*
Author: Brittany Huynh
Date: April 4, 2024
E-mail: bhuynh4@umbc.edu
Desc: This is the Navigator.cpp which 
*/

#include "Navigator.h"

#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

const int TOTAL_AIRPORTS = 40;

  // Overloaded Constructor
  Navigator::Navigator(string fileName){
    m_fileName = fileName;
  }
  // Destructor
  // Desc: Deallocates all dynamic aspects of a Navigator
  // Postconditions: All airports and routes are cleared
  Navigator::~Navigator(){
    int airportSize = m_airports.size();
    int routeSize = m_routes.size();

    for (int i = 0; i < airportSize; i++){ //iterate through airport vector 
      delete m_airports[i]; // delete each item at index 
      m_airports[i] = nullptr;
    }

    for(int i = 0; i < routeSize; i++){
      delete m_routes[i];
      m_routes[i] = nullptr;
    }

    cout << "Routes removed from memory" << endl;
    cout << "Deleting Airports" << endl;
    cout << "Deleting Routes" << endl;
  }
  // Name: Start
  // Desc: Loads the file and calls the main menu
  // Preconditions: m_fileName is populated
  // Postconditions: All ports are loaded and the main menu runs
  void Navigator::Start(){
    ReadFile();
    MainMenu();
  }
  // Name: DisplayAirports
  // Desc: Displays each airport in m_airports
  // Preconditions: At least one airport is in m_airports
  // Postconditions: Displays all airports.
  //  Uses overloaded << provided in Airport.h
  void Navigator::DisplayAirports(){
    for (int i = 0; i < TOTAL_AIRPORTS; i++){
      cout << i + 1 << ". " << m_airports[i]->GetName() << ", " << m_airports[i]->GetCity() << endl;
    }
  }
  // Name: ReadFile
  // Desc: Reads in a file that has data about each airport
  //   including code, name, city, country, degrees north and degrees west.
  //   Dynamically allocates airports and stores them in m_airports
  //   The vector can hold many airports.
  // Preconditions: Valid file name of airports
  // Postconditions: Dynamically allocates each airport
  //   and enters it into m_airports
  void Navigator::ReadFile(){
    string code;
    string name;
    string city;
    string country;
    string north;
    string west;
    double doubleNorth;
    double doubleWest;
    Airport* myAirport;
    
    ifstream airportFile(m_fileName);
    if(airportFile.is_open()){
        for (int i = 0; i < TOTAL_AIRPORTS; i++){
            getline(airportFile, code, ',');
            getline(airportFile, name, ',');
            getline(airportFile, city, ',');
            getline(airportFile, country, ',');
            getline(airportFile, north, ',');
            getline(airportFile, west);
            doubleNorth = stod(north);
            doubleWest = stod(west);
            myAirport = new Airport(code, name, city, country, doubleNorth, doubleWest);
            m_airports.push_back(myAirport);
        }
        cout << "Opened file" << "\n" 
        << "Airports Loaded: " << m_airports.size() << endl;
    }else{
        cout << "file does not open" << endl;
    }
    airportFile.close();
  }
  // Name: InsertNewRoute
  // Desc: Dynamically allocates a new route with the user selecting
  //   each airport in the route. Each route can have a minimum of two
  //   airports. Will not allow a one airport route.
  //   Checks for min of two valid airports (1-40)
  //   Route named using Route's UpdateName.
  //   For example, Baltimore to Boston
  //   Once route is created, inserted into m_routes.
  // Preconditions: Populated m_routes
  // Postconditions: Inserts a new route into m_routes
  void Navigator::InsertNewRoute(){
    Route* newRoute = new Route(); // dynamically allocates a new route 
    m_routes.push_back(newRoute); // add new route to vector 
    int answer = 0;
    int counter = 0;
    string code;
    string name;
    string city;
    string country;
    double north;
    double west;

  while(answer != -1){
    cout << "Enter the number of the airport to add to your Route: (-1 to end)" << endl;
    cin >> answer;

    if (answer < -1 || answer > TOTAL_AIRPORTS || answer == 0){
      cout << "Please enter a number between 1 and 40:" << endl;
    }

    if ((answer == -1) && (counter < 2)){
      cout << "You entered only 1 airport. Please choose at least two airports." << endl;
      answer = 0;
    }
    else if (answer >= 1 && answer <= TOTAL_AIRPORTS){
      counter++;
      code = m_airports[answer - 1]->GetCode();
      name = m_airports[answer - 1]->GetName();
      city = m_airports[answer - 1]->GetCity();
      country = m_airports[answer - 1]->GetCountry();
      north = m_airports[answer - 1]->GetNorth();
      west = m_airports[answer - 1]->GetWest();

      newRoute->InsertEnd(code, name, city, country, north, west); // call InsertEnd func on data of selected airport 
    }
  }
  cout << "Done building a new route called " << newRoute->UpdateName() << endl;
  }
  // Name: MainMenu
  // Desc: Displays the main menu and manages exiting
  // Preconditions: Populated m_airports
  // Postconditions: Exits when someone chooses 5
  void Navigator::MainMenu(){
    int answer = 0;
    do{
      cout << "What would you like to do?\n"
      << "1. Create New Route\n"
      << "2. Display Route\n"
      << "3. Remove Airport From Route\n"
      << "4. Reverse Route\n" 
      << "5. Exit" << endl;
      cin >> answer;

    if (answer == 1){
      DisplayAirports();
      InsertNewRoute();
    }else if (answer == 2){
      DisplayRoute();      
    }else if (answer == 3){
      RemoveAirportFromRoute();
    }else if (answer == 4){
      ReverseRoute();
    }
    
    }while(answer != 5);
  }

  // Name: ChooseRoute
  // Desc: Allows user to choose a specific route to work with
  //   by displaying numbered list
  // Preconditions: Populated m_routes
  // Postconditions: Returns the index of the selected route minus 1
  int Navigator::ChooseRoute(){
  unsigned int chosenRoute = 0;

  do{
    if(m_routes.size() < 1){
    return -1;
    }
    cout << "Which route would you like to use?" << endl;
    for (unsigned int i = 0; i < m_routes.size(); i++){
      cout << i + 1 << ". " << m_routes[i]->UpdateName() << endl;
    }
    cin >> chosenRoute;
  }while(chosenRoute < 1 || chosenRoute > m_routes.size());
  
  return chosenRoute - 1;
  }
  // Name: DisplayRoute
  // Desc: Using ChooseRoute, displays a numbered list of all routes.
  //    If no routes, indicates that there are no routes to display
  //    User selects a route from list to display
  //    Displays numbered list of each airport in route
  //    Displays total miles of a route using RouteDistance
  // Preconditions: Routes has more than one airport
  // Postconditions: Displays all airports in a route and
  //    the total miles of the route
  void Navigator::DisplayRoute(){
    int chosenRoute;
    double distance; 

    if (m_routes.size() < 1){
      cout << "No routes available. Create a route first." << endl; //If no routes, indicates that 
      // there are no routes to display
    }else{
      chosenRoute = ChooseRoute(); // displays list of routes
      Route* temp = m_routes[chosenRoute]; 
      cout << m_routes[chosenRoute]->GetName() << endl;
      temp->DisplayRoute();
      distance = RouteDistance(temp);
      cout << "The total miles of this route is " << distance << " miles." << endl;
    }

  }
  // Name: RemoveAirportFromRoute()
  // Desc: Using ChooseRoute, displays a numbered list of all routes.
  //    User selects one of the routes to remove an airport from.
  //    Displays a numbered list of all airports in selected route.
  //    User selects airport to remove from list.
  //    Each route has a minimum of two airports (will not allow).
  //    Removes airport from route if more than two.
  //    If first or last airport removed,
  //    updates name of route using UpdateName
  // Preconditions: Route has more than one airport
  // Postconditions: Displays updated route with removed airport
  //    and new name
  void Navigator::RemoveAirportFromRoute(){
    int answer = 0;
    int chosenRoute = ChooseRoute();

    if(chosenRoute == -1){
      cout << "No routes available. Create a route first." << endl;
      return;
    }
    if(m_routes[chosenRoute]->GetSize() < 3){
      cout << "This route only has 2 airports.\n" <<
      "You cannot remove an airport from a route that has less than two airports." << endl;
    }else{
      cout << m_routes[chosenRoute]->GetName() << endl;
      m_routes[chosenRoute]->DisplayRoute();
      cout << "Which airport would you like to remove?" << endl;
      cin >> answer;
      m_routes[chosenRoute]->RemoveAirport(answer - 1);
      cout << m_routes[chosenRoute]->GetName() << endl;
      m_routes[chosenRoute]->DisplayRoute();
      cout << "Route named " << m_routes[chosenRoute]->UpdateName() << " updated." << endl;
    }
  }
  // Name: RouteDistance
  // Desc: Calculates the total distance of a route
  //    Goes from airport 1 to airport 2 then airport 2 to airport 3
  //    and repeats for length of route.
  //    Calculates the distance using CalcDistance (provided)
  //    Aggregates the total and returns the total in miles
  // Preconditions: Populated route with more than one airport
  // Postconditions: Returns the total miles between all airports in a route
  double Navigator::RouteDistance(Route* route){
    double sum = 0;
    double distance = 0;

    double north1;
    double west1;
    double north2;
    double west2;

    for (int i = 0; i < route->GetSize() - 1; i++){ 
      north1 = route->GetData(i)->GetNorth();
      west1 = route->GetData(i)->GetWest();
      north2 = route->GetData(i + 1)->GetNorth();
      west2 = route->GetData(i + 1)->GetWest();
      distance = CalcDistance(north1, west1, north2, west2);
      sum += distance;
    }
    return sum; 
  }
  // Name: ReverseRoute
  // Desc: Using ChooseRoute, users chooses route and the route is reversed
  //   If no routes in m_routes, indicates no routes available to reverse
  //   Updates route name using UpdateName
  //   For example, Baltimore to Boston becomes Boston to Baltimore
  // Preconditions: Populated m_routes
  // Postconditions: Reverses a specific route by reversing the airports
  //   in place. Must move airports, cannot just change data in airports.
  void Navigator::ReverseRoute(){
    int chosenRoute = ChooseRoute();

    if(chosenRoute == -1){
      cout << "No routes available. Create a route first." << endl;
      return;
    }else{
      m_routes[chosenRoute]->ReverseRoute();
      cout << "Done reversing Route: " << m_routes[chosenRoute]->UpdateName() << endl;
    }
  }
