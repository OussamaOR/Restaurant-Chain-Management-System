#pragma once
#include <iostream>
#include "CostsBST.h"
#include "Cuisine.h"


using namespace std;
enum RestaurantType
{
    OWNED,
    FRANCHISED
};

class Restaurant
{
private:
    int restaurantId;           
    string restaurantName;
    int numOfEmployees;
    RestaurantType restaurantType;
    CostsBST restaurantCosts;
    string Location[3];
    Cuisine array[5];
};