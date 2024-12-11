#include <iostream>
#include <cstring>
#include <list>
#include "HashTable.h"
using namespace std;

int main(){
    HashTable myHash;
    int choice, key;
    string value; //name

    while (true){
        cout << "1. Insert Item" << endl;
        cout << "2. Remove Item" << endl;
        cout << "3. Search Item" << endl;
        cout << "4. Print Table" << endl;
        cout << "5. Exit Program" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        
        switch(choice){
            case 1:
                cout << "Enter key of item: ";
                cin >> key;
                cout << "Enter value of item (name): ";
                cin.ignore();
                getline(cin, value);
                myHash.insertItem(key, value);
                break;
            case 2:
                cout << "Enter key of item: ";
                cin >> key;
                myHash.removeItem(key);
                break;
            case 3:
                cout << "Enter key of item: ";
                cin >> key;
                cout << "Value mapped to key: " << myHash.searchItem(key) << endl;
                break;
            case 4:
                cout << "Current Table:" << endl;
                myHash.printTable();
                break;
            case 5:
                cout << "Exiting program, bye!" << endl;
                return 0;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    }


    return 0;
}