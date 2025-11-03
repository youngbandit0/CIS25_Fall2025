#include "BankAccount.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <sstream>
using namespace std;

static string money(double x) {
    ostringstream os;
    os << fixed << setprecision(2) << x;
    return os.str();
}

string BankAccount::nowTimestamp() {
    using namespace std::chrono;
    auto t = system_clock::to_time_t(system_clock::now());
    std::tm tm{};
#if defined(_WIN32)
    localtime_s(&tm, &t);
#else
    localtime_r(&t, &tm);
#endif
    ostringstream os;
    os << put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return os.str();
}

void BankAccount::logLine(const string& line) const {
    ofstream fout(filename, ios::app);
    if (fout) fout << line << '\n';
}

BankAccount::BankAccount(string name, double initialBalance, string file)
    : ownerName(std::move(name)), balance(initialBalance), filename(std::move(file)) {
    logLine("[" + nowTimestamp() + "] Account created for " + ownerName +
            " | Starting balance: $" + money(balance));
}

void BankAccount::deposit(double amount) {
    if (amount <= 0) {
        cout << "Amount must be positive.\n";
        return;
    }
    balance += amount;
    logLine("[" + nowTimestamp() + "] Deposit: +$" + money(amount) +
            " | Balance: $" + money(balance));
    cout << "Deposited $" << money(amount) << ".\n";
}

bool BankAccount::purchase(double amount, const string& item) {
    if (amount <= 0) {
        cout << "Amount must be positive.\n";
        return false;
    }
    if (amount > balance) {
        cout << "Insufficient funds for \"" << item << "\".\n";
        logLine("[" + nowTimestamp() + "] Declined purchase: $" + money(amount) +
                " (" + item + ") | Balance: $" + money(balance));
        return false;
    }
    balance -= amount;
    logLine("[" + nowTimestamp() + "] Purchase: -$" + money(amount) +
            " (" + item + ") | Balance: $" + money(balance));
    cout << "Purchased \"" << item << "\" for $" << money(amount) << ".\n";
    return true;
}

void BankAccount::displayBalance() const {
    cout << "Current balance for " << ownerName << ": $" << fixed << setprecision(2) << balance << '\n';
}

void BankAccount::displayTransactions() const {
    ifstream fin(filename);
    if (!fin) {
        cout << "No transaction history found.\n";
        return;
    }
    cout << "\n--- Transaction History (" << filename << ") ---\n";
    string line;
    while (getline(fin, line)) cout << line << '\n';
    cout << "-----------------------------------------------\n";
}
