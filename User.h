#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User {
public:
    virtual void accessLevel() {
        cout << "User: Basic account access." << endl;
    }

    virtual ~User() {} // ensures proper cleanup through base pointers
};

#endif

