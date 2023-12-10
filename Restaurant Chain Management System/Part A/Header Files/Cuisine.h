#pragma once
#ifndef CUISINE_H
#define CUISINE_H
#include "RatingsBST.h"
#include "SalesBST.h"

// THE TYPE OF THE CUISINE
enum  CuisineType
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
    //default constructor
    Cuisine();
    //constructor with parameters
    Cuisine(CuisineType,const salesBST &,const ratingsBST & );
    //copy constructor
    Cuisine(const Cuisine &);
    //move constructor
    Cuisine(Cuisine &&);

    //getters
    CuisineType getCuisineType() const;
    const salesBST& getDailySales() const;
    const ratingsBST& getMonthlyRatings() const;

    //setters
    void setCuisineType(CuisineType );
    void setDailySales(const salesBST&);
    void setMonthlyRatings(const ratingsBST&);

    //operator opverloading
    Cuisine& operator=(const Cuisine& );

    //destructor 
    ~Cuisine();
};
#endif


