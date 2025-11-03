#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
using namespace std;

class BankAccount {
private:
    string ownerName;
    double balance;
    string filename;

    void logLine(const string& line) const;   // helper to append to file
    static string nowTimestamp();              // ISO timestamp

public:
    // Constructor
    BankAccount(string name, double initialBalance, string file = "transactions.txt");

    // Core actions
    void deposit(double amount);
    bool purchase(double amount, const string& item); // returns success/fail

    // Queries
    void displayBalance() const;
    void displayTransactions() const;
    double getBalance() const { return balance; }
    const string& getOwnerName() const { return ownerName; }
};

#endif
