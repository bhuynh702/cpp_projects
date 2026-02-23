#ifndef SHIP_CPP
#define SHIP_CPP
#include "Ship.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Ship::Ship(string name){
    m_name = name;
    m_fuel = STARTING_FUEL;
}

string Ship::GetName(){
    return m_name;
}
  // Name: GetTotal(string type)
  // Description: Passed an item type (armor, weapon, or engine)
  //     Iterates over all items on ship and totals type passed in
  // Preconditions: None
  // Postconditions: Returns total value for armor, weapon, or engine
int Ship::GetTotal(string type){
    int total = 0;
    for (unsigned int i = 0; i < m_shipItems.size(); i++){
        if(type == m_shipItems[i]->GetType()){
            total += m_shipItems[i]->GetValue();
        }
    }
    return total;
}
  // Name: AddItem
  // Description: Adds a new item into m_items up to MAX_ITEMS.
  //    If at max, calls ReplaceItem
  // Preconditions: None
  // Postconditions: m_items is populated
void Ship::AddItem(Item* item){
    if(m_shipItems.size() < MAX_ITEMS){
        m_shipItems.push_back(item);
    }else if(m_shipItems.size() == MAX_ITEMS){
        ReplaceItem(item);
    }
}
  // Name: ReplaceItem(Item*)
  // Description: Used when m_shipItem is at capacity.
  //   Lists all ship items and replaces with updated pointer
  //   Does NOT make a new object - just updates pointer
  // Preconditions: None
  // Postconditions: Used to replace an item in inventory (m_shipItems)
void Ship::ReplaceItem(Item* item){
    int answer;
    cout << "Which item would you like to replace?" << endl;
    DisplayItems();
    cin >> answer;
    if(answer > MAX_ITEMS || answer < 1){
        cout << "Enter a number between 1 and 10:" << endl;
        cin >> answer;
    }
    m_shipItems[answer - 1] = item;
}

int Ship::GetFuel(){
    return m_fuel;
}
  // Name: ModifyFuel(int)
  // Description: Used to increase (positive int) or
  //              decrease (negative int) m_fuel
  // Preconditions: None
  // Postconditions: Used to update fuel.
void Ship::ModifyFuel(int updateFuel){
    m_fuel += updateFuel;
}
  // Name: DisplayItems
  // Description: Displays a numbered list of all items on ship.
  // Preconditions: None
  // Postconditions: m_items is populated
  
void Ship::DisplayItems(){
    for (unsigned int i = 0; i < m_shipItems.size(); i++){
        cout << i + 1 << ". ";
        m_shipItems[i]->Display();
    }
}

int Ship::GetItemCount(){
    int itemCount = 0;
    for(unsigned int i = 0; i < m_shipItems.size(); i++){
        itemCount++;
    }
    return itemCount;
}
  // Name: DisplayShip;
  // Description: Displays stats about the ship
  // Displays name, fuel, attack(weapon), defense(armor), engine(engine) all all items
  // Preconditions: None
  // Postconditions: None
void Ship::DisplayShip(){
    cout << "**************************" << "\n" 
    << "Name: " << m_name << "\n"
    << "Fuel: " << m_fuel << "\n"
    << "Attack: " << GetTotal("weapon") << "\n"
    << "Defense: " << GetTotal("armor") << "\n"
    << "Engine " << GetTotal("engine") << "\n"
    << "**************************" << endl; 
    // DisplayItems();
}

#endif
