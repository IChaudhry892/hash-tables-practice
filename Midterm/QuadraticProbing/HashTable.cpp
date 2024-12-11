#include "HashTable.h"

HashTable::HashTable() : table(hashGroups, -1), isOccupied(hashGroups, false) {}

int HashTable::hashFunction(int key){
    return key % hashGroups;
}

void HashTable::insertItem(int value){
    int key = value;
    int index = hashFunction(key);
    int i = 0;

    while (isOccupied[index] && table[index] != value && i < hashGroups){
        i++;
        index = (hashFunction(key) + i * i) % hashGroups;
    }

    if (i == hashGroups){ //no empty spots
        cout << "[WARNING] Hash table is full. Cannot insert value " << value << ".\n";
    }

    if (isOccupied[index] && table[index] == value){
        cout << "[INFO] Value " << value << " already exists in the table at index " << index << ".\n";
    } else{
        table[index] = value;
        isOccupied[index] = true;
        cout << "[INFO] Inserted value " << value << " at index " << index << ".\n";
    }
}

bool HashTable::insertItem2(int value){
    int key = value;
    int index = hashFunction(key);
    int i = 0;
    int bucketsProbed = 0;

    while (bucketsProbed < hashGroups){
        if (table[index] == -1){
            table[index] = value;
            cout << "[INFO] Inserted value " << value << " at index " << index << ".\n";
            return true;
        }

        i++;
        index = (hashFunction(key) + i + i * i) % hashGroups;
        bucketsProbed++;
    }
    return false;
}

void HashTable::deleteItem(int value){
    int key = value;
    int index = hashFunction(key);
    int i = 0;

    while (isOccupied[index] && table[index] != value && i < hashGroups){
        i++;
        index = (hashFunction(key) + i * i) % hashGroups;
    }

    if (table[index] == value){
        table[index] = -1;
        isOccupied[index] = false;
        cout << "[INFO] Value " << value << " deleted from index " << index << ".\n";
    } else{
        cout << "[WARNING] Value " << value << " not found in the table.\n";
    }
}

void HashTable::searchItem(int value){
    int key = value;
    int index = hashFunction(key);
    int i = 0;

    while (isOccupied[index] && table[index] != value && i < hashGroups){
        i++;
        index = (hashFunction(key) + i * i) % hashGroups;
    }

    if (table[index] == value){
        cout << "[INFO] Value " << value << " found at index " << index << ".\n";
    } else{
        cout << "[WARNING] Value " << value << " not found in the table.\n";
    }
}

void HashTable::printTable(){
    for(int i = 0; i < hashGroups; i++){
        if (isOccupied[i]){
            cout << "Index " << i << ": " << table[i] << endl;
        } else{
            cout << "Index " << i << ": " << "Empty" << endl;
        }
    }
}