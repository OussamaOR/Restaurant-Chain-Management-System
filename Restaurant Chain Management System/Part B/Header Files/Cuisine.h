#pragma once
#ifndef CUISINE_H
#define CUISINE_H
#include "ratingAVL.h"
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
    ratingAVL monthlyRating;
public:
    //default constructor
    Cuisine();
    //constructor with parameters
    Cuisine(CuisineType,const SalesVec &,const ratingAVL & );
    //copy constructor
    Cuisine(const Cuisine &);
    //move constructor
    Cuisine(Cuisine &&);

    //getters
    CuisineType getCuisineType() const;
    const SalesVec& getDailySales() const;
    const ratingAVL& getMonthlyRatings() const;

    //setters
    void setCuisineType(CuisineType );
    void setDailySales(const SalesVec&);
    void setMonthlyRatings(const ratingAVL&);

    //operator opverloading
    Cuisine& operator=(const Cuisine& );

    //destructor 
    ~Cuisine();

    //function to get the Average prize on a month
    float getAveragePrizeOnMonth(int ,int );

    //functions to get the total sale
    float getTotalSaleOnMonth(int , int);
    float getTotalSaleOnPeriod(Date , Date);
    float getTotalSaleOnYear(int);

    //functions to get the average ratings
    float getAverageRatingOnMonth(int , int);
    
    //print function 
    void printCuisine() ;
    void printCuisineSalesOnMonth(int,int);
};
#endif


