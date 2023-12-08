#include"Cuisine.h"
#include<iostream>
using namespace std;
#include "Cuisine.h"

//default constructor
Cuisine::Cuisine() : cuisineType(CuisineType::ALGERIAN), dailySales(), monthlyRating() {}

//constructor
Cuisine::Cuisine(CuisineType type, const salesBST & daily,const  ratingsBST & monthly)
    : cuisineType(type), dailySales(daily), monthlyRating(monthly) { }

//copy constructor
Cuisine::Cuisine(const Cuisine& other)
    : cuisineType(other.cuisineType), dailySales(other.dailySales), monthlyRating(other.monthlyRating) {
}

//getters
CuisineType Cuisine::getCuisineType() const {
    return cuisineType;
}

const salesBST& Cuisine::getDailySales() const {
    return dailySales;
}

const ratingsBST& Cuisine::getMonthlyRatings() const {
    return monthlyRating;
}

//setters
void Cuisine::setCuisineType(CuisineType type) {
    cuisineType = type;
}

void Cuisine::setDailySales(const salesBST& daily) {
    dailySales = daily;
}

void Cuisine::setMonthlyRatings(const ratingsBST& monthly) {
    monthlyRating = monthly;
}

//operator overloading 
// Overloading the assignment operator for Cuisine class
Cuisine& Cuisine::operator=(const Cuisine& other) {
    if (this != &other) {  // Avoid self-assignment
        cuisineType = other.cuisineType;
        dailySales = other.dailySales;
        monthlyRating = other.monthlyRating;
    }
    return *this;
}

