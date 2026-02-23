/*
Author: Brittany Huynh
Email: bhuynh4@umbc.edu
Date: 05/01/2024
Desc: This is the driver file for proj5
*/
#ifndef MOVIEPLAYER_CPP
#define MOVIEPLAYER_CPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include "MoviePlayer.h"

using namespace std;


  //Name: MoviePlayer - Default Constructor
  //Precondition: None
  //Postcondition: Creates a new MoviePlayer with m_filename of "proj5_movies.txt"
MoviePlayer::MoviePlayer(){
    m_filename = "proj5_movies.txt";
}
  //Name: MoviePlayer - Overloaded Constructor
  //Precondition: None
  //Postcondition: Creates a new MoviePlayer with passed filename
MoviePlayer::MoviePlayer(string filename){
    m_filename = filename;
}
  //Name: ~MoviePlayer - Destructor
  //Precondition: None
  //Postcondition: Deallocates movies from m_movieCatalog
MoviePlayer::~MoviePlayer(){
  for(unsigned int i = 0; i < m_movieCatalog.size(); i++){
    delete m_movieCatalog[i];
  }
  cout << "Deleting all movies..." << endl
  << "Thanks for playing!" << endl;
}
  //Name: LoadCatalog()
  //Precondition: Requires m_filename to be populated
  //Postcondition: Dynamically allocates each movie and inserts into m_movieCatalog
  //Hint:          Allowed to use stoi (string to integer) if needed
  //Hint:          Allowed to use stoul (string to long) if needed
void MoviePlayer::LoadCatalog(){
    string title; 
    string rating;
    string genre;
    string year;
    int intYear;
    string director;
    string star;
    string budget;
    long longBudget;
    string gross;
    long longGross;
    string studio;
    string runtime;
    int intRuntime; 
    Movie* newMovie;

    ifstream movieFile(m_filename);
    if(movieFile.is_open()){
        while(getline(movieFile, title, ';') && getline(movieFile, rating, ';')
        && getline(movieFile, genre, ';') && getline(movieFile, year, ';') 
        && getline(movieFile, director, ';') && getline(movieFile, star, ';') 
        && getline(movieFile, budget, ';') && getline(movieFile, gross, ';')
        && getline(movieFile, studio, ';') && getline(movieFile, runtime)){
            intYear = stoi(year);
            longBudget = stoul(budget);
            longGross = stoul(gross);
            intRuntime = stoi(runtime);
            newMovie = new Movie(title, rating, genre, intYear, director, star, 
            longBudget, longGross, studio, intRuntime);
            m_movieCatalog.push_back(newMovie);
        }
        cout << m_movieCatalog.size() << " movie files loaded." << endl;
    }else{
        cout << "File does not open" << endl;
    }
    movieFile.close();
}
  //Name: MainMenu
  //Precondition: None
  //Postcondition: Manages the menu
void MoviePlayer::MainMenu(){
  int answer = 0;
  do{
      cout << "What would you like to do?" << endl
      << "1. Display Movie by Type and Year" << endl
      << "2. Add Movie to Playlist" << endl
      << "3. Display Playlist" << endl
      << "4. Sort Playlist by Year" << endl
      << "5. Search for Movie" << endl
      << "6. Quit" << endl;
      cin >> answer;

      if(answer == 1){
        DisplayMovie();
      }else if(answer == 2){
        AddMovie();
      }else if(answer == 3){
        DisplayPlaylist();
      }else if(answer == 4){
        SortPlaylist();
      }

  }while(answer != 6);
}
  //Name: DisplayMovie
  //Desc: Asks user for year (between min and max year)
  //      Asks user for genre (no validation)
  //      Displays all movies with year and genre with location in vector
  //      Uses iterators
  //Precondition: m_movieCatalog, MIN_YEAR, and MAX_YEAR are all populated
  //Postcondition: Returns count of movies found matching year and genre else 0
  //Hint: Allowed to use ** if necessary
