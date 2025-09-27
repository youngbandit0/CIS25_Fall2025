#include <iostream>  
using namespace std;


void showMenu() {
    cout << "\n=== Main Menu ===\n";
    cout << "1. Add Two Numbers\n";
    cout << "2. View a Message\n";
    cout << "3. Exit\n";
    cout << "Choose an option: ";
}


void addNumbers() {
    int a, b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    cout << "Sum = " << a + b << endl;
}


void viewMessage() {
    cout << "Hello! This is your message." << endl;
}


int main() {
    int option;
    do {
        showMenu();      
        cin >> option;  

       
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

    } while (option != 3);  

    return 0;
}
