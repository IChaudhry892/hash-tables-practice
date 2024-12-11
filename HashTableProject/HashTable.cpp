#include <cstdlib>
#include <iostream>
#include <string>
#include "HashTable.h"
using namespace std;

HashTable::HashTable(){
    for (int i = 0; i < tableSize; i++){
        table[i] = new item;
        table[i]->name = "empty";
        table[i]->drink = "empty";
        table[i]->next = nullptr;
    }
}

int HashTable::hashFunction(string key){
    int hash = 0;
    int index;

    for (int i = 0; i < key.length(); i++){
        // hash += (int)key[i];
        hash += ((int)key[i]) * 17;
        // cout << "hash = " << hash << endl;
    }
    index = hash % tableSize;

    return index; //bucket
}

void HashTable::addItem(string name, string drink){
    int index = hashFunction(name);

    if (table[index]->name == "empty"){
        table[index]->name = name;
        table[index]->drink = drink;
    } else{
        item* ptr = table[index];
        item* newItem = new item;
        newItem->name = name;
        newItem->drink = drink;
        newItem->next = nullptr;
        while (ptr->next != nullptr){
            ptr = ptr->next;
        }
        ptr->next = newItem;
    }
}

void HashTable::removeItem(string name){
    int index = hashFunction(name);

    item* delPtr;
    item* ptr1;
    item* ptr2;
    //Case 0 - bucket is emtpy
    if (table[index]->name == "empty" && table[index]->drink == "empty"){
        cout << name << " was not found in the Hash Table\n";
    }
    //Case 1 - only 1 item in bucket and that item has a matching name
    else if (table[index]->name == name && table[index]->next == nullptr){
        table[index]->name = "empty";
        table[index]->drink = "empty";

        cout << name << " was removed from the Hash Table\n";
    }
    //Case 2 - match is in the first item in the bucket but there are more items in the bucket
    else if (table[index]->name == name){
        delPtr = table[index];
        table[index] = table[index]->next;
        delete delPtr;

        cout << name << " was removed from the Hash Table\n";
    }
    //Case 3 - bucket contains items but first item is not a match
    else {
        ptr1 = table[index]->next;
        ptr2 = table[index];

        while(ptr1 != nullptr && ptr1->name != name){
            ptr2 = ptr1;
            ptr1 = ptr1->next;
        }
        //Case 3.1 - no match
        if (ptr1 == nullptr){
            cout << name << " was not found in the Hash Table\n";
        }
        //Case 3.2 - match is found
        else {
            delPtr = ptr1;
            ptr1 = ptr1->next;
            ptr2->next = ptr1;

            delete delPtr;
            cout << name << " was removed from the Hash Table\n";
        }
    }
}

int HashTable::numItemsInIndex(int index){
    int count = 0;
    if(table[index]->name == "empty"){
        return count;
    } else{
        count++;
        item* ptr = table[index];
        while (ptr->next != nullptr){
            count++;
            ptr = ptr->next;
        }
    }
    return count;
}

void HashTable::findDrink(string name){
    int index = hashFunction(name);
    bool foundName = false;
    string drink;

    item* ptr = table[index];
    while (ptr != nullptr){
        if (ptr->name == name){
            foundName = true;
            drink = ptr->drink;
        }
        ptr = ptr->next;
    }
    if (foundName == true){
        cout << "Favorite drink = " << drink << endl;
    } else{
        cout << name << "'s info was not found in the Hash Table\n";
    }
}

void HashTable::printTable(){
    int number;
    for (int i = 0; i < tableSize; i++){
        number = numItemsInIndex(i);
        cout << "------------------\n";
        cout << "index = " << i << endl;
        cout << table[i]->name << endl;
        cout << table[i]->drink << endl;
        cout << "# of times = " << number << endl;
        cout << "------------------\n";
    }
}

void HashTable::printItemsInIndex(int index){
    item* ptr = table[index];

    if (ptr->name == "empty"){
        cout << "index = " << index << " is empty" << endl;
    } else{
        cout << "index " << index << " contains the following items\n";
        while(ptr != nullptr){
            cout << "------------------\n";
            cout << ptr->name << endl;
            cout << ptr->drink << endl;
            cout << "------------------\n";
            ptr = ptr->next;
        }
    }
}