README


Overview

This project demonstrates how inheritance and polymorphism work in C++ by creating a small class hierarchy for an inventory system. Each user role provides its own version of the accessLevel() method, showing how child classes can override and customize parent behavior.
The program includes:


A base class User

A derived class Employee

A more specialized derived class InventoryManager

A main.cpp file that tests how overridden methods behave when accessed directly and through base-class pointers


This models a simple role-based access control system.
Class Hierarchy
User
 └── Employee
       └── InventoryManager

User.h	Defines the base class with a virtual method

Employee.h	Inherits from User and overrides accessLevel()

InventoryManager.h	Inherits from Employee and overrides accessLevel()

main.cpp	Creates an InventoryManager object and tests polymorphism
