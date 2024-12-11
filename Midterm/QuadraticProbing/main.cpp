#include "HashTable.h"
#include <iostream>
using namespace std;

int main(){
    HashTable myHash;
    int choice, value;

    while (true){
        cout << "\n==== Hash Table Menu ====" << endl;
        cout << "1. Insert item" << endl;
        cout << "2. Delete item" << endl;
        cout << "3. Search for item" << endl;
        cout << "4. Print table" << endl;
        cout << "5. Exit program" << endl;
        cout << "Enter choice (1-5): ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                myHash.insertItem(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                myHash.deleteItem(value);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                myHash.searchItem(value);
                break;
            case 4:
                cout << "Current table:" << endl;
                myHash.printTable();
                break;
            case 5:
                cout << "Exiting program, bye!" << endl;
                return 0;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
                break;
        }
    }



    return 0;
}