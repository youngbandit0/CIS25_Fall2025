
#include "item.h"

void populateSortedByName(Item* items, std::size_t N) {
    const int base = 1000;
    const int a = 37;
    const int b = 11;

    for (std::size_t i = 0; i < N; ++i) {
        items[i].name = "Name" + (i < 10 ? std::string("00") : (i < 100 ? "0" : "")) + std::to_string(i);
        int scrambled_index = static_cast<int>((a * i + b) % N);
        items[i].id = base + scrambled_index;
    }
}

Item** buildIdIndex(Item* items, std::size_t N) {
    Item** index = new Item*[N];
    for (std::size_t i = 0; i < N; ++i)
        index[i] = &items[i];
    std::sort(index, index + N, [](const Item* a, const Item* b) {
        return a->id < b->id;
    });
    return index;
}

Item* binarySearchById(Item** idIndex, std::size_t N, int targetId) {
    std::size_t lo = 0, hi = N;
    while (lo < hi) {
        std::size_t mid = lo + (hi - lo) / 2;
        int midId = idIndex[mid]->id;
        if (midId == targetId) return idIndex[mid];
        if (midId < targetId) lo = mid + 1;
        else hi = mid;
    }
    return nullptr;
}

int main() {
    const std::size_t N = 100;
    Item* items = new Item[N];
    populateSortedByName(items, N);

    Item** idIndex = buildIdIndex(items, N);

    std::cout << "Enter an ID to search for (1000?" << 1000 + N - 1 << "): ";
    int queryId;
    std::cin >> queryId;

    Item* found = binarySearchById(idIndex, N, queryId);

    if (found)
        std::cout << "Found item: " << found->name << " (ID: " << found->id << ")\n";
    else
        std::cout << "Item with ID " << queryId << " not found.\n";

    delete[] idIndex;
    delete[] items;
    return 0;
}
