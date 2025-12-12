#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "NetflixTitle.h"

int main() {
    std::ifstream file("netflix_titles.csv");
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string line;
    std::getline(file, line); // Skip header line

    std::vector<NetflixTitle> titles;
    int count = 0;

    while (std::getline(file, line) && count < 10) { // Load only 10 entries
        std::stringstream ss(line);
        std::string id, type, title, director, cast, country, date_added, year_str, rating, duration;

        std::getline(ss, id, ',');
        std::getline(ss, type, ',');
        std::getline(ss, title, ',');
        std::getline(ss, director, ',');
        std::getline(ss, cast, ',');
        std::getline(ss, country, ',');
        std::getline(ss, date_added, ',');
        std::getline(ss, year_str, ',');
        std::getline(ss, rating, ',');
        std::getline(ss, duration, ',');

        int year = 0;
        try {
            year = std::stoi(year_str);
        } catch (...) {}

        NetflixTitle nt;
        nt.setData(id, type, title, director, cast, country, date_added, year, rating, duration);
        titles.push_back(nt);
        count++;
    }

    file.close();

    for (const auto& t : titles) {
        t.display();
    }

    return 0;
}
