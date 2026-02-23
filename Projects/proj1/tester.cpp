/*****************************************
 ** File:    fortune.cpp
 ** Project: CMSC 202 Project 1, Spring 2024
 ** Author: Brittany Huynh
 ** Date: 02/26/2024
 ** Email: bhuynh4@umbc.edu

    This file is Project 1 for SP24 CMSC202. 
    It's a C++ version of the game Wheel of Fortune.
 ***********************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib> 
using namespace std;

const int NUMLINES = 24;

bool loadFile(string[], string[]);
int getAnswer(string[]);
void printPuzzle(char[], int);
char getInput();
void inPuzzle(char, string, char[]);
bool checkWin(string, char[]);

bool loadFile(string category[], string puzzle[]){
    /*
    This function loads the categories and puzzles from the proj1.txt file
    */
    ifstream gamefile ("proj1_data.txt");

    if(gamefile.is_open()){

        int count = 0;

        string categoryLine = {""};
        string answerLine = {""};

        while(getline(gamefile, categoryLine) && getline(gamefile, answerLine)){ 
            // the above line reads the first and second line of the file 
            category[count] = categoryLine; // adds category to array that's declared in main 
            puzzle[count] = answerLine; // adds answer to array that's declared in main 
            count++; // increments through each line of file 
        }
        cout << "24 Puzzles Loaded." << endl;
        return true;
    }else{
        cout << "Unable to open file. " << endl;
        return false;
    }
}


int getAnswer(string category[])
{
    /* 
    This file returns a random number between 0-24 
    that will be used to select the random category 
    */
    int randomCat = rand() % 24;
    return randomCat;
}


void printPuzzle(char puzzle[], int size)
{
    /*
    This function prints out the blank spaces of the puzzle
    */
    for (unsigned int i = 0; i < (unsigned int)size; ++i) // iterates through the each letter of puzzle
    {
        cout << puzzle[i];
    }
    cout << endl;
} 

char getInput()
{
    /*
    This function takes the user input and 
    reprompts if the answer is not a capital letter
    */
    char answer;

    do{
        cout << "What letter would you like to try? " << endl; // prompts user
        cin >> answer;

        if (answer < 'A'  || answer > 'Z'){ // if answer is invalid 
            cout << "Enter an uppercase letter only." << endl; // print this out 
        }
        
    }while(answer < 'A' || answer > 'Z'); // if answer is out of range, restart the loop 
    
    return answer;
}

void inPuzzle(char userInput, string puzzle, char answers[]) 
    {

    int letterCount = 0;
    bool alreadyGuessed = false;
    bool found = false;

    for (unsigned int i = 0; i < puzzle.length(); i++)
    {
        if (userInput == answers[i])
        {
            alreadyGuessed = true;
        }else if (userInput == puzzle[i]){
            found = true;
            letterCount++;
            answers[i] = puzzle[i];
        }
    }
    if (alreadyGuessed == true) {
        cout << userInput << " already guessed.\n";
    }
    else if (found == true){
        cout << letterCount << " " << userInput << " found in the puzzle.\n";
    }
    else{
        cout << "No " << userInput << " found in puzzle.\n";
    }

    }


bool checkWin(string puzzle, char answer[]) {
    /*
    This function returns a boolean that checks if 
    the answer is equal to the puzzle 
    */
    bool winCheck = true; // will return true if the answer is equal to puzzle 
    for (unsigned int i = 0; i < puzzle.length(); i++){ // iterates through puzzle 
        if (puzzle[i] != answer[i]){ // if answer is not equal to the puzzle
            winCheck = false; // returns False, keeps asking for input  
        }
    }
    return winCheck;
}

int main () 
{
    srand(time(NULL));

    cout << "Welcome to UMBC Fortune Wheel!" << endl;

    string category[NUMLINES]= {" "}; // string array of categories with size of 24 
    string puzzle[NUMLINES] = {" "}; // string array of puzzles with size of 24

    loadFile(category, puzzle); // loads the file contents into the arrays 
    
    int randomCat = getAnswer(category); // initialize a var that is the number of the randomly selected category
    string selectedPuzzle = puzzle[randomCat]; // intialize a var that is the correlating puzzle to the selected category 
   
    cout << "The category is: " << category[randomCat] << endl; 

    cout << selectedPuzzle << endl; 


    char answers[selectedPuzzle.length()]; // char array of guessed answers 
    /*
    The below for loop makes char array answers into all underscores that 
    change in the inPuzzle function 
    */
    for (unsigned int i = 0; i < selectedPuzzle.length(); ++i) {
        if (selectedPuzzle[i] != ' ') {
            answers[i] = '_';
        }
        else {
            answers[i] = ' ';
        }
    }

    do
    {

    printPuzzle(answers, selectedPuzzle.length()); // prints underscores initially 

    char input = getInput(); // get user input 
    
    inPuzzle(input, selectedPuzzle, answers); // checks if input is in the puzzle and valid, then updates answers 

    } while(!checkWin(selectedPuzzle, answers)); // while checkWin is not false 

    return 0;
}