#pragma once
#ifndef CUISINE_H
#define CUISINE_H
#include "Restaurant-Chain-Management-System/Restaurant Chain Management System/Part A/Header Files/RatingsBST.h"
#include "Restaurant-Chain-Management-System/Restaurant Chain Management System/Part A/Header Files/SalesBST.h"
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
public:
    Cuisine();
    Cuisine(CuisineType,const salesBST &,const ratingsBST & );
    Cuisine(const Cuisine &);
    CuisineType getCuisineType() const;
    const salesBST& getDailySales() const;
    const ratingsBST& getMonthlyRatings() const;
    void setCuisineType(CuisineType );
    void setDailySales(const salesBST&);
    void setMonthlyRatings(const ratingsBST&);
    Cuisine& operator=(const Cuisine& );
};
#endif


