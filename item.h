// Item.h
#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include <algorithm>

struct Item {
    std::string name;
    int id;
};

void populateSortedByName(Item* items, std::size_t N);
Item** buildIdIndex(Item* items, std::size_t N);
Item* binarySearchById(Item** idIndex, std::size_t N, int targetId);

#endif
