#include <iostream>
#include <string>
using namespace std;

void changeInts(int x, int & y) 
{
    x += 5;
    y += 7;
    cout << x << " " << y << endl; 
}

void changeArray(int array[]){
    for (int i = 0; i < 10; i++) 
    {
        cout << "what should we put in array[" << i << " ]" << endl;
        cin >> array[i];
 
    }
}
int main()
{
    /*
    What is a pointer? 
    A pointer is a variable that contains memory address
    & = reference operator which gets us the memory location of a variable 
    * = dereference operator which gets us the value of the variable 
    */
//    int t = 15;
//    int s = 23;
//    int * pt = &t, *ps, &s;

//    *pt += 7;
//    cout << *pt << " " << t << " " << pt << " " << &t << endl;

    int x = 2, y = 4;
    changeInts(x, y);

    int myArray[10] = {2, 5, 3, 1, 9};

    for ( int j = 0; j < 10; j++) {
        cout << myArray[j] << ", ";
    }
    cout << endl;

   return 0;
}