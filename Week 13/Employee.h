#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "User.h"

class Employee : public User {
public:
    void accessLevel() override {
        cout << "Employee: Access to standard inventory features." << endl;
    }
};

#endif
