#include "BankAccount.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

BankAccount::BankAccount(string name, double initialBalance, string file)
    : ownerName(name), balance(initialBalance), filename(file) {
    ofstream fout(filename, ios::app);
    fout << "Account created for " << ownerName 
         << " | Starting balance: $" << fixed << setprecision(2) << balance << endl;
}

void BankAccount::deposit(double amount) {
    balance += amount;
    ofstream fout(filename, ios::app);
    fout << "Deposit: +" << fixed << setprecision(2) << amount 
         << " | Balance: $" << balance << endl;
    cout << "Deposited $" << amount << " successfully." << endl;
}

void BankAccount::purchase(double amount, string item) {
    if (amount > balance) {
        cout << "Insufficient funds for " << item << "!" << endl;
        return;
    }
    balance -= amount;
    ofstream fout(filename, ios::app);
    fout << "Purchase: -" << fixed << setprecision(2) << amount 
         << " (" << item << ") | Balance: $" << balance << endl;
    cout << "Purchased " << item << " for $" << amount << endl;
}

void BankAccount::displayBalance() const {
    cout << "Current balance: $" << fixed << setprecision(2) << balance << endl;
}

void BankAccount::displayTransactions() const {
    ifstream fin(filename);
    if (!fin) {
        cout << "No transaction history found." << endl;
        return;
    }

    cout << "\n--- Transaction History ---" << endl;
    string line;
    while (getline(fin, line))
        cout << line << endl;
}
