
#include "Item.h"

Item::Item() : name(""), quantity(0) {}

Item::Item(const std::string& n, int q) : name(n), quantity(q) {}

void Item::setName(const std::string& n) {
    name = n;
}

void Item::setQuantity(int q) {
    quantity = q;
}

std::string Item::getName() const {
    return name;
}

int Item::getQuantity() const {
    return quantity;
}
