
#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

int searchItem(Item items[], int size, const string& target) {
    for (int i = 0; i < size; i++) {
        if (items[i].getName() == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    const int SIZE = 5;
    Item items[SIZE];

    cout << "Enter inventory items:\n";

    for (int i = 0; i < SIZE; i++) {
        string name;
        int qty;

        cout << "\nItem #" << (i + 1) << endl;

        cout << "Name: ";
        cin >> ws;       // eat whitespace
        getline(cin, name);

        cout << "Quantity: ";
        cin >> qty;

        items[i].setName(name);
        items[i].setQuantity(qty);
    }

    cout << "\n--- Inventory List ---\n";
    for (int i = 0; i < SIZE; i++) {
        cout << items[i].getName() << " - " << items[i].getQuantity() << endl;
    }

    cout << "\nSearch for an item by name: ";
    string searchName;
    cin >> ws;
    getline(cin, searchName);

    int idx = searchItem(items, SIZE, searchName);

    if (idx != -1) {
        cout << "Found! Quantity: " << items[idx].getQuantity() << endl;
    } else {
        cout << "Item not found.\n";
    }

    return 0;
}
