
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
private:
    std::string name;
    int quantity;

public:
    Item();
    Item(const std::string& n, int q);

    void setName(const std::string& n);
    void setQuantity(int q);

    std::string getName() const;
    int getQuantity() const;
};

#endif
