/*
Author: Brittany Huynh
E-mail: bhuynh4@umbc.edu
Date: 04/18/24
Desc: This is the main function that runs the game. 
*/
#ifndef GAME_CPP
#define GAME_CPP
#include "Game.h"

#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

Game::Game(string itemFile, string planetFile){
  m_fileItems = itemFile;
  m_filePlanets = planetFile;
}
  // Name: ~Game
  // Description: Destructor
  // Preconditions: None
  // Postconditions: Deallocates anything dynamically allocated
  //                 in Game (ship, items, and planets)
Game::~Game(){
  for(unsigned int i = 0; i < m_items.size(); i++){
    delete m_items[i];
  }
  delete m_ship;
  for(unsigned int i = 0; i < m_planets.size(); i++){
    delete m_planets[i];
  }
  cout << "Deleting all items, planets, and your ship." << endl 
  << "Goodbye. Thank you for playing!" << endl;
}

void Game::LoadItems(){
  string name; 
  string type;
  string stringValue;
  int intValue = 0; 
  Item* newItem;

  ifstream itemFile(m_fileItems);
  if(itemFile.is_open()){
    while(getline(itemFile, name, DELIMITER) && 
    getline(itemFile, type, DELIMITER) && getline(itemFile, stringValue)){
      intValue = stoi(stringValue);
      if(type == "armor"){
        newItem = new Armor(name, type, intValue);
      }
      if(type == "weapon"){
        newItem = new Weapon(name, type, intValue);
      }
      if(type == "engine"){
        newItem = new Engine(name, type, intValue);
      }
      m_items.push_back(newItem);
    }
  }else{
    cout << "File does not open" << endl;
  }
  itemFile.close();
}

void Game::LoadPlanets(){
  string name; 
  string type;
  string stringChallenge;
  int intChallenge;
  Planet* newPlanet;

  ifstream planetFile(m_filePlanets);
  if(planetFile.is_open()){
    while(getline(planetFile, name, DELIMITER) && 
    getline(planetFile, type, DELIMITER) && getline(planetFile, stringChallenge)){
      intChallenge = stoi(stringChallenge);
      if(type == "gas"){
        newPlanet = new Gas(name, intChallenge);
      }
      if(type == "mining"){
        newPlanet = new Mining(name, intChallenge);
      }
      if(type == "enemy"){
        newPlanet = new Enemy(name, intChallenge);
      }
      m_planets.push_back(newPlanet);
    }
  }else{
    cout << "File does not open" << endl;
  }
  planetFile.close();
}

void Game::ShipCreation(){
  string shipName;
  cout << "Enter the Ship's name:" << endl;
  getline(cin, shipName);

  Ship *newShip = new Ship(shipName);
  m_ship = newShip;

  m_ship->AddItem(m_items[START_ENGINE]);
  m_ship->AddItem(m_items[START_ARMOR]);
  m_ship->AddItem(m_items[START_WEAPON]);
}

void Game::StartGame(){
  LoadItems();
  LoadPlanets();
  cout << "Welcome to Super Space Exploration!" << endl
  << m_planets.size() << " planets loaded." << endl
  << m_items.size() << " items loaded." << endl;
  ShipCreation();

  m_curPlanet = m_planets[START_PLANET];
  cout << m_curPlanet->GetName() << "(" << m_curPlanet->GetType() << ")" 
  << " Challenge: " << m_curPlanet->GetChallenge() << endl;

  m_winEngine = UTOPIA_MIN + (rand() % (UTOPIA_MAX - UTOPIA_MIN));

  cout << endl;
  Action();
}

void Game::Action(){
      int win;
      int answer = 0;
    do{
      cout << "What would you like to do?\n"
      << "1. Examine Items" << endl
      << "2. Move" << endl
      << "3. Attack Planet" << endl
      << "4. Travel to Utopia" << endl 
      << "5. Check Stats" << endl
      << "6. Quit" << endl;
      cin >> answer;

    if(answer == 1){
      DisplayShipItems();
    }else if (answer == 2){
      Move();   
    }else if (answer == 3){
      AttackPlanet();
    }else if (answer == 4){
      win = TravelUtopia();
    }else if (answer == 5){
      Stats();
    }
    
    }while(answer != 6 && m_ship->GetFuel() >= 0 && win == 0);
}

void Game::Move(){
  cout << "You travel to the next planet." << endl;
  int randNum = rand() % m_planets.size() + 1;
  cout << m_planets[randNum]->GetName() << "(" << 
  m_planets[randNum]->GetType() << ")" << " Challenge: " << 
  m_planets[randNum]->GetChallenge() << endl; 

  cout << "Your fuel has been modified by -5 fuel." << endl;
  m_ship->ModifyFuel(MOVE_FUEL);
  m_curPlanet = m_planets[randNum]; 
}

void Game::AttackPlanet(){
  if(m_curPlanet->GetIsExplored() == true){
    cout << "You have already defeated this planet." << endl
    << "You should move to a new planet." << endl;
  }else{
    bool win = m_curPlanet->Battle(m_ship);
    if(win){
      cout << "You found a new item: ";
      IdentifyItem(m_curPlanet->GetChallenge());
    }
  } 
}

void Game::IdentifyItem(int currentChallenge){
  Item *tempItem;
  int randIndex;
  vector<Item*> randomItems;

  for(unsigned int i = 0; i < m_items.size(); i++){
    if(m_items[i]->GetValue() == currentChallenge){
      randomItems.push_back(m_items[i]); 
    } 
  }
  randIndex = rand() % randomItems.size() + 1; 
  tempItem = randomItems[randIndex];
  cout << tempItem->GetName() << " (" << tempItem->GetType() << ") Value:" << tempItem->GetValue() << endl;
  m_ship->AddItem(tempItem);
}

void Game::Stats(){
  m_ship->DisplayShip();
  DisplayShipItems();
}

int Game::TravelUtopia(){ 
  int totalEngine = m_ship->GetTotal("engine");
  if(totalEngine > m_winEngine){ 
    cout << "You successfully made it to Utopia!" << endl
    << "You win! Hooray!" << endl;
    return 1;
  }else if(totalEngine < UTOPIA_MIN){ 
    cout << "You've failed to make it to Utopia." << endl 
    << "Try again once you've developed your engines more." << endl;
    return 0;
  }else if(totalEngine < m_winEngine){
    cout << "You've failed to make it to Utopia." << endl
    << "You eventually ran out of food and fuel, then DIED." << endl;
    return -1;
  }
  return 0;
}
void Game::DisplayShipItems(){
  m_ship->DisplayItems();
}

#endif