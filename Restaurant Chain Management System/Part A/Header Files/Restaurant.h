#pragma once
#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "BinarySearchTree.h"
#include "Cuisine.h"
#include "costsBST.h"

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
    string restaurantName;
    int numOfEmployees;
    RestaurantType restaurantType;
    string location[3];
    Costs dailyCosts;
    Cuisine cuisines[5];

    //the state is needed for the hashtable
    EntryState state;

public:
    // default constructor
    Restaurant();
    // constructor with parameters
    Restaurant(int, int, RestaurantType, const string &, string[], const Costs &, const Cuisine[]);
    // constructor to initialize the location array and cuisines array elements one by one
    Restaurant(int, int, RestaurantType, const string &, string, string, string, const Costs &,
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
    const Costs & getDailyCosts() const;
    Cuisine getCuisine(CuisineType) const;
    const Cuisine *getAllCuisines() const;

    //setters
    void setRestaurantId(int id);
    void setRestaurantName(const string &name);
    void setNumOfEmployees(int employees);
    void setRestaurantType(RestaurantType type);
    void setDistrict(string );
    void setWilaya(string ) ;
    void setCountry(string ) ;
    void setFullLocation(string ,string ,string);
    void setFullLocation(const Location []);
    void setDailyCosts(const Costs &costs);
    void setCuisine(Cuisine );
    void setAllCuisines(const Cuisine cuisineArray[5]);
    //functions to be used in the hashtable 
    void setState(EntryState );
    EntryState getState() const;

    // Destructor
    ~Restaurant();
};

#endif
// function to return the monthly costs (summing up all the dailycosts for a given month);  ==> month
// function to return the monthly sale (summing up all the monthly sales of each cuisine); ==> month O(log n)
// function to return sales during a year (summing up the total sales of each cuisine); ==> year
// function to return the sales of restaurant of a specific district/wiliya or the whole country (sales of cuisines where district == 'x') O(1)
// function to return the monthlySales/publicity cost for a given month
// function to return the monthlySales/publicity cost for a given month for a given district/wilaya
