#include "HashTable.h"
#include <iostream>
using namespace std;

int main(){
    HashTable myHash;
    int choice, value;

    while (true){
        cout << "\n==== Hash Table Menu ====\n";
        cout << "1. Insert item\n";
        cout << "2. Search for item\n";
        cout << "3. Delete item\n";
        cout << "4. Print table\n";
        cout << "5. Exit program\n";
        cout << "Enter choice (1-5): ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                myHash.insertItem(value);
                break;
            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                myHash.searchItem(value);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                myHash.deleteItem(value);
                break;
            case 4:
                cout << "Current table:\n";
                myHash.printTable();
                break;
            case 5:
                cout << "Exiting program, bye!\n";
                return 0;
                break;
            default:
                cout << "Invalid choice, try again.\n";
                break;
        }
    }


    return 0;
}