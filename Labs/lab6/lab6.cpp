#include "Grocery.h"
#include <vector>

//Sets FRUITS = 0, VEGETABLES = 1, and DAIRY = 2
enum GROCERY_TYPE { FRUITS = 0, VEGETABLES = 1, DAIRY = 2};

// Write addToShoppingList
// Ask the user how many items they want to add to the shopping list
// For each item, ask the user for the name and type (0-2)
// Create a Grocery object with the information and add it to the vector
// You might have to use if(cin.peek() == '\n') cin.ignore(256,'\n') to clear the buffer
void addToShoppingList(vector<Grocery> &ShoppingList) {
  int items;
  cout << "How many items would you like to add to the shopping list? ";
  cin >> items;

  string theName;
  int type;

  for (int i = 0; i < items; i++){
    cout << "Item: " << i + 1 << endl;

    cout << "What is the name of this item?" << endl;
    cin >> theName;

    cout << "What type of grocery is this item?\n" << 
    "(0 for fruits, 1 for vegetables, 2 for dairy)" << endl;
    cin >> type; 

    Grocery Groceries(theName, type);
    ShoppingList.push_back(Groceries);
  }

}

// Write displayWithoutIterator
// Display the number of items on the shopping list
// For each item, display the name, type, and category
// Use a switch statement to display the type and category
// Don't forget to display the name as well
void displayWithoutIterator(vector<Grocery> &ShoppingList) {
  cout << "We have " << ShoppingList.size() << " item(s) on the shopping list." << endl;
  for (unsigned int i = 0; i < ShoppingList.size(); i++){
    switch(ShoppingList[i].GetType()){
    case FRUITS:
    cout << "Fruits: " << ShoppingList[i].GetName() << endl;
    break;
    case VEGETABLES:
    cout << "Vegetables: ";
    cout << ShoppingList[i].GetName() << endl;
    break;
    case DAIRY:
    cout << "Dairy: ";
    cout << ShoppingList[i].GetName() << endl;
    break;
    default:
    cout << "Grocery: ";
    cout << ShoppingList[i].GetName() << endl;
    break;
    }
  }
}

// Here is some free code! Use it wisely!
/*
  switch(FILL THIS IN){
  case FRUITS:
  cout << "Fruits: ";
  break;
  case VEGETABLES:
  cout << "Vegetables: ";
  break;
  case DAIRY:
  cout << "Dairy: ";
  break;
  default:
  cout << "Grocery: ";
  break;
  }
*/

// FUNCTION TO COMPLETE
void DisplayWithIterator(vector<Grocery> &ShoppingList) {
  // This function is the same as the one above, but uses an iterator to display the shopping list
  for (vector<Grocery>::iterator it = ShoppingList.begin(); it != ShoppingList.end(); it++){
    cout << ' ' << *it;
  }
}

// Main
// Provided.

int main() {
  vector<Grocery> ShoppingList;
  addToShoppingList(ShoppingList);
  cout << "Displaying Shopping List without iterator:" << endl;
  displayWithoutIterator(ShoppingList);
  cout << endl;
  cout << "Displaying Shopping List with iterator:" << endl;
  DisplayWithIterator(ShoppingList);
  cout << endl << "What a good-looking shopping list!" << endl;
  return 0;
}
