#include "InventoryManager.h"

int main() {
    InventoryManager manager;

    cout << "Calling accessLevel() on InventoryManager object:" << endl;
    manager.accessLevel();

    cout << "\nCalling through base class pointers (polymorphism):" << endl;

    User* u = &manager;
    Employee* e = &manager;

    u->accessLevel();  // still calls InventoryManager version
    e->accessLevel();  // still calls InventoryManager version

    return 0;
}
