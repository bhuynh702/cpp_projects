a#ifndef QUEUE_CPP
#define QUEUE_CPP
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Templated linked list
//Note: Because the linked list is a templated class,
//      there is only ONE file (Queue.cpp)

//Templated node class
template <class T>
class Node {
public:
  Node( const T& data ); //Constructor
  T& GetData(); //Gets data from node
  void SetData( const T& data ); //Sets data in node
  Node<T>* GetNext(); //Gets next pointer
  void SetNext( Node<T>* next ); //Sets next pointer
private:
  T m_data;
  Node<T>* m_next;
};

//Overloaded constructor for Node
template <class T>
Node<T>::Node( const T& data ) {
   m_data = data;
   m_next = NULL;
}

//Returns the data from a Node
template <class T>
T& Node<T>::GetData() {
   return m_data;
}

//Sets the data in a Node
template <class T>
void Node<T>::SetData( const T& data ) {
   m_data = data;
}

//Gets the pointer to the next Node
template <class T>
Node<T>* Node<T>::GetNext() {
   return m_next;
}

//Sets the next Node
template <class T>
void Node<T>::SetNext( Node<T>* next ) {
   m_next = next;
}

template <class T>
class Queue {
 public:
  // Name: Queue() Queue from a linked list - Default Constructor
  // Desc: Used to build a new linked queue (as a linked list)
  // Preconditions: None
  // Postconditions: Creates a new queue where m_head and m_tail
  //                 point to nullptr and m_size = 0
  Queue();
  // Name: ~Queue() - Destructor
  // Desc: Used to destruct a Queue
  // Preconditions: There is a Queue
  // Postconditions: Queue is deallocated (including dynamically allocated nodes)
  //                 Can just call Clear()
 ~Queue();
  // Name: Queue (Copy Constructor)
  // Preconditions: Creates a copy of existing Queue in separate memory
  //                address (deep copy)
  //                Requires one already existing Queue
  // Postconditions: Copy of existing Queue
  Queue(const Queue& currQueue);
  // Name: operator= (Overloaded Assignment Operator)
  // Preconditions: When two Queue objects exist, sets one to equal another
  //                Requires two Queue objects
  // Postconditions: When completed, you have two Queues in
  //                 separate memory addresses with the same
  //                 number of nodes with the same values in each node
  Queue<T>& operator= (Queue&);
  // Name: PushBack
  // Preconditions: Takes in data. Creates new node. 
  //                Requires a Queue
  // Postconditions: Adds a new node to the end of the Queue.
  void PushBack(const T& data);
  // Name: PopFront
  // Preconditions: Queue with at least one node. 
  // Postconditions: Removes first node in the queue and
  //                 returns the data in the first node
  T PopFront();
  // Name: Display
  // Preconditions: Outputs the queue.
  // Postconditions: Displays the data in each node of queue
  // Required (used only for queue testing)
  void Display();
  // Name: Front
  // Preconditions: Requires a Queue with at least one node
  // Postconditions: Returns whatever data is pointed at by m_head -
  //                 Does NOT remove node
  T Front();
  // Name: IsEmpty
  // Preconditions: Requires a queue
  // Postconditions: Returns if the queue is empty.
  bool IsEmpty();
  // Name: GetSize
  // Preconditions: Requires a queue
  // Postconditions: Returns m_size
  int GetSize();
  // Name: Find()
  // Preconditions: Requires a queue
  // Postconditions: Iterates and if it finds the thing, returns index, else -1
  int Find(T);
  // Name: Clear
  // Preconditions: Requires a queue
  // Postconditions: Deallocates and removes all nodes in a queue. No memory leaks
  void Clear();
  // Name: At
  // Precondition: Existing Queue
  // Postcondition: Returns object from Queue at a specific location
  // Desc: Iterates to node x and returns data from Queue
  T& At (int x);
  // Name: Swap(int)
  // Preconditions: Requires a queue
  // Postconditions: Swaps the nodes at the index with the node prior to it.
  // Example: Swap(1) would swap the node 0 with node 1 so
  //          that node 1 would now be m_head
  // Desc: Swaps two nodes by updating the pointers (not just the value)
  // Hint: Think about the special cases! Implement before Sort
  void Swap(int);
  // Name: Sort()
  // Preconditions: Requires a queue with a minimum of 2 nodes
  //                (otherwise notifies user)
  // Postconditions: Sorts the Queue (may use overloaded < or >).
  // Desc: This is used to sort anything in the Queue assuming the
  //       < or > is overloaded
  //        Uses bubble sort and Swap function above.
  //        Ensure working with queue_test before rest of project.
  // Note: Allowed to use the break command in just this function if necessary
  void Sort();
private:
  Node <T> *m_head; //Node pointer for the head
  Node <T> *m_tail; //Node pointer for the tail
  int m_size; //Number of nodes in queue
};

