#include<iostream>
using namespace std;
#include "../Header Files/Restaurant.h"
#include<utility>

// Default constructor
Restaurant::Restaurant()
    : restaurantId(0), numOfEmployees(0), restaurantType(RestaurantType::OWNED), state(EntryState::EMPTY){}

// Constructor with parameters
Restaurant::Restaurant(int id, int numEmployees, RestaurantType type, const string &name,
                       string loc[], const Costs &costs, const Cuisine cuisines[])
    : restaurantId(id), restaurantName(name), numOfEmployees(numEmployees),
      restaurantType(type), dailyCosts(costs), state(EntryState::EMPTY) {
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
      restaurantType(type), dailyCosts(costs), state(EntryState::EMPTY) {
    location[Location::district] = district;
    location[Location::wilaya] = wilaya;
    location[Location::country] = country;

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
      dailyCosts(other.dailyCosts),state(other.state) {
    for (int i = 0; i < 3; ++i) {
        location[i] = other.location[i];
    }
    for (int i = 0; i < 5; ++i) {
        cuisines[i] = other.cuisines[i];
    }
}
// Move constructor
Restaurant::Restaurant(Restaurant &&other)
    : restaurantId(other.restaurantId),
      restaurantName(other.restaurantName),
      numOfEmployees(other.numOfEmployees),
      restaurantType(other.restaurantType),
      dailyCosts(other.dailyCosts),
      state(other.state)
{
    // Moving location 
    for (int i = 0; i < 3; ++i)
    {
        location[i] = other.location[i];
    }
    //moving the cuisines array elements
    for (int i = 0; i < 5; ++i)
    {
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
    for (int i = 0; i < 5; i++) {
        if (cuisines[i].getCuisineType() == type) {
            return cuisines[i];
        }
    }
    return Cuisine();  // Returning default cuisine if not found
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
int main()
{
    string Locations[3]={"alger centre","alger","algerie"};
    Costs co1;
    salesBST s1;
    ratingsBST r1;
    Cuisine c1(CuisineType::ALGERIAN,s1,r1);
    Cuisine c2(CuisineType::SYRIAN,s1,r1);
    Cuisine c3(CuisineType::CHINESE,s1,r1);
    Cuisine c4(CuisineType::INDIAN,s1,r1);
    Cuisine c5(CuisineType::EUROPEAN,s1,r1);
    Cuisine cuisines[5]={c1,c2,c3,c4,c5};
    Restaurant resto1(1630100002,12,RestaurantType::OWNED,"r1",Locations,co1,cuisines);
    cout<<"restaurant id "<<resto1.getRestaurantId()<<endl;
}
