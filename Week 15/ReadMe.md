
Netflix Titles C++ Project

Description:
This project demonstrates reading a CSV file containing Netflix titles (movies and TV shows)
into C++ objects and displaying the data. The dataset includes fields like title, type, director,
cast, country, release year, rating, and duration.

Files:

1. netflix_titles.csv
   - A CSV file with Netflix titles.
   - Example structure:
     show_id,type,title,director,cast,country,date_added,release_year,rating,duration
     s1,Movie,Example Movie 1,Director A,Actor A1|Actor A2,USA,January 1, 2020,2020,PG,90 min
     s2,TV Show,Example Show 1,Director B,Actor B1|Actor B2,UK,February 15, 2019,2019,TV-14,3 Seasons

2. NetflixTitle.h
   - Defines the NetflixTitle class with attributes for each CSV column.
   - Includes a display() method to print details.

3. main.cpp
   - Reads the CSV file line by line.
   - Creates NetflixTitle objects.
   - Stores them in a vector.
   - Prints each entry.

Compilation and Running:

1. Compile the program:
   g++ main.cpp -o netflix_program

2. Run the program:
   ./netflix_program

Features:
- Reads CSV files with headers.
- Supports both Movies and TV Shows.
- Prints all details in a human-readable format.
- Handles multiple cast members separated by '|'.

Notes:
- Make sure netflix_titles.csv is in the same directory as main.cpp.
- For large datasets, the program dynamically stores entries in a vector.
- The CSV parser is simple; it may need enhancement to handle commas inside quoted fields.

Example Output:
--------------------------------
Title: Dick Johnson Is Dead
Type: Movie
Director: Kirsten Johnson
Cast: 
Country: United States
Date Added: September 25, 2021
Release Year: 2020
Rating: PG-13
Duration: 90 min
--------------------------------
*/
