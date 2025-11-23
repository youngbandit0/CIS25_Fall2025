#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include "Employee.h"

class InventoryManager : public Employee {
public:
    void accessLevel() override {
        cout << "Inventory Manager: Full access to inventory operations." << endl;
    }
};

#endif
