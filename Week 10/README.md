Inventory Program (C++)


This project is a basic C++ inventory system that demonstrates how to use classes across multiple files. It includes:


A class defined in a header (Item.h)


Class implementation in a source file (Item.cpp)


A main program (main.cpp) that uses an array of Item objects

User input, inventory display, and item search functionality


Files

Item.h      // Class definition

Item.cpp    // Class implementation

main.cpp    // Program logic

README.md   // Project documentation



Features

✔ Item Class
The Item class stores:
name (string)
quantity (int)
Includes constructors, setters, and getters.

✔ User Input
The program asks the user to enter a name and quantity for each item.

✔ Inventory Display
After input, all items are printed in list form.

✔ Search Function
The user can search for an item by name.
If found, the program prints its quantity; if not, it shows a “not found” message.


How to Compile:

Use g++:

g++ main.cpp Item.cpp -o inventory


How to Run:

./inventory
