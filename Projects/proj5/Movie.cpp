#include <iostream>
#include <string>
#include "Movie.h"
using namespace std;

#ifndef MOVIE_CPP
#define MOVIE_CPP


  //Name: Movie - Default Constructor
  //Precondition: None
  //Postcondition: Creates a default movie
Movie::Movie(){
    m_title = "";
    m_rating = "";
    m_genre = "";
    m_year = 0;
    m_director = "";
    m_star = "";
    m_budget = 0;
    m_gross = 0;
    m_studio = "";
    m_runtime = 0; 
}
  //Name: Movie - Overloaded Constructor
  //Precondition: Requires title, rating, genre, year, director, star,
  //              budget, gross, studio, and runtime
  //Postcondition: Creates a movie entry based on passed parameters
Movie::Movie(string title, string rating, string genre, int year, string director,
	string star, long budget, long gross, string studio, int runtime){
    m_title = title;
    m_rating = rating;
    m_genre = genre;
    m_year = year;
    m_director = director;
    m_star = star;
    m_budget = budget;
    m_gross = gross;
    m_studio = studio;
    m_runtime = runtime; 
}
  //Name: Mutators and Accessors
  //Precondition: None
  //Postcondition: Sets and Gets private member variables
string Movie::GetTitle()const{
    return m_title;
}
string Movie::GetRating()const{
    return m_rating; 
}
string Movie::GetGenre()const{
    return m_genre;
}
int Movie::GetYear()const{
    return m_year;
}
string Movie::GetDirector()const{
    return m_director;
}
string Movie::GetStar() const{
    return m_star;
}
long Movie::GetBudget() const{
    return m_budget;
}
long Movie::GetGross() const{
    return m_gross;
}
string Movie::GetStudio() const{
    return m_studio;
}
int Movie::GetRuntime() const{
    return m_runtime;
}
void Movie::SetTitle(string title){
    m_title = title;
}
void Movie::SetRating(string rating){
    m_rating = rating;
}
void Movie::SetGenre(string genre){
    m_genre = genre; 
}
void Movie::SetYear(int year){
    m_year = year;
}
void Movie::SetDirector(string director){
    m_director = director;
}
void Movie::SetStar(string star){
    m_star = star;
}
void Movie::SetBudget(long budget){
    m_budget = budget;
}
void Movie::SetGross(long gross){
    m_gross = gross;
}
void Movie::SetStudio(string studio){
    m_studio = studio;
}
void Movie::SetRuntime(int runtime){
    m_runtime = runtime; 
}
  //Name: Overloaded << operator
  //Precondition: movie available
  //Postcondition: Returns output stream including title by director from year
ostream& operator<<(ostream& out, Movie& m){
    out << m.GetTitle() << " by " << m.GetDirector() << " from " << m.GetYear() << " added to the playlist.";
    return out;
}

//   Name: Overloaded Relational Operator (<)
//   Precondition: Two movie objects required
//   Postcondition: if passed movie's year is less than first,
//                 return true else false
bool Movie::operator<(const Movie& m){
    if(GetYear() < m.GetYear()){
        return false;
    }
    return true;
}
  //Name: Overloaded Relational Operator (>)
  //Precondition: Two movie objects required
  //Postcondition: if passed movie's year is greater than first,
  //               return true else false
bool Movie::operator>(const Movie& m){
    if(GetYear() > m.GetYear()){
        return false;
    }
    return true;
}


#endif 