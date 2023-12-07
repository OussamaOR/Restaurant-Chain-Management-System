#pragma once
#ifndef CUISINE_H
#define CUISINE_H
#include "ratingsBST.h"
#include "salesBST.h"


// THE TYPE OF THE CUISINE
enum class CuisineType
{
    ALGERIAN,
    SYRIAN,
    CHINESE,
    INDIAN,
    EUROPEAN
};


//THE CUISINE CLASS
class Cuisine
{
private:
    CuisineType cuisineType;
    salesBST dailySales;
    ratingsBST monthlyRating;
};
#endif


