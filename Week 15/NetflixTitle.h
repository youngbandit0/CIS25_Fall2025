#ifndef NETFLIX_TITLE_H
#define NETFLIX_TITLE_H

#include <string>
#include <iostream>

class NetflixTitle {
private:
    std::string show_id;
    std::string type;
    std::string title;
    std::string director;
    std::string cast;
    std::string country;
    std::string date_added;
    int release_year;
    std::string rating;
    std::string duration;

public:
    NetflixTitle() = default;

    void setData(const std::string& id, const std::string& t, const std::string& ti,
                 const std::string& dir, const std::string& c, const std::string& cn,
                 const std::string& date, int year, const std::string& r, const std::string& dur) {
        show_id = id;
        type = t;
        title = ti;
        director = dir;
        cast = c;
        country = cn;
        date_added = date;
        release_year = year;
        rating = r;
        duration = dur;
    }

    void display() const {
        std::cout << "ID: " << show_id << "\nTitle: " << title << "\nType: " << type
                  << "\nDirector: " << director << "\nCast: " << cast
                  << "\nCountry: " << country << "\nDate Added: " << date_added
                  << "\nYear: " << release_year << "\nRating: " << rating
                  << "\nDuration: " << duration << "\n--------------------------\n";
    }
};

#endif
