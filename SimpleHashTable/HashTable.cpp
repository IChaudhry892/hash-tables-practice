#include <iostream>
#include <list>
#include <cstring>
using namespace std;

// Hashtable to implement 905, Jimmy

class HashTable{
private:
    static const int hashGroups = 10;
    list<pair<int, string>> table[hashGroups]; // List 1, Index 0, List 2, Index 1....

public:
    bool isEmpty() const;
    int hashFunction(int key);
    void insertItem(int key, string value);
    void removeItem(int key);
    string searchItem(int key);
    void printTable();
};

bool HashTable::isEmpty() const{
    int sum{};
    for (int i{}; i < hashGroups; i++){
        sum += table[i].size();
    }
    if (!sum){
        return true;
    }
    return false;
}

int HashTable::hashFunction(int key){
    return key % hashGroups; //Key: 905, in return, this function will spit out 5.
}

void HashTable::insertItem(int key, string value){
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto beginningIterator = begin(cell);
    bool keyExists = false;
    for (; beginningIterator != end(cell); beginningIterator++){
        if (beginningIterator->first == key){
            keyExists = true;
            beginningIterator->second = value;
            cout << "[WARNING] Key exists. Value replaced." << endl;
            break;
        }
    }

    if (!keyExists){
        cell.emplace_back(key, value);
    }

    return;
}

void HashTable::removeItem(int key){
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto beginningIterator = begin(cell);
    bool keyExists = false;
    for (; beginningIterator != end(cell); beginningIterator++){
        if (beginningIterator->first == key){
            keyExists = true;
            beginningIterator = cell.erase(beginningIterator);
            cout << "[INFO] Pair removed." << endl;
            break;
        }
    }

    if (!keyExists){
        cout << "[WARNING] Key not found. Pair not removed." << endl;
    }

    return;
}

string HashTable::searchItem(int key){
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto beginningIterator = begin(cell);
    bool keyExists = false;
    for (; beginningIterator != end(cell); beginningIterator++){
        if (beginningIterator->first == key){
            keyExists = true;
            return beginningIterator->second;
        }
    }

    // if (!keyExists){
    return "[WARNING] Key not found.";
    // }
}

void HashTable::printTable(){
    for (int i{}; i < hashGroups; i++){
        if (table[i].size() == 0) continue;

        auto beginningIterator = table[i].begin();
        for (; beginningIterator != table[i].end(); beginningIterator++){
            cout << "[INFO] Key: " << beginningIterator->first << " Value: " << beginningIterator->second << endl;
        }
    }
    return;
}

int main(){
    HashTable HT;

    if (HT.isEmpty()){
        cout << "Correct answer. Good job." << endl;
    } else{
        cout << "Uh oh. We need to check our code!" << endl;
    }

    HT.insertItem(905, "SpongeBob");
    HT.insertItem(201, "Squidward");
    HT.insertItem(332, "Gary");
    HT.insertItem(124, "Patrick");
    HT.insertItem(107, "Sandy");
    HT.insertItem(929, "Mr.Krabs");
    HT.insertItem(928, "Plankton");
    HT.insertItem(128, "Larry");

    HT.printTable();

    HT.removeItem(332);
    HT.removeItem(100);

    if (HT.isEmpty()){
        cout << "Uh oh. We need to check our code!" << endl;
    } else{
        cout << "Correct answer! Good job!" << endl;
    }


    return 0;
}