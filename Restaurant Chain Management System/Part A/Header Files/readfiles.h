#include "RestaurantHashTable.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>
Date parseDate(const std::string &);

// Function to parse SalesVec from a string
SalesVec parseSalesVec(const std::string &);

// function to read data from costs.csv file
void readCSVAndInsertIntoCostsVec(const std::string &, CostsVec &,int );

// function to read sata from cuisine.csv file
Cuisine readCuisineFromCSV(const std::string &, int );
// function to read data from the restaurant csv file
void readRestaurantCSV(const std::string &, RestaurantHashTable &);
