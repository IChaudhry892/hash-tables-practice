#include <cstring>
#include <list>
using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable{
private:
    static const int hashGroups = 10;
    list<pair<int, string>> table[hashGroups];

public:
    HashTable();

    bool isEmpty();
    int hashFunction(int key);
    void insertItem(int key, string value);
    void removeItem(int key);
    string searchItem(int key);
    int numItemsInBucket(int bucket);
    void printTable();
};

#endif