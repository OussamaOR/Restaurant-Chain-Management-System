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
    // function of total dailysales
};
#endif

//function to return the monthlysales (summing up all the daily sales for a given month) ==> month o(logn)
//function to return the total sales of a cuisine (summing up all the daily sales) ==> year
//function to display the prize winners for the 5 cuisines on a given month 
