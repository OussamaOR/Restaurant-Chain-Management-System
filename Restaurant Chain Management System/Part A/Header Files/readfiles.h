#include "RestaurantHashTable.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>
Date parseDate(const std::string &dateString);

// Function to parse SalesVec from a string
SalesVec parseSalesVec(const std::string &salesVecString);

// function to read data from costs.csv file
void readCSVAndInsertIntoCostsVec(const std::string &filename, CostsVec &costsVec,int restaurantIndex);

// function to read sata from cuisine.csv file
Cuisine readCuisineFromCSV(const std::string &filePath, int cuisineIndex);
// function to read data from the restaurant csv file
void readRestaurantCSV(const std::string &filename, RestaurantHashTable &restaurantTable);
