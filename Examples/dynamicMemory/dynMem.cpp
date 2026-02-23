#include <iostream> 
using namespace std;



int main(){
    cout << "hi" << endl;

    int x; 
    cout << "Enter a length of the array that you want: ";
    cin >> x;

    int *ptrArray = new int[x];

    for (int i = 0; i < x; i++){
        cout << "Enter value for position " << i + 1 << ": ";
        cin >> ptrArray[i];
    }

    for (int i = 0; i < x; i++){
        cout << ptrArray[i] << " "; 
    }
    cout << endl;

    delete [] ptrArray;  

    int *mrPtr = new int(3);
    cout << *mrPtr << endl;

    delete mrPtr;

    double *mrDouble = new double(3.14);
    cout << *mrDouble << endl;
    delete mrDouble;

    return 0;
}