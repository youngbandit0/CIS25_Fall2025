#include <iostream>  // Header file for input/output
using namespace std;

// Function to display the menu
void showMenu() {
    cout << "\n=== Main Menu ===\n";
    cout << "1. Add Two Numbers\n";
    cout << "2. View a Message\n";
    cout << "3. Exit\n";
    cout << "Choose an option: ";
}

// Function for Option 1: Add two numbers
void addNumbers() {
    int a, b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    cout << "Sum = " << a + b << endl;
}

// Function for Option 2: View a message
void viewMessage() {
    cout << "Hello! This is your message." << endl;
}

// Main function
int main() {
    int option;
    do {
        showMenu();      // Show menu
        cin >> option;   // Get user choice

        // Handle menu options
        if (option == 1) {
            addNumbers();
        } 
        else if (option == 2) {
            viewMessage();
        } 
        else if (option == 3) {
            cout << "Exiting the program..." << endl;
        } 
        else {
            cout << "Invalid option. Please try again." << endl;
        }

    } while (option != 3);  // Repeat until user chooses to exit

    return 0;
}
