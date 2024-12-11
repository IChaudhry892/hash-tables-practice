#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <iostream>
using namespace std;

class HashTable{
private:
    static const int hashGroups = 10;
    vector<int> table;
    vector<bool> isOccupied;

public:
    HashTable();

    int hashFunction(int key);
    void insertItem(int value);
    bool insertItem2(int value);
    void deleteItem(int value);
    void searchItem(int value);
    void printTable();
};

#endif