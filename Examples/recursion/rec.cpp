/*
Topic: Recursion
Thu Apr 25, 2024
*/
#include <iostream>
#include <string>
using namespace std;

int count_as_better(string s, unsigned int i = 0){
    if(i == s.length()){
        return 0; // base case
    }
    if(s[i] == 'a' || s[i] == 'A'){
        return 1 + count_as_better(s, i + 1);
    }
    else {
        return 0 + count_as_better(s, i + 1);
    }
}

template<typename T>
struct LLN {
    LLN(T nd = T()) : data(nd), p_next(nullptr) {}
    void insertAtTail(T newData);
    T data;
    LLN * p_next;

    private:
    void insertTailRecur(T newData, LLN<T> * current);
};

template<typename T>
void insertAtTail(T newData){
    insertTailRecur(newData);
}

template<typename T>
void insertTailRecur(T newData, LLN<T> * current){
    if(current->p_next != nullptr){
        current->p_next = new LLN<T>(newData);
    }
    else{
        insertTailRecur(newData, current->p_next);
    }
}




int main(){
    cout << count_as_better("Abba") << endl;
    cout << count_as_better("gfhdrjs") << endl;
    cout << count_as_better("abaaba") << endl;



    return 0;
}