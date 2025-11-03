#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
using namespace std;

class BankAccount {
private:
    string ownerName;
    double balance;
    string filename;

public:
    // Constructor
    BankAccount(string name, double initialBalance, string file = "transactions.txt");

    // Core functions
    void deposit(double amount);
    void purchase(double amount, string item);
    void displayBalance() const;
    void displayTransactions() const;
};

#endif
