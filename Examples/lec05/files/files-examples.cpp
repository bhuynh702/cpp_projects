//
//  main.cpp
//  files
//
//  Created by Brittany Huynh on 2/13/24.
//

#include <iostream>
#include <fstream> // for file input
#include <string>

using namespace std;

void myFile() {
    
    string filename;
    cout << "Please enter the filename: " << endl;
    cin >> filename;
    
    fstream my_file(filename, ios_base::out);
    
    string contents = "";
    do
    {
        my_file << contents << endl;
        cout << "What do you want to add to the file? " << endl;
        cin >> contents;
        
    }while (contents != "quit");
    my_file.close();
    
}

int main() {
    string filename;
    cout << "Enter a file to read: " << endl;
    cin >> filename;
    
    fstream read_file;
    
    read_file.open(filename, ios_base::in);
    string contents;
    
    while (!read_file.eof())
    {
        read_file >> contents;
        cout << contents << endl;
        
    }
    
    read_file.close();
    
    return 0;
}