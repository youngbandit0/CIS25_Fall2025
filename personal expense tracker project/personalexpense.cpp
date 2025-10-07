#include <iostream>
#include <vector>
#include <iomanip>
#include "Expense.h"

using namespace std;

// ANSI color codes
const string RESET = "\033[0m";
const string CYAN = "\033[36m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string RED = "\033[31m";
const string BOLD = "\033[1m";

// Helper to draw a divider line
void line() {
    cout << CYAN << "---------------------------------------------" << RESET << endl;
}

// Menu display
void showMenu() {
    line();
    cout << BOLD << CYAN << "       💰 PERSONAL EXPENSE TRACKER 💰" << RESET << endl;
    line();
    cout << YELLOW << "1." << RESET << " ➕ Add Expense\n";
    cout << YELLOW << "2." << RESET << " 📋 View Expenses\n";
    cout << YELLOW << "3." << RESET << " 💵 View Total\n";
    cout << YELLOW << "4." << RESET << " 💾 Save & Exit\n";
    line();
    cout << "Select an option (1–4): ";
}

int main() {
    vector<Expense> expenses;
    string filename = "expenses.txt";
    expenses = Expense::loadFromFile(filename);

    int choice;
    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string category, description;
            double amount;

            cout << GREEN << "\nEnter category (e.g., Food, Rent, etc.): " << RESET;
            getline(cin, category);
            cout << GREEN << "Enter description: " << RESET;
            getline(cin, description);
            cout << GREEN << "Enter amount: $" << RESET;
            cin >> amount;
            cin.ignore();

            expenses.emplace_back(category, description, amount);
            cout << GREEN << "\n✅ Expense added successfully!\n" << RESET;

        } else if (choice == 2) {
            line();
            cout << BOLD << CYAN << "📋 Current Expenses:" << RESET << endl;
            line();
            Expense::displayExpenses(expenses);
        } 
        else if (choice == 3) {
            double total = Expense::calculateTotal(expenses);
            cout << BOLD << GREEN << "\n💵 Total Spending: $" 
                 << fixed << setprecision(2) << total << RESET << endl;
        } 
        else if (choice == 4) {
            Expense::saveToFile(expenses, filename);
            cout << BOLD << GREEN << "\n💾 Expenses saved. Goodbye!\n" << RESET;
        } 
        else {
            cout << RED << "\n❌ Invalid choice. Please try again.\n" << RESET;
        }

    } while (choice != 4);

    return 0;
}
