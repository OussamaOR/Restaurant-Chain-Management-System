#include"../Header Files/Cuisine.h"
#include<iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>
using namespace std;

//default constructor
Cuisine::Cuisine() : cuisineType(CuisineType::ALGERIAN), dailySales(), monthlyRating() {}
Cuisine::~Cuisine(){}
//constructor with parameters 
Cuisine::Cuisine(CuisineType type, const SalesVec & daily,const  ratingsBST & monthly)
    : cuisineType(type), dailySales(daily), monthlyRating(monthly) { }

//copy constructor
Cuisine::Cuisine(const Cuisine& other)
    : cuisineType(other.cuisineType), dailySales(other.dailySales), monthlyRating(other.monthlyRating) {
}
//move constructor
Cuisine::Cuisine(Cuisine &&other)
    : cuisineType(other.cuisineType), dailySales(other.dailySales), monthlyRating(other.monthlyRating)
{}
//getters
CuisineType Cuisine::getCuisineType() const {
    return cuisineType;
}

const SalesVec& Cuisine::getDailySales() const {
    return dailySales;
}

const ratingsBST& Cuisine::getMonthlyRatings() const {
    return monthlyRating;
}

//setters
void Cuisine::setCuisineType(CuisineType type) {
    cuisineType = type;
}

void Cuisine::setDailySales(const SalesVec& daily) {
    dailySales = daily;
}

void Cuisine::setMonthlyRatings(const ratingsBST& monthly) {
    monthlyRating = monthly;
}

//operator overloading 
// Overloading the assignment operator for Cuisine class
Cuisine& Cuisine::operator=(const Cuisine& other) {
    if (this != &other) { 
        cuisineType = other.cuisineType;
        dailySales = other.dailySales;
        monthlyRating = other.monthlyRating;
    }
    return *this;
}
float Cuisine::getAveragePrizeOnMonth(int month,int year)
{
    std::pair<int,int> date = make_pair(month,year);
    return this->dailySales.total_onmonth(month,year) + 
    ((this->monthlyRating).getAverageRatingByMonth(this->monthlyRating.getRoot(),date))/50;
}
float Cuisine::getTotalSaleOnMonth(int month , int year){
    return this->dailySales.total_onmonth(month,year);
}

//function to parse the date
Date parseDate(const std::string& dateString) {
    int day, month, year;
    sscanf(dateString.c_str(), "%d-%d-%d", &day, &month, &year);
    return Date(day, month, year);
}

// Function to parse SalesVec from a string
SalesVec parseSalesVec(const std::string& salesVecString) {
    SalesVec salesVec;
    std::regex pattern("\\((\\d{2}-\\d{2}-\\d{4}), (\\d+)\\)");
    auto salesBegin = std::sregex_iterator(salesVecString.begin(), salesVecString.end(), pattern);
    auto salesEnd = std::sregex_iterator();

    for (auto it = salesBegin; it != salesEnd; ++it) {
        std::smatch match = *it;
        Date date = parseDate(match[1]);
        double amount = std::stod(match[2]);
        DailySale dailySale(date, amount);
        salesVec.insert_dailysale(dailySale);
    }

    return salesVec;
}
std::vector<Cuisine> readCuisineFromCSV(const std::string& filePath) {
    std::vector<Cuisine> cuisineVector;

    // Open the CSV file
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return cuisineVector;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string cuisineTypeStr, dailySalesStr, monthlyRatingStr;

        // Read CuisineType
        if (!std::getline(iss, cuisineTypeStr, ',')) {
            std::cerr << "Error reading CuisineType" << std::endl;
            continue;
        }

        // Read DailySales
        if (!std::getline(iss, dailySalesStr, ',')) {
            std::cerr << "Error reading DailySales" << std::endl;
            continue;
        }

        // Read MonthlyRating
        if (!std::getline(iss, monthlyRatingStr)) {
            std::cerr << "Error reading MonthlyRating" << std::endl;
            continue;
        }

        // Convert CuisineType string to enum
        CuisineType cuisineType;
        if (cuisineTypeStr == "ALGERIAN") {
            cuisineType = ALGERIAN;
        } else if (cuisineTypeStr == "SYRIAN") {
            cuisineType = SYRIAN;
        } else if (cuisineTypeStr == "CHINESE") {
            cuisineType = CHINESE;
        } else if (cuisineTypeStr == "INDIAN") {
            cuisineType = INDIAN;
        } else if (cuisineTypeStr == "EUROPEAN") {
            cuisineType = EUROPEAN;
        } else {
            std::cerr << "Unknown CuisineType: " << cuisineTypeStr << std::endl;
            continue;
        }

        
        //parsing the RatingsBST 
        std::vector<std::pair<std::pair<int, int>, std::vector<int>>> ratingsData;
        std::smatch match;
        std::regex pattern("\\((\\d{2}-\\d{4}): \\[([\\d ]+)\\]\\)");
        while (std::regex_search(monthlyRatingStr, match, pattern)) {
            int month = std::stoi(match[1]);
            std::vector<int> ratings;
            std::istringstream ratingsStream(match[2]);
            int rating;
            while (ratingsStream >> rating) {
                ratings.push_back(rating);
            }
            ratingsData.push_back({{month, 2023}, ratings});
            monthlyRatingStr = match.suffix();
        }
        ratingsBST ratingsBST;
        for (const auto& data : ratingsData) {
            MonthlyRating monthlyRating(data.first.first, data.first.second, data.second);
            ratingsBST.insertRating(monthlyRating);
        }
        // Create Cuisine instance and add it to the vector
        Cuisine cuisine(cuisineType, parseSalesVec(dailySalesStr),ratingsBST);
        cuisineVector.push_back(cuisine);
    }

    // Close the file
    inputFile.close();

    return cuisineVector;
}
//function to print info 
void Cuisine::printCuisine()  {
        std::cout << "Cuisine Type: ";
        switch (cuisineType) {
            case ALGERIAN:
                std::cout << "Algerian";
                break;
            case SYRIAN:
                std::cout << "Syrian";
                break;
            case CHINESE:
                std::cout << "Chinese";
                break;
            case INDIAN:
                std::cout << "Indian";
                break;
            case EUROPEAN:
                std::cout << "European";
                break;
            default:
                std::cout << "Unknown";
        }
        std::cout << "\nDaily Sales:\n";
        cout << "\nMonthly Ratings:\n";
        monthlyRating.print(monthlyRating.getRoot());
}
int main()
{
    std::vector<Cuisine> cuisines = readCuisineFromCSV("cuisine.csv");
    for(int i=0;i<cuisines.size();i++)
    {
        cuisines[i].printCuisine();
    }
}

