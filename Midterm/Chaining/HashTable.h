#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <list>
#include <iostream>
using namespace std;

class HashTable{
private:
    static const int hashGroups = 10;
    list<pair<int, int>> table[hashGroups];

public:
    HashTable();

    int hashFunction(int key);
    void insertItem(int value);
    void deleteItem(int value);
    void searchItem(int value);
    void printTable();
};


#endif