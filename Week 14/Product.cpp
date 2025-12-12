#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int id;
    string name;
    double price;

public:
    Product(int pid, string pname, double pprice) {
        id = pid;
        name = pname;
        price = pprice;
    }

    ~Product() {
        cout << "Destructor called for product: " << name << endl;
    }

    void printDetails() {
        cout << "Product ID: " << id << endl;
        cout << "Product Name: " << name << endl;
        cout << "Product Price: $" << price << endl;
    }
};

int main() {
    Product p1(101, "Laptop", 999.99);
    p1.printDetails();
    return 0;
}
