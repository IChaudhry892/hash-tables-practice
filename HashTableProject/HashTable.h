#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable{
private:
    static const int tableSize = 4;
    
    struct item{
        string name;
        string drink;
        item* next;
    };

    item* table[tableSize];

public:
    HashTable();

    int hashFunction(string key);
    void addItem(string name, string drink);
    void removeItem(string name);
    int numItemsInIndex(int index);
    void findDrink(string name);
    void printTable();
    void printItemsInIndex(int index);

};

#endif