#pragma once
#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <iostream>
#include "Cuisine.h"
#include "costsBST.h"
using namespace std;

//location
enum Location {
    district,
    wilaya,
    country
};
//restaurant type
enum class RestaurantType
{
    OWNED,
    FRANCHISED
};
//restaurant class 
class Restaurant  // hash table for the restaurant
{
private:
    int restaurantId;
    string restaurantName;
    int numOfEmployees;
    RestaurantType restaurantType;
    Location location[3];
    costsBST dailyCosts;
    Cuisine array[5]; 
};

#endif
//function to return the monthly costs (summing up all the dailycosts for a given month);  ==> month
//function to return the monthly sale (summing up all the monthly sales of each cuisine); ==> month O(log n)
//function to return sales during a year (summing up the total sales of each cuisine); ==> year
//function to return the sales of restaurant of a specific district/wiliya or the whole country (sales of cuisines where district == 'x') O(1)
//function to return the monthlySales/publicity cost for a given month 
//function to return the monthlySales/publicity cost for a given month for a given district/wilaya
