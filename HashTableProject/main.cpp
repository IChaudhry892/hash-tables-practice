#include <cstdlib>
#include <iostream>
#include <string>
#include "HashTable.h"
using namespace std;

int main(){
    HashTable myHash;
    string name = "";

    myHash.addItem("SpongeBob", "Kelp Shake");
    myHash.addItem("Patrick", "Strawberry Smoothy");
    myHash.addItem("Sandy", "Iced Mocha");
    myHash.addItem("Squidward", "Locha");
    myHash.addItem("Gary", "Hot Chocolate");
    myHash.addItem("Plankton", "Root Beer");
    myHash.addItem("Mr. Krabs", "Water");
    myHash.addItem("Pearl", "Green Tea");
    myHash.addItem("Larry", "Skinny Latte");
    myHash.addItem("Mrs. Puff", "Chai Tea");
    myHash.addItem("Karen", "Caramel Mocha");
    myHash.addItem("Mermaid Man", "Apple Cider");

    myHash.printTable();
    // myHash.printItemsInIndex(3);

    while (name != "exit"){
        cout << "Remove ";
        cin >> name;
        if (name != "exit"){
            myHash.removeItem(name);
        }
    }

    myHash.printTable();
    // myHash.printItemsInIndex(3);


    return 0;
}