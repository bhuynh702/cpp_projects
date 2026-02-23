#include <iostream> 
using namespace std; 

// void loadFile(){
//     string type; 
//     string price;
//     double doublePrice; 
//     string brand;
//     string quantity;
//     int intQuantity;

//     ifstream candyFile(candy.txt);
//     if(candyFile.is_open){
//         while(getline(candyFile, type, ',') && getline(candyFile, price, ',') 
//         && getline(candyFile, brand, ',') && getline(candyFile, quantity)){
//         doublePrice = stod(price);
//         intQuantity = stoi(quantity);
//         vector.push_back(new Candy(type, doublePrice, brand, intQuantity));
//         }
//     }
//     candyFile.close();
// }

void rotateArray(int arr[], int size){
    int first = arr[0];
    for(int i = 0; i < size; i++){
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = first;
}

int everyFifth(int start, int finish){
    int total = 0;
    if(total == finish){
        return total;
    }else if(start < finish){
        for(int i = start; i <= finish; i += 5){
            total += i;
        }
    }else{
        for(int i = finish; i <= start; i += 5){
            total += i;
        }
    }
    return total;
}

class GolfCourse {
    public: 
    GolfCourse(): m_name(""), m_address(""){}
    string GetName(){ return m_name; }
    string GetAddress() { return m_address; }
    void SetName(string name) { m_name = name; }
    void SetAddress(string address) { m_address = address; }
    void AddHole()
}

int main () {
    int arr[5] = {12, 1, 2, 3, 4};
    rotateArray(arr, 5);
    for(int i = 0; i < 5; i ++){
        cout << arr[i] << " ";
    }
    
    cout << everyFifth(3, 13) << endl;
    cout << everyFifth(20, 10) << endl;
    cout << everyFifth(-16, -1) << endl;
    cout << everyFifth(9, 9) << endl;

    return 0;
}


