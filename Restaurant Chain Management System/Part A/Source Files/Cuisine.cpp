#include "../Header Files/Cuisine.h"
#include <iostream>
#include <vector>

using namespace std;

// default constructor
Cuisine::Cuisine() : cuisineType(CuisineType::ALGERIAN), dailySales(), monthlyRating() {}
Cuisine::~Cuisine() {}
// constructor with parameters
Cuisine::Cuisine(CuisineType type, const SalesVec &daily, const ratingsBST &monthly)
    : cuisineType(type), dailySales(daily), monthlyRating(monthly) {}

// copy constructor
Cuisine::Cuisine(const Cuisine &other)
    : cuisineType(other.cuisineType), dailySales(other.dailySales), monthlyRating(other.monthlyRating)
{
}
// move constructor
Cuisine::Cuisine(Cuisine &&other)
    : cuisineType(other.cuisineType), dailySales(other.dailySales), monthlyRating(other.monthlyRating)
{
}
// getters
CuisineType Cuisine::getCuisineType() const
{
    return cuisineType;
}

const SalesVec &Cuisine::getDailySales() const
{
    return dailySales;
}

const ratingsBST &Cuisine::getMonthlyRatings() const
{
    return monthlyRating;
}

// setters
void Cuisine::setCuisineType(CuisineType type)
{
    cuisineType = type;
}

void Cuisine::setDailySales(const SalesVec &daily)
{
    dailySales = daily;
}

void Cuisine::setMonthlyRatings(const ratingsBST &monthly)
{
    monthlyRating = monthly;
}

// operator overloading
//  Overloading the assignment operator for Cuisine class
Cuisine &Cuisine::operator=(const Cuisine &other)
{
    if (this != &other)
    {
        cuisineType = other.cuisineType;
        dailySales = other.dailySales;
        monthlyRating = other.monthlyRating;
    }
    return *this;
}

// function to get the average prize
float Cuisine::getAveragePrizeOnMonth(int month, int year)
{
    std::pair<int, int> date = make_pair(month, year);
    return this->dailySales.total_onmonth(month, year) +
           ((this->monthlyRating).getAverageRatingByMonth(this->monthlyRating.getRoot(), date)) / 50;
}

// functions to get the total sale
float Cuisine::getTotalSaleOnMonth(int month, int year)
{
    return this->dailySales.total_onmonth(month, year);
}
float Cuisine::getTotalSaleOnPeriod(Date d1, Date d2)
{
    return dailySales.total_onperiod(d1, d2);
}
float Cuisine::getTotalSaleOnYear(int year)
{
    return dailySales.total_onyear(year);
}

// functions to get the average Rating
float Cuisine::getAverageRatingOnMonth(int month, int year)
{
    return monthlyRating.getAverageRatingByMonth(monthlyRating.getRoot(), month, year);
}
// function to print info
void Cuisine::printCuisine()
{
    std::cout << "Cuisine Type: ";
    switch (cuisineType)
    {
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
    dailySales.printSalesVec();
    cout << "\nMonthly Ratings:\n";
    monthlyRating.print(monthlyRating.getRoot());
}
void Cuisine::printCuisineSalesOnMonth(int month, int year)
{
    dailySales.printSalesOnMonth(month, year);
    cout << endl;
}