//**********Implement Queue Class Here***********
//**********All Functions Are Required Even If Not Used for Project**************
//**********No references to anything from Movie here*****************

  // Name: Queue() Queue from a linked list - Default Constructor
  // Desc: Used to build a new linked queue (as a linked list)
  // Preconditions: None
  // Postconditions: Creates a new queue where m_head and m_tail
  //                 point to nullptr and m_size = 0
  template <class T>
  Queue<T>::Queue(){
   m_head = nullptr;
   m_tail = nullptr;
   m_size = 0;
  }
  // Name: ~Queue() - Destructor
  // Desc: Used to destruct a Queue
  // Preconditions: There is a Queue
  // Postconditions: Queue is deallocated (including dynamically allocated nodes)
  //                 Can just call Clear()
  template <class T>
  Queue<T>::~Queue(){
   Clear();
  }
  // Name: Queue (Copy Constructor)
  // Preconditions: Creates a copy of existing Queue in separate memory
  //                address (deep copy)
  //                Requires one already existing Queue
  // Postconditions: Copy of existing Queue
  template <class T>
  Queue<T>::Queue(const Queue& currQueue){
   m_head = nullptr;
   m_tail = nullptr;
   m_size = 0;
   Node<T>* temp = currQueue.m_head;
   while(temp != nullptr){
      PushBack(temp->GetData());
      temp = temp->GetNext();
   }
  }
  // Name: operator= (Overloaded Assignment Operator)
  // Preconditions: When two Queue objects exist, sets one to equal another
  //                Requires two Queue objects
  // Postconditions: When completed, you have two Queues in
  //                 separate memory addresses with the same
  //                 number of nodes with the same values in each node

template <class T>
Queue<T>& Queue<T>::operator= (Queue& currQueue){
   m_head = nullptr;
   m_tail = nullptr;
   m_size = 0;
   Node<T>* temp = currQueue.m_head;
   Clear();
   while(temp != nullptr){
      PushBack(temp->GetData());
      temp = temp->GetNext();
   }
   return *this;
}

  // Name: PushBack
  // Preconditions: Takes in data. Creates new node. 
  //                Requires a Queue
  // Postconditions: Adds a new node to the end of the Queue.
