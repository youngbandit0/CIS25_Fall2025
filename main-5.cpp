#include "BankAccount.h"
#include <iostream>
using namespace std;

int main() {
    BankAccount account("Justine", 100.00);

    account.deposit(50.00);
    account.purchase(25.75, "Groceries");
    account.purchase(80.00, "Shoes");
    account.displayBalance();
    account.displayTransactions();

    return 0;
}
