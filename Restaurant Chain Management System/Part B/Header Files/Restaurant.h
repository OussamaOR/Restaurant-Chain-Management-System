#pragma once
#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "BinarySearchTree.h"
#include "Cuisine.h"
#include "CostsVec.h"

using namespace std;
// location
enum Location
{
    district,
    wilaya,
    country,
};
// restaurant type
enum RestaurantType
{
    OWNED,
    FRANCHISED,
};
//entry state 
enum EntryState { ACTIVE, DELETED, EMPTY };
// restaurant class
class Restaurant 
{
private:
     int restaurantId;
    int numOfEmployees;
    RestaurantType restaurantType;
    string restaurantName;
    string location[3];
    CostsVec dailyCosts;
    Cuisine cuisines[5];

    //the state is needed for the hashtable
    EntryState state;

public:
    // default constructor
    Restaurant();
    // constructor with parameters
    Restaurant(int, int, RestaurantType, const string &, string[], const CostsVec &, const Cuisine[]);
    // constructor to initialize the location array and cuisines array elements one by one
    Restaurant(int, int, RestaurantType, const string &, string, string, string, const CostsVec &,
               Cuisine, Cuisine, Cuisine, Cuisine, Cuisine);
    // copy constructor
    Restaurant(const Restaurant &);
    // Move constructor
    Restaurant(Restaurant &&);

    // Getters
     int getRestaurantId() const;
    string getRestaurantName() const;
    int getNumOfEmployees() const;
    RestaurantType getRestaurantType() const;
    string getDistrict() const;
    string getWilaya() const;
    string getCountry() const;
    const string *getFullLocation() const;
    const CostsVec & getDailyCosts() const;
    Cuisine getCuisine(CuisineType) const;
    const Cuisine *getAllCuisines() const;

    //setters
    void setRestaurantId( int id);
    void setRestaurantName(const string &name);
    void setNumOfEmployees(int employees);
    void setRestaurantType(RestaurantType type);
    void setDistrict(string );
    void setWilaya(string ) ;
    void setCountry(string ) ;
    void setFullLocation(string ,string ,string);
    void setFullLocation(const Location []);
    void setDailyCosts(const CostsVec &CostsVec);
    void setCuisine(Cuisine );
    void setAllCuisines(const Cuisine cuisineArray[5]);
    //functions to be used in the hashtable 
    void setState(EntryState );
    EntryState getState() const;

    // Destructor
    ~Restaurant();

    //functions needed to display the results

    //function to get the cuisine winner among the five cuisines in a restaurant
    std::pair<Cuisine,float> getCuisineWinner(int , int);

    //functions to return the average prize for each of the five cuisines
    float getAlgeriancuisineAveragePrize(int,int);
    float getSyriancuisineAveragePrize(int,int);
    float getChinesecuisineAveragePrize(int,int);
    float getIndiancuisineAveragePrize(int,int);
    float getEuropeancuisineAveragePrize(int,int);

    //functions to return the total sales 
    float totalSalesOnMonth(int ,int);
    float totalSalesOnPerid(Date,Date);

    //functions to return the tostal cost
    double totalCostOnmonth(int,int);
    double totalCostOnPeriod(Date,Date);
    double totalCostOnYear(int);
    double totalPublicityOnMonth(int ,int );
    double totalPublicityOnPeriod(Date,Date);

    /*function to return the ratio of the monthly sales to the amount of money
     spent during any given month on publicity*/
    double getAveragePublicityRatio(int,int);
    double getAveragePublicityRatio(Date,Date);

    //operator overloading
    Restaurant& operator=(const Restaurant& other);

    //print function 
    void print();
};

#endif

// function to return the sales of restaurant of a specific district/wiliya or the whole country (sales of cuisines where district == 'x') O(1)
// function to return the monthlySales/publicity cost for a given month for a given district/wilaya
