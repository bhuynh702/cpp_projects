//File: SteamTeam.cpp
//Date: 3/25/2024 - 3/28/2024                                                                                         
//Description: You are working on this file!
//Adding and removing nodes from the linked list

#include "SteamTeam.h"

//Constructor
SteamTeam::SteamTeam(){
  m_head = nullptr;
  m_tail = nullptr;
}


//Destructor
SteamTeam::~SteamTeam(){
  //Removes nodes unitl linked list is empty
  while(m_head != nullptr){
    RemoveFirst();
  }

  //reset head and tail of linked list
  m_head = nullptr;
  m_tail = nullptr;
}


//PLEASE COMPLETE THIS FUNCTION
//Takes in name of train to create a steam engine object
//then inserts it to end of linked list
void SteamTeam::InsertEnd(string name){
  //Create steam engine object
  //If linked list is empty
  //Else newly created object becomes the new tail
  SteamEngineNode *temp = new SteamEngineNode(name);
  temp->m_next = nullptr;
  temp->m_name = name;
  if(m_head == nullptr){
    m_tail = temp;
    m_head = temp;
  }else{
    m_tail->m_next = temp;
    m_tail = temp; 
  }
}


//PLEASE COMPLETE THIS FUNCTION
//Removes the first train in line
//Consider special cases:
//1. When there are no trains in line
//2. One or more trains in line
void SteamTeam::RemoveFirst(){
  //Check if there are any trains left
  SteamEngineNode *temp = m_head;
  if(m_head == nullptr){
    cout << "The trains are all in their berths" << endl;
  }else{
    //*****IMPLEMENT THIS PART*********
    m_head = m_head->m_next;
    delete temp;
    temp = nullptr; 
  }
}


//PLEASE COMPLETE THIS FUNCTION
//Outputs the linked list which in this case is the trains in line!
void SteamTeam::Display(){
  //From start of linked list
  //Until we are at the end of linked list, output each node's data
   //*****IMPLEMENT THIS FUNCTION*********
  SteamEngineNode *temp = m_head;
  while (temp != nullptr){
    cout << temp->m_name << "->";
    temp = temp->m_next;
  }
  cout << "END" << endl;
  }


string SteamTeam::GetFirstInLine(){
  if(m_head)
    return m_head->m_name;
  return "";
}
