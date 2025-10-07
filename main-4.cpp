#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Item {
private:
    string name;
    int quantity;
    string filePath; // each user gets their own file

public:
    // Constructor sets the user's file name
    Item(string username) {
        filePath = username + "_items.txt";
    }

    // Method to input item details
    void inputData() {
        cout << "Enter item name: ";
        getline(cin, name);
        cout << "Enter quantity: ";
        cin >> quantity;
        cin.ignore();
    }

    // Method to save item data to file
    void saveToFile() {
        ofstream file(filePath, ios::app);
        if (file) {
            file << name << "," << quantity << endl;
            file.close();
            cout << "✅ Item saved successfully to: " << filePath << endl;
        } else {
            perror("❌ Error opening file for writing");
        }
    }

    // Method to load and display data from file
    void loadFromFile() {
        ifstream file(filePath);
        string line;
        if (file) {
            cout << "\n📋 Items in " << filePath << ":\n";
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        } else {
            perror("❌ Error opening file for reading");
        }
    }
};

int main() {
    string username;
    cout << "Enter your name: ";
    getline(cin, username);

    Item userList(username); // create unique file for this user

    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Add new item\n";
        cout << "2. View your list\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                userList.inputData();
                userList.saveToFile();
                break;
            case 2:
                userList.loadFromFile();
                break;
            case 3:
                cout << "👋 Goodbye, " << username << "!\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
