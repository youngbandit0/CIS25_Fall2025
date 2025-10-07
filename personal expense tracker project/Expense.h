#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

class Expense {
private:
    string category;
    string description;
    double amount;

public:
    Expense() {}
    Expense(string c, string d, double a)
        : category(c), description(d), amount(a) {}

    string getCategory() const { return category; }
    string getDescription() const { return description; }
    double getAmount() const { return amount; }

    static void saveToFile(const vector<Expense>& expenses, const string& filename);
    static vector<Expense> loadFromFile(const string& filename);
    static void displayExpenses(const vector<Expense>& expenses);
    static double calculateTotal(const vector<Expense>& expenses);
};

#endif
