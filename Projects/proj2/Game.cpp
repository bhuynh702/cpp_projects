/*
Author: Brittany Huynh
Date: March 12, 2024
E-mail: bhuynh4@umbc.edu
Description: This is the driver function for Project 2, a C++ version of Pokemon. 
*/
#include "Game.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

Game::Game(string filename){
    m_filename = filename;
}
  // Name: LoadFile
  // Desc - Opens file and reads in each Pokemon into m_PokeDex
  // Preconditions - Input file passed and populated with Pokemon
  // Postconditions - m_pokeDex populated with Pokemon
  void Game::LoadFile(){
    int pokeNum;
    string name;
    int power;
    int rarity; 
    Pokemon myPokemon; // creates an object myPokemon with overloaded constructor 
    ifstream pokeDexFile(m_filename);

    if(pokeDexFile.is_open()){
        for (int i = 0; i < TOTAL_POKEMON; i++){
            pokeDexFile >> pokeNum >> name >> power >> rarity;
            myPokemon = Pokemon(pokeNum, name, power, rarity);
            m_pokeDex[i] = myPokemon;
            // cout << m_pokeDex[i].GetCP();
        }
    }else{
      cout << "file does not open" << endl;
    }
    pokeDexFile.close();
  }
  // Name: DisplayPokeDex
  // Desc - Display all Pokemon in the m_pokeDex
  // Preconditions - m_pokeDex populated with Pokemon
  // Postconditions - None
  void Game::DisplayPokeDex(){
    for (int i = 0; i < TOTAL_POKEMON; i++){
      cout << "\t" << i + 1 << ". " << m_pokeDex[i].GetName() << "\n";
    }
  }


  void Game::MainMenu(){
    int answer = 0;
    do{
        cout << "What would you like to do?:" << endl;

        cout << "1. Display Complete PokeDex\n" 
            << "2. Display your Team\n"  
            << "3. Search for a new Pokemon\n"
            << "4. Battle your Pokemon\n"
            << "5. Train your Pokemon\n"
            << "6. Exit" << endl;

        cin >> answer;

        if (answer == 1){
            DisplayPokeDex();
        }else if (answer == 2){
            DisplayTeam();
        }else if (answer == 3){
            CatchPokemon();
        }else if (answer == 4){
            BattlePokemon();
        }else if (answer == 5){
            TrainPokemon();
        }
        
    }while(answer != 6);
    cout << "Thanks for playing!" << endl;
  }
  // Name: CatchPokemon
  // Desc - Main function for catching pokemon. Does the following:
  //        1. Calls CatchMenu and stores rarity chosen
  //        2. Randomly chooses a number between 0 - 99
  //        3. If random number is less than rarity, calls FoundPokemon
  //        4. If random number is greater than rarity, indicates none found
  //        5. Call AddPokemon if new Pokemon is caught
  // Preconditions - m_pokeDex has maximum CP for Pokemon
  // Postconditions - After random Pokemon of that rarity is chosen,
  //                  this function reduces the CP of between 30-50%
  //                  and adds to m_team
  void Game::CatchPokemon(){
    int chosenRarity = CatchMenu();
    Pokemon foundPokemon;
    cout << "You start to search." << endl;
    int randomNum = (rand() % 100);
    if (chosenRarity == 1 && randomNum <= COMMON){
      foundPokemon = FoundPokemon(chosenRarity);
    }else if (chosenRarity == 2 && randomNum <= UNCOMMON){
      foundPokemon = FoundPokemon(chosenRarity);
    }else if (chosenRarity == 3 && randomNum <= ULTRA){
      foundPokemon = FoundPokemon(chosenRarity);
    }else{
      cout << "You did not find any Pokemon." << endl;
      return;
    }
    AddPokemon(foundPokemon);
  }
  // Name: CatchMenu
  // Desc - User chooses which rarity of Pokemon to try and catch
  // Preconditions - m_pokeDex has rarities of 1-3
  // Postconditions - Returns choice of 1-3
  int Game::CatchMenu(){
    int chosenRarity = 0;
    do{
      cout << "What rarity of Pokemon would you like to catch?:" << endl;
      cout << "1. Common (High Probability)\n"
      << "2. Uncommon (Normal Probability)\n" 
      << "3. Ultra Rare (Extremely Low Probability)\n";
      cin >> chosenRarity;
      return chosenRarity; 

    }while(chosenRarity >= 1 || chosenRarity <= 3);
  }
  // Name: FoundPokemon
  // Desc - Based on rarity passed in, randomly chooses one Pokemon
  //        from the m_pokeDex, updates the CP, and adds to m_team
  // Preconditions - m_pokeDex has maximum CP for Pokemon
  // Postconditions - After random Pokemon of that rarity is chosen,
  //                  this function reduces the CP of between 30-50%
  //                  and adds to m_team
  Pokemon Game::FoundPokemon(int rarity){
    int randomNum = rand() % TOTAL_POKEMON; // generates random number between 0 - 150
    while (m_pokeDex[randomNum].GetRarity() != rarity){ // this while loop continues to regenerate a
      randomNum = rand() % TOTAL_POKEMON; // random Pokemon until there is a matching rarity found
    }
    // declare a newPokemon object 
    Pokemon newPokemon(m_pokeDex[randomNum].GetNum(), m_pokeDex[randomNum].GetName(), m_pokeDex[randomNum].GetCP(), m_pokeDex[randomNum].GetRarity());
    
    // generates a random number between 30 - 50 
    int random3050;
    random3050 = (rand() % (MAX_FIND + 1 - MIN_FIND)) + MIN_FIND;
    
    // casts random3050 into a double 
    double percentage;
    percentage = double(random3050) / 100;
    
    // create a double which will be the new reduced CP 
    double reducedCP;
    reducedCP = double(newPokemon.GetCP()) * (1 - percentage); 
    
    newPokemon.SetCP(reducedCP); // calls Setter to update new reduced CP

    cout << "You found a " << m_pokeDex[randomNum].GetName() << endl;
    return newPokemon; // returns the found Pokemon 

  }
  // Name: AddPokemon
  // Desc - Figures out where to insert newly found Pokemon
  //        If m_team has opening, inserts into first open slot
  //        If m_team is full, inserts into first slot with lower CP
  //        If m_team is full, and new Pokemon has lower CP, does not insert
  //        Tells user if not inserted
  // Preconditions - None
  // Postconditions - New Pokemon is added to m_team if possible
  //                  or user is notified that there is no room
  void Game::AddPokemon(Pokemon newPokemon){
    int teamCount = TeamSize();
    if (teamCount == NUM_TEAM){
      for (int i = 0; i < NUM_TEAM; i++){
      if (m_team[i].GetCP() < newPokemon.GetCP()){
        cout << newPokemon.GetName() << " replaced " << m_team[i].GetName() << endl;
        m_team[i] = newPokemon;
        return;
      }
    }
    }else if(m_team[teamCount].GetName() == ""){
        m_team[teamCount] = newPokemon;
        cout << newPokemon.GetName() << " added to your team!" << endl;
    }
  }


  int Game::TeamSize(){
    int teamCount = 0;
    for (int i = 0; i < NUM_TEAM; i++){ //Iterates through m_team
      if (m_team[i].GetName() != ""){ // if names in each Pokemon are not empty 
        teamCount++; // increment team counter 
      }
    }
    return teamCount; // return 0 if there are no names found 
  }

  void Game::DisplayTeam(){
    int teamCount = TeamSize();
    if (teamCount == 0){
      cout << "You have no team yet. Maybe search for a Pokemon?!" << endl;
    }else {
      for (int i = 0; i < teamCount; i++){
        cout << i + 1 << ".\t"<< m_team[i].GetName() << "\t" << m_team[i].GetCP() << endl;
      }
    }
  }
  // Name: FindPokemon
  // Desc - Iterates through m_pokeDex to see if matching name exists
  //        Returns index if found else -1
  // Preconditions - m_pokeDex exists
  // Postconditions - Returns index of match, else -1
  int Game::FindPokemon(string name){
    for (int i = 0; i < TOTAL_POKEMON; i++){
      if (m_pokeDex[i].GetName() == name){
        return i;
      }
    }
    return -1;
  }

  // Name: TrainPokemon
  // Desc - If m_team size is 0. If 0, tells user and returns to main menu
  //        If m_team size > 0, displays team (DisplayTeam)
  //        Asks user to chose one team member
  //        Calls Train on chosen team member and passes corresponding CP
  //             value from m_pokeDex (m_pokeDex holds max CP for all)
  // Preconditions - m_team and m_pokeDex exists
  // Postconditions - Calls Train on chosen team member
  void Game::TrainPokemon(){
    int answer = 0;
    cout << "Which of your Pokemon would you like to choose?" << endl;
    DisplayTeam();
    cin >> answer;
    if (answer < 1 || answer > 4) {
      cout << "Please choose a number between 1 and 4." << endl;
    }else{
      string pokeName = m_team[answer - 1].GetName();
      int index = FindPokemon(pokeName);
      int maxCP = m_pokeDex[index].GetCP();
      m_team[answer - 1].Train(maxCP);
      cout << pokeName << "'s CP goes up!" << endl;
    }
  }
  // Name: BattlePokemon
  // Desc - If m_team size is 0. If 0, tells user and returns to main menu
  //        If m_team size > 0, randomly chooses Pokemon to fight from
  //        m_pokeDex. Asks which team member to use in battle.
  //        Random enemy has a CP of 0 - max CP + 200.
  //        Compares CP for random enemy and team member.
  //        If team member wins, indicates and returns to main menu
  //        If team member loses, indicates, sets CP to 0, returns to menu
  // Preconditions - m_team exists
  // Postconditions - Either the player wins or team member's CP is set to 0
  void Game::BattlePokemon(){
    int teamCount = TeamSize(); // teamCount 
    int answer = 0;
    int enemyCP = 0;
    int randomNum = rand() % TOTAL_POKEMON; // random index for enemy 

    if (teamCount == 0){
      cout << "You have no team yet. Maybe search for a Pokemon?!" << endl;
    }else{
      cout << "You are going to fight a " << m_pokeDex[randomNum].GetName() << endl;

      enemyCP = (rand() % (m_pokeDex[randomNum].GetCP() + 1)) + 200; // enemy's CP 
      
      cout << "The enemy has a CP of " << enemyCP << endl; 

      cout << "Which of your Pokemon would you like to use? " << endl;
      DisplayTeam();
      cin >> answer;

    }

    if (m_team[answer - 1].GetCP() < enemyCP){ // use [answer - 1] to access index of m_team
        cout << "You lost.\n" << "Your " << m_team[answer - 1].GetName() 
        << " can't lift its head.\n" << "You should replace it." << endl;
        m_team[answer - 1].SetCP(0);
      }else if (m_team[answer - 1].GetCP() > enemyCP){
        cout << "You won!" << endl;
      }
  }
  // Name: Start
  // Desc - Calls LoadFile then MainMenu
  // Preconditions - m_fileName is populated
  // Postconditions - Exits game when done running
  void Game::Start(){
    LoadFile();
    MainMenu();
  }