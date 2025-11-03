#include "BankAccount.h"
#include <iostream>
#include <limits>
#include <string>
using namespace std;

double readAmount(const string& prompt) {
    while (true) {
        cout << prompt;
        double amt;
        if (cin >> amt) return amt;
        cout << "Invalid number. Try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    cout << "Enter account owner name: ";
    string name;
    getline(cin, name);

    double startBal = 0.0;
    cout << "Enter starting balance: ";
    while (!(cin >> startBal)) {
        cout << "Invalid number. Try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear newline

    BankAccount acct(name, startBal, "transactions.txt");

    while (true) {
        cout << "\n==== Bank Menu ====\n"
             << "1) Deposit\n"
             << "2) Purchase\n"
             << "3) Show Balance\n"
             << "4) Show Transactions\n"
             << "5) Exit\n"
             << "Choose an option: ";

        int choice;
        if (!(cin >> choice)) {
            cout << "Please enter a number 1-5.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // consume newline

        if (choice == 1) {
            double amt = readAmount("Deposit amount: ");
            acct.deposit(amt);
        } else if (choice == 2) {
            double amt = readAmount("Purchase amount: ");
            cout << "Item description: ";
            string item;
            getline(cin, item);
            acct.purchase(amt, item);
        } else if (choice == 3) {
            acct.displayBalance();
        } else if (choice == 4) {
            acct.displayTransactions();
        } else if (choice == 5) {
            cout << "Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice. Try 1-5.\n";
        }
    }
    return 0;
}
