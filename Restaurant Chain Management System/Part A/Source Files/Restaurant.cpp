#include "Part A/Header Files/Restaurant.h"
#include<iostream>
using namespace std;
#include "Restaurant.h"

#include "Restaurant.h"

// Default constructor
Restaurant::Restaurant()
    : restaurantId(0), numOfEmployees(0), restaurantType(RestaurantType::OWNED) {}

// Constructor with parameters
Restaurant::Restaurant(int id, int numEmployees, RestaurantType type, const string &name,
                       string loc[], const Costs &costs, const Cuisine cuisines[])
    : restaurantId(id), restaurantName(name), numOfEmployees(numEmployees),
      restaurantType(type), dailyCosts(costs) {
    for (int i = 0; i < 3; ++i) {
        location[i] = loc[i];
    }
    for (int i = 0; i < 5; ++i) {
        this->cuisines[i] = cuisines[i];
    }
}

// Constructor to initialize location and cuisines one by one
Restaurant::Restaurant(int id, int numEmployees, RestaurantType type, const string &name,
                       string district, string wilaya, string country,
                       const Costs &costs, Cuisine cuisine1, Cuisine cuisine2,
                       Cuisine cuisine3, Cuisine cuisine4, Cuisine cuisine5)
    : restaurantId(id), restaurantName(name), numOfEmployees(numEmployees),
      restaurantType(type), dailyCosts(costs) {
    location[Location::district] = district;
    location[Location::district] = wilaya;
    location[Location::district] = country;

    cuisines[0] = cuisine1;
    cuisines[1] = cuisine2;
    cuisines[2] = cuisine3;
    cuisines[3] = cuisine4;
    cuisines[4] = cuisine5;
}

// Copy constructor
Restaurant::Restaurant(const Restaurant &other)
    : restaurantId(other.restaurantId), restaurantName(other.restaurantName),
      numOfEmployees(other.numOfEmployees), restaurantType(other.restaurantType),
      dailyCosts(other.dailyCosts) {
    for (int i = 0; i < 3; ++i) {
        location[i] = other.location[i];
    }
    for (int i = 0; i < 5; ++i) {
        cuisines[i] = other.cuisines[i];
    }
}

// Getters
int Restaurant::getRestaurantId() const {
    return restaurantId;
}

string Restaurant::getRestaurantName() const {
    return restaurantName;
}

int Restaurant::getNumOfEmployees() const {
    return numOfEmployees;
}

RestaurantType Restaurant::getRestaurantType() const {
    return restaurantType;
}

string Restaurant::getDistrict() const {
    return location[district];
}

string Restaurant::getWilaya() const {
    return location[wilaya];
}

string Restaurant::getCountry() const {
    return location[country];
}

const string *Restaurant::getFullLocation() const {
    return location;
}

const Costs &Restaurant::getDailyCosts() const {
    return dailyCosts;
}

Cuisine Restaurant::getCuisine(CuisineType type) const {
   
       for(int i=0;i<5;i++)
       {
        if(cuisines[i].getCuisineType()==type)
        return cuisines[i];
       }
       return Cuisine(); //returing default cuisine if the cuisine was not found
}

const Cuisine *Restaurant::getAllCuisines() const {
    return cuisines;
}

// Setters
void Restaurant::setRestaurantId(int id) {
    restaurantId = id;
}

void Restaurant::setRestaurantName(const string &name) {
    restaurantName = name;
}

void Restaurant::setNumOfEmployees(int employees) {
    numOfEmployees = employees;
}

void Restaurant::setRestaurantType(RestaurantType type) {
    restaurantType = type;
}

void Restaurant::setDistrict(string dist) {
    location[district] = dist;
}

void Restaurant::setWilaya(string wil) {
    location[wilaya] = wil;
}

void Restaurant::setCountry(string country) {
    location[Location::country] = country;
}

void Restaurant::setFullLocation(string dist, string wil, string country) {
    location[district] = dist;
    location[wilaya] = wil;
    location[Location::country] = country;
}

void Restaurant::setFullLocation(const Location loc[]) {
    for (int i = 0; i < 3; ++i) {
        location[i] = loc[i];
    }
}

void Restaurant::setDailyCosts(const Costs &costs) {
    dailyCosts = costs;
}

void Restaurant::setCuisine(Cuisine cuisine) {
      if(cuisine.getCuisineType()==CuisineType::ALGERIAN)
      cuisines[0]=cuisine;
      if(cuisine.getCuisineType()==CuisineType::SYRIAN)
      cuisines[1]=cuisine;
      if(cuisine.getCuisineType()==CuisineType::CHINESE)
      cuisines[2]=cuisine;
      if(cuisine.getCuisineType()==CuisineType::INDIAN)
      cuisines[3]=cuisine;
      if(cuisine.getCuisineType()==CuisineType::EUROPEAN)
      cuisines[4]=cuisine;
}

void Restaurant::setAllCuisines(const Cuisine cuisineArray[5]) {
    for (int i = 0; i < 5; ++i) {
        cuisines[i] = cuisineArray[i];
    }
}

//functions to be used in the hashtable
void Restaurant::setState(EntryState newState) {
        state = newState;
}
EntryState Restaurant::getState() const {
        return state;
}
