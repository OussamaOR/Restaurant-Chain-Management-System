#pragma once
#ifndef CUISINE_H
#define CUISINE_H
#include "RatingsBST.h"
#include "SalesVec.h"

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
    SalesVec dailySales;
    ratingsBST monthlyRating;
public:
    //default constructor
    Cuisine();
    //constructor with parameters
    Cuisine(CuisineType,const SalesVec &,const ratingsBST & );
    //copy constructor
    Cuisine(const Cuisine &);
    //move constructor
    Cuisine(Cuisine &&);

    //getters
    CuisineType getCuisineType() const;
    const SalesVec& getDailySales() const;
    const ratingsBST& getMonthlyRatings() const;

    //setters
    void setCuisineType(CuisineType );
    void setDailySales(const SalesVec&);
    void setMonthlyRatings(const ratingsBST&);

    //operator opverloading
    Cuisine& operator=(const Cuisine& );

    //destructor 
    ~Cuisine();

    //functions to display the needed results
    float getAveragePrizeOnMonth(int ,int );
};
#endif