int MoviePlayer::DisplayMovie(){
  int chosenYear = 0;
  string chosenGenre = "";
  int movieCount = 0;

  cout << "What year would you like to display? (" << MIN_YEAR << '-' << MAX_YEAR << ')' << endl;
  cin >> chosenYear;
  while(chosenYear < MIN_YEAR || chosenYear > MAX_YEAR){
    cout << "Please enter a year between 1980 and 2020: " << endl;
    cin >> chosenYear;
  }
  cout << "******" << chosenYear << "******" << endl;

  cout << "Which genre would you like?" << endl;
  cin >> chosenGenre;
  cout << "******" << chosenGenre << "******" << endl;

  cout << "MOVIES TOTAL: " << m_movieCatalog.size() << endl;

  for(unsigned int i = 0; i < m_movieCatalog.size(); i++){
    if(m_movieCatalog[i]->GetGenre() == chosenGenre && m_movieCatalog[i]->GetYear() == chosenYear){
      cout << i + 1 << ". " << m_movieCatalog[i]->GetTitle() << " by " << m_movieCatalog[i]->GetDirector() 
      << " from " << m_movieCatalog[i]->GetYear() << endl;
      movieCount++;
    }
  }
  cout << movieCount << " movies found." << endl;
  return movieCount;
}
  //Name: AddMovie
  //Desc: Calls DisplayMovie where user chooses year and genre
  //      User enters index of movie to choose
  //      Validates for number to be between 0 - m_movieCatalog size
  //      Does NOT validate that movie chosen was from year and genre
  //      Uses overloaded << operator to display the example below
  //Example: Airplane! by Jim Abrahams from 1980 added to the playlist
  //Precondition: m_movieCatalog is populated
  //Postcondition: Adds pointer from m_catalog and inserts into m_playList
void MoviePlayer::AddMovie(){
  DisplayPlaylist();

  unsigned int answer = 0;
  cout << "Choose a movie you would like to add to the playlist:" << endl;
  int movieCount = DisplayMovie();

  if(movieCount == 0){
    cout << "Try another year and category." << endl; 
  }else{
    cout << "Enter the number of the movie you would like to add:" << endl;
    cin >> answer;
    while(answer < 0 || answer > m_movieCatalog.size()){
      cout << "Please enter a number number between 0 and " << m_movieCatalog.size() << endl;
      cin >> answer;
    }

    Movie* newMovie = m_movieCatalog[answer - 1];
    m_playList.PushBack(newMovie);

    cout << *newMovie << endl;
  }

}
  //Name: DisplayPlaylist
  //Precondition: None (will indicate if list is empty)
  //Postcondition: Displays the playlist using the overloaded << operator
void MoviePlayer::DisplayPlaylist(){
  if(m_playList.IsEmpty()){
    cout << "The playlist is currently empty." << endl;
  }else{
    cout << "Your current playlist:" << endl;
    for(int i = 0; i < m_playList.GetSize(); i++){
    cout << i + 1 << ". " << m_playList.At(i)->GetTitle() << " by " 
    << m_playList.At(i)->GetDirector() << " from " << m_playList.At(i)->GetYear() << endl;
  }
  }
}
  //Name: SortPlaylist
  //Precondition: None (will indicate if list is empty)
  //Postcondition: Sorts the playlist by year
void MoviePlayer::SortPlaylist(){
  if(m_playList.GetSize() > 1){
    m_playList.Sort();
    cout << "Done sorting by year." << endl
    << m_playList.GetSize() << " items sorted." << endl;
  }else{
    cout << "The playlist needs at least two movies to sort." << endl;
  }
}
// void MoviePlayer::SearchMovie(){
//   int answer;
//   string theString;
//   int ASCII_MIN = 65;
//   int ASCII_MAX = 90;
//   vector<string> allMovieTitles;
//   do{
//     cout << "What do you want to search by?" << endl
//     << "1. Word in Title or Director" << endl
//     << "2. Year" << endl
//     << "3. Earnings" << endl;
//     cin >> answer;
//     while(answer > 3 || answer < 1){
//       cout << "Please enter a number between 1 and 3." << endl;
//       cin >> answer;
//     }
//   }while(answer < 3 && answer > 1);

//   if(answer == 1){
//     cout << "What string would you like to search?" << endl;
//     cin >> theString;
//     while(theString[0] < ASCII_MIN || theString[0] > ASCII_MAX){
//       cout << "Please enter a title or director starting with a capital letter." << endl;
//       cin >> theString;
//     }
//   for(unsigned int i = 0; i < m_movieCatalog.size(); i++){
//     allMovieTitles.push_back(m_movieCatalog[i]->GetTitle());
//   }

//   for(unsigned int i = 0; i < allMovieTitles.size(); i++){
//     if(find(allMovieTitles.begin(), allMovieTitles.end(), theString) != allMovieTitles.end()){
//       cout << allMovieTitles[i] << endl;
//     }
//   }

//     }else if(answer == 2){
//       cout << "What year would you like to search?" << endl;
//     }else if(answer == 3){
//       cout << "What amount of gross earnings would you like to search for?" << endl;
//     }
// }

  //Name: StartPlayer
  //Precondition: None (file name has already been provided)
  //Postcondition: Loads file and calls main menu
void MoviePlayer::StartPlayer(){
  LoadCatalog();
  MainMenu();
}

 
#endif