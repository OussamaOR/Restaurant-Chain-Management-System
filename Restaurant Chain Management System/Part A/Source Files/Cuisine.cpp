#include"../Header Files/Cuisine.h"
#include<iostream>
using namespace std;


//default constructor
Cuisine::Cuisine() : cuisineType(CuisineType::ALGERIAN), dailySales(), monthlyRating() {}

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

