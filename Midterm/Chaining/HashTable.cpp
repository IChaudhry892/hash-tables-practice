#include "HashTable.h"

HashTable::HashTable(){}

int HashTable::hashFunction(int key){
    return key % hashGroups;
}

void HashTable::insertItem(int value){
    int key = value;
    int index = hashFunction(key);
    auto& cell = table[index];
    auto beginningIterator = begin(cell);
    bool keyExists = false;
    while (beginningIterator != end(cell)){
        if (beginningIterator->first == key){
            keyExists = true;
            beginningIterator->second = value;
            cout << "[WARNING] Key exists. Value replaced.\n";
            break;
        }
        beginningIterator++;
    }

    if (!keyExists){
        cell.emplace_back(key, value);
        cout << "[INFO] Inserted value " << value << " at index " << index << endl;
    }
    
}

void HashTable::deleteItem(int value){
    int key = value;
    int index = hashFunction(key);
    auto& cell = table[index];
    auto beginningIterator = begin(cell);
    bool keyExists = false;
    while (beginningIterator != end(cell)){
        if (beginningIterator->first == key){
            keyExists = true;
            cout << "[INFO] Removing Pair <" << key << ", " << value << ">" << endl;
            beginningIterator = cell.erase(beginningIterator);
            cout << "[INFO] Pair was removed successfuly.\n";
            break;
        }
        beginningIterator++;
    }

    if (!keyExists){
        cout << "[WARNING] Value not found. Pair not removed\n";
    }
}

void HashTable::searchItem(int value){
    int key = value;
    int index = hashFunction(key);
    auto& cell = table[index];
    auto beginningIterator = begin(cell);
    bool keyExists = false;
    while (beginningIterator != end(cell)){
        if (beginningIterator->first == key){
            keyExists = true;
            cout << "[INFO] Value " << value << " found at index " << index << endl;
            break;
        }
        beginningIterator++;
    }

    if (!keyExists){
        cout << "[WARNING] Value not found\n";
    }
}

void HashTable::printTable(){
    for (int i = 0; i < hashGroups; i++){
        if (table[i].size() == 0){
            continue;
        }

        cout << "------------------------------------\n";
        cout << "Index: " << i << endl;
        auto beginningIterator = table[i].begin();
        while (beginningIterator != table[i].end()){
            cout << "Key: " << beginningIterator->first << " | Value: " << beginningIterator->second << endl;
            beginningIterator++;
        }
    }
    cout << "------------------------------------\n";
    // return;
}