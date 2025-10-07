#include "Expense.h"

void Expense::saveToFile(const vector<Expense>& expenses, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for saving.\n";
        return;
    }
    for (const auto& e : expenses) {
        file << e.getCategory() << "," << e.getDescription() << "," << e.getAmount() << "\n";
    }
    file.close();
}

vector<Expense> Expense::loadFromFile(const string& filename) {
    vector<Expense> expenses;
    ifstream file(filename);
    if (!file) {
        cerr << "No previous expenses found. Starting fresh.\n";
        return expenses;
    }

    string category, description;
    double amount;
    while (getline(file, category, ',') && getline(file, description, ',') && (file >> amount)) {
        file.ignore();
        expenses.emplace_back(category, description, amount);
    }

    file.close();
    return expenses;
}

void Expense::displayExpenses(const vector<Expense>& expenses) {
    if (expenses.empty()) {
        cout << "No expenses recorded yet.\n";
        return;
    }

    cout << left << setw(15) << "Category" << setw(25) << "Description" << "Amount ($)" << endl;
    cout << "--------------------------------------------------------\n";
    for (const auto& e : expenses) {
        cout << left << setw(15) << e.getCategory()
             << setw(25) << e.getDescription()
             << fixed << setprecision(2) << e.getAmount() << endl;
    }
}

double Expense::calculateTotal(const vector<Expense>& expenses) {
    double total = 0.0;
    for (const auto& e : expenses)
        total += e.getAmount();
    return total;
}