template <class T>
void Queue<T>::PushBack(const T& data){
if(m_head == nullptr){ // if list is empty 
   m_head = new Node<T>(data); // create one node with data 
   m_head->SetData(data);
   m_tail = m_head;
}else{ // else, add new node 
   Node<T>* temp = new Node<T>(data); 
   temp->SetData(data);
   temp->SetNext(nullptr);
   m_tail->SetNext(temp);
   m_tail = m_tail->GetNext();
}
m_size++;
}
  // Name: PopFront
  // Preconditions: Queue with at least one node. 
  // Postconditions: Removes first node in the queue and
  //                 returns the data in the first node
  template <class T>
  T Queue<T>::PopFront(){
   Node<T>* temp;
   int removed;
   if(m_head != nullptr){
      temp = m_head->GetNext();
      removed = m_head->GetData();
      delete m_head;
      m_head = temp;
      m_size--;
   }
   return removed;
  }
  // Name: Display
  // Preconditions: Outputs the queue.
  // Postconditions: Displays the data in each node of queue
  // Required (used only for queue testing)
  template <class T>
  void Queue<T>::Display(){
   Node<T>* temp = m_head;
   while(temp != nullptr && m_size > 0){
      cout << temp->GetData() << endl;
      temp = temp->GetNext();
   }
  }
  // Name: Front
  // Preconditions: Requires a Queue with at least one node
  // Postconditions: Returns whatever data is pointed at by m_head -
  //                 Does NOT remove node
  template <class T>
  T Queue<T>::Front(){
   Node<T>* front = m_head->GetData();
   return front;
  }
  // Name: IsEmpty
  // Preconditions: Requires a queue
  // Postconditions: Returns if the queue is empty.
  template <class T>
  bool Queue<T>::IsEmpty(){
   if(m_head == nullptr){
      return true;
   }
   return false; 
  }
  // Name: GetSize
  // Preconditions: Requires a queue
  // Postconditions: Returns m_size
  template <class T>
  int Queue<T>::GetSize(){
   return m_size;
  }
  // Name: Find()
  // Preconditions: Requires a queue
  // Postconditions: Iterates and if it finds the thing, returns index, else -1
  template <class T>
  int Queue<T>::Find(T thing){
   Node<T>* temp = m_head;
   if(temp != nullptr && m_size > 0){
      for(int i = 0; i < m_size; i++){
         if(temp->GetData() == thing){
            return i;
         }
         temp = temp->GetNext();
      }
   }
   return -1;
  }
  // Name: Clear
  // Preconditions: Requires a queue
  // Postconditions: Deallocates and removes all nodes in a queue. No memory leaks
  template <class T>
  void Queue<T>::Clear(){
   Node<T>* current = m_head;
   Node<T>* next;

  // iterate through linked list 
   while(current != nullptr){ 
      next = current->GetNext();
      delete current; // delete each node
      current = next;
      m_size--;
   }
  //reset head and tail of linked list
   m_head = nullptr;
   m_tail = nullptr;
   current = nullptr;
   next = nullptr;
  }
  // Name: At
  // Precondition: Existing Queue
  // Postcondition: Returns object from Queue at a specific location
  // Desc: Iterates to node x and returns data from Queue
  template <class T>
  T& Queue<T>::At(int x){
   Node<T>* temp = m_head;
   int i = 0;
   while(temp != nullptr && i < x && m_size > 0){
      temp = temp->GetNext();
      i++;
   }
   return temp->GetData();
  }
  // Name: Swap(int)
  // Preconditions: Requires a queue
  // Postconditions: Swaps the nodes at the index with the node prior to it.
  // Example: Swap(1) would swap the node 0 with node 1 so
  //          that node 1 would now be m_head
  // Desc: Swaps two nodes by updating the pointers (not just the value)
  // Hint: Think about the special cases! Implement before Sort
  template <class T>
  void Queue<T>::Swap(int index){
   Node<T>* current = m_head;
   Node<T>* prev = nullptr;
   Node<T>* prevPrev = nullptr;
   int count = 0;
   if(index > m_size){
      cout << "Out of range" << endl;
      return;
   }
   if(index == 1){ // special case 1: index is the second node in list 
      current = current->GetNext(); // current is the second node in the list 
      m_head->SetNext(current->GetNext()); // make m_head (first node) point to third node
      current->SetNext(m_head); // make second node point to m_head (first node)
      m_head = current; // make current m_head 
   }else if(index == 0){
      cout << "Nothing to swap." << endl;
   }
   else{
      while(count != index){
         prevPrev = prev; // two nodes before selected node
         prev = current; // node before selected node 
         current = current->GetNext(); // selected node 
         count++;
      }
      if(index == m_size - 1){ // special case 2: index is last node in list 
         current->SetNext(prev); 
         prevPrev->SetNext(current);
         prev->SetNext(nullptr);
         m_tail = prev;
      }else{
         // all other cases 
         prev->SetNext(current->GetNext());
         current->SetNext(prev);
         prevPrev->SetNext(current);
      }
   }
  }
  // Name: Sort()
  // Preconditions: Requires a queue with a minimum of 2 nodes
  //                (otherwise notifies user)
  // Postconditions: Sorts the Queue (may use overloaded < or >).
  // Desc: This is used to sort anything in the Queue assuming the
  //       < or > is overloaded
  //        Uses bubble sort and Swap function above.
  //        Ensure working with queue_test before rest of project.
  // Note: Allowed to use the break command in just this function if necessary
  template <class T>
  void Queue<T>::Sort(){
   if(m_size < 2){
      cout << "You need at least two nodes." << endl;
   }else{
      int i, j;
      bool swapped = false;
      for(i = 0; i < m_size - 1; i++){ 
         swapped = false;
         for (j = 0; j < m_size - i - 1; j++) {
            if(At(j) > At(j + 1)){ 
               Swap(j + 1);
               swapped = true;
            }
         }
        // If no two elements were swapped
        // by inner loop, then break
         if (swapped == false)
         break;
      }
   }
}

#endif
