/*
  CMSC 202 - Lab 13
  Lab to practice recursion
*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

/* Node Struct */
struct Node{
public:
  Node(int v) : m_val(v), m_next(nullptr) {} //Overloaded constructor
  int m_val; //Data in node
  Node* m_next; //Pointer to next node
};

/*************************************************
 * Implement findMin()                            *
 * Input: Node* -> Linked List                   *
 * Return: The min (smallest number) among the linked list values       *
 * Hint: The doc shares hints for each case      *
 ************************************************/

//&&&&&&&&&&  IMPLEMENT findMin HERE &&&&&&&&&&&&
int findMin(Node* node) {
  // Base case - Empty list, returns a minimum value
  int minValue = 0;
  if(node == nullptr){
    minValue = 100;
    return minValue; 
  }
  // Sets the minValue to the first node's value
  minValue = findMin(node->m_next);
  // Recursively finds the minimum in the rest of the list
  if(minValue > node->m_val){
    minValue = node->m_val;
  }
  // Returns the minimum of the current value
  // and the minimum in the rest of the list
  return minValue;
}


/*********************************************
 * main()                                    *
 * DO NOT EDIT                               *
 *********************************************/

int main(){
  //This part of main creates a new linked list
  //with a random size of 2 to 6 nodes
  //each node will have a random value between 0 - 99
  
  int len = 0; //Stores length of linked list
  Node *head = nullptr, *cur = nullptr; //Node pointer to head and curr

  srand(time(NULL)); //Seeds random number generator

  // create randomized linked list with possible length between 1 and 6
  head = new Node(rand() % 100); //Creates new head with value 0 - 99
  cur = head; //Sets cur to point to head
  cout << "Linked list:\n" << head->m_val; //Outputs value of first node

  len = rand() % 5 + 1; //Randomly generates the size of the list (1-5)
  
  while(len--) { //Counts down from len
    cur->m_next= new Node(rand() % 100); //Inserts new node 0 - 99
    cur = cur->m_next; //Moves cur to next node
    cout << "->" << cur->m_val; //outputs an arrow and the next value
  }

  // Calls findMin and displays smallest number in linked list
  cout << "\nThe smallest number is :" << endl
       << findMin(head) << endl; //Calls the recursive function

  // deallocate all nodes
  while(head) {
    cur = head;
    head = head->m_next;
    delete cur;
  }

  return 0;
}
