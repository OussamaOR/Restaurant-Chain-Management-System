#pragma once
#include <iostream>
#include "SalesBST.h"
#include "RatingsBST.h"

enum CuisineType
{
    ALGERIAN = 1,
    SYRIAN,
    CHINESE,
    INDIAN,
    EUROPEAN
};

class Cuisine
{
private:
    CuisineType cuisineType;
    SalesBST dailySales;
    RatingsBST monthlyRating;
};