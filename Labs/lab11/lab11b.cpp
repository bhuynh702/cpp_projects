#include <iostream>
using namespace std;

template <class T>
class DynamicArray {
public:
  DynamicArray() {
    size = 0;
    arr = new T[size];
  }
  
  ~DynamicArray() {
    delete[] arr;
  }
  
  void Push(T val) {
    T temp[size + 1];
    
    for (int i = 0; i < size; ++i) {
      temp[i] = arr[i];
    }
    temp[size] = val;
    delete[] arr;
    
    arr = new T[size + 1];
    for (int i = 0; i < size + 1; ++i) {
      arr[i] = temp[i];
    }
    
    ++size;
  }
  
  // COMPLETE THIS FUNCTION
  void Pop() {
    // This function should remove an element from the end of the dynamic array
    
    // HINTS:
    // - Create a temporary array with size - 1 elements
    // - Loop through arr array and copy them over to temp
    // - Deallocate arr
    // - Reinitialize with size - 1 elements
    // - Loop through temp array and copy them over to arr
    // - Decrease the size variable by 1
    T temp[size - 1];

    for(int i = 0; i < size; i++){
      temp[i] = arr[i];
    }
    delete[] arr; 

    arr = new T[size - 1];

    for (int i = 0; i < size + 1; ++i) {
      arr[i] = temp[i];
    }
    --size;
  }
  
  void Display() {
    cout << "Dynamic Array Elements:" << endl;
    for (int i = 0; i < size; ++i) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
  
private:
  T* arr;
  int size;
};

int main() {
  DynamicArray<int> darr;
  darr.Display();
  darr.Push(1);
  darr.Display();
  darr.Push(2);
  darr.Push(5);
  darr.Push(3);
  darr.Display();
  darr.Pop();
  darr.Display();
  
  return 0;
}
