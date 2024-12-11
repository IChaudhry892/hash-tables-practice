#include <iostream>
#include <cstring>
#include <list>
#include "HashTable.h"
using namespace std;

HashTable::HashTable(){

}

bool HashTable::isEmpty(){
    int sum = 0;
    for (int i = 0; i < hashGroups; i++){
        sum += table[i].size();
    }
    if (sum == 0){
        return true;
    }
    return false;
}

int HashTable::hashFunction(int key){
    return key % hashGroups;
}

void HashTable::insertItem(int key, string value){
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
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
    }
}

void HashTable::removeItem(int key){
    int hashValue = hashFunction(key); //hashValue is the bucket/index
    auto& cell = table[hashValue]; //cell is the list in the table at the hashValue bucket?
    auto beginningIterator = begin(cell);
    bool keyExists = false;
    while (beginningIterator != end(cell)){
        if (beginningIterator->first == key){
            keyExists = true;
            cout << "[INFO] Removing Pair <" << beginningIterator->first << ", " << beginningIterator->second << ">" << endl;
            beginningIterator = cell.erase(beginningIterator);
            cout << "[INFO] Pair was removed successfuly.\n";
            break;
        }
        beginningIterator++;
    }

    if (!keyExists){
        cout << "[WARNING] Key not found. Pair not removed.\n";
    }
}

string HashTable::searchItem(int key){
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto beginningIterator = begin(cell);
    bool keyExists = false;
    while (beginningIterator != end(cell)){
        if(beginningIterator->first == key){
            keyExists = true;
            return beginningIterator->second;
        }
        beginningIterator++;
    }

    return "[WARNING] Key not found. Search failed.";
}

int HashTable::numItemsInBucket(int bucket){
    int count = 0;
    auto& cell = table[bucket];
    auto beginningIterator = begin(cell);
    while (beginningIterator != end(cell)){
        count++;
        beginningIterator++;
    }
    return count;
}

void HashTable::printTable(){
    for (int i = 0; i < hashGroups; i++){
        if (table[i].size() == 0){
            continue;
        }
        
        cout << "------------------------------------\n";
        cout << "Bucket " << i << endl;
        auto beginningIterator = table[i].begin();
        while (beginningIterator != table[i].end()){
            cout << "[INFO] Key: " << beginningIterator->first << " | Value: " << beginningIterator->second << endl;
            beginningIterator++;
        }
        cout << "# of items in bucket: " << numItemsInBucket(i) << endl;
    }
    cout << "------------------------------------\n";
    return;
}