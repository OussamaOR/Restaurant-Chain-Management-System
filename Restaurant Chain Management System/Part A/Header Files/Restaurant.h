#pragma once
#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <iostream>
#include "Cuisine.h"
#include "costsBST.h"
using namespace std;

// location
enum Location
{
    district,
    wilaya,
    country
};
// restaurant type
enum class RestaurantType
{
    OWNED,
    FRANCHISED
};
// restaurant class
class Restaurant 
{
private:
    int restaurantId;
    string restaurantName;
    int numOfEmployees;
    RestaurantType restaurantType;
    Location location[3];
    costsBST dailyCosts;
    Cuisine cuisines[5];

public:
    // default constructor
    Restaurant();
    // constructor
    Restaurant(int, int, RestaurantType, const string &, Location[], const costsBST &, const Cuisine[]);
    // constructor to initialize the location array and cuisines array elements one by one
    Restaurant(int, int, RestaurantType, const string &, Location, Location, Location, const costsBST &,
               Cuisine, Cuisine, Cuisine, Cuisine, Cuisine);
    // copy constructor
    Restaurant(const Restaurant &);

    // Getters
    int getRestaurantId() const;
    string getRestaurantName() const;
    int getNumOfEmployees() const;
    RestaurantType getRestaurantType() const;
    Location getDistrict() const;
    Location getWilaya() const;
    Location getCountry() const;
    const Location *getFullLocation() const;
    costsBST getDailyCosts() const;
    Cuisine getCuisine(CuisineType) const;
    const Cuisine *getAllCuisines() const;

    //setters
    void setRestaurantId(int id);
    void setRestaurantName(const string &name);
    void setNumOfEmployees(int employees);
    void setRestaurantType(RestaurantType type);
    void setDistrict(Location );
    void setWilaya(Location ) ;
    void setCountry(Location ) ;
    void setFullLocation(Location ,Location ,Location);
    void setFullLocation(const Location []);
    void setDailyCosts(const costsBST &costs);
    void setCuisine(Cuisine );
    void setAllCuisines(const Cuisine cuisineArray[5]);
};

#endif
// function to return the monthly costs (summing up all the dailycosts for a given month);  ==> month
// function to return the monthly sale (summing up all the monthly sales of each cuisine); ==> month O(log n)
// function to return sales during a year (summing up the total sales of each cuisine); ==> year
// function to return the sales of restaurant of a specific district/wiliya or the whole country (sales of cuisines where district == 'x') O(1)
// function to return the monthlySales/publicity cost for a given month
// function to return the monthlySales/publicity cost for a given month for a given district/wilaya
