#ifndef RESTAURANTHASHTABLE_H
#define RESTAURANTHASHTABLE_H
#include "../Header Files/Restaurant.h"
#include <vector>
#include <functional>
#include <stdexcept>

class RestaurantHashTable
{
private:
    std::vector<Restaurant> table;
    int currentSize;
    int maxSize;
    const double loadFactor;

    size_t hashFunction(int key) const;
    size_t hashFunction2(int key) const;
    size_t linearProbing(size_t index, int attempt) const;
    size_t doubleHashing(size_t index, int attempt) const;
    void rehash();

public:
    RestaurantHashTable();
    void insert(const Restaurant &restaurant);
    void remove(int restaurantId);
    bool search(int restaurantId, Restaurant &result) const;

    // getting the total sale on a given month for a given wilaya
    float totalSalesInWilaya(const std::string &, int, int);
    // getting the total sale on a given month for a given district
    float totalSalesInDistrict(const std::string &, int, int);
    // getting the total sales for the whole country
    float totalSalesInCountry(const std::string &, int, int);

    

    //function to display winner in district
    pair<Restaurant,float> getAlgerianCuisineWinnerInDistrict(const std::string &,int,int);
    pair<Restaurant,float> getSyrianCuisineWinnerInDistrict(const std::string &,int,int);
    pair<Restaurant,float> getChineseCuisineWinnerInDistrict(const std::string &,int,int);
    pair<Restaurant,float> getIndianCuisineWinnerInDistrict(const std::string &,int,int);
    pair<Restaurant,float> getEuropeanCuisineWinnerInDistrict(const std::string &,int,int);

    //function to display winner in wilaya
    pair<Restaurant,float> getAlgerianCuisineWinnerInWilaya(const std::string &,int,int);
    pair<Restaurant,float> getSyrianCuisineWinnerInWilaya(const std::string &,int,int);
    pair<Restaurant,float> getChineseCuisineWinnerInWilaya(const std::string &,int,int);
    pair<Restaurant,float> getIndianCuisineWinnerInWilaya(const std::string &,int,int);
    pair<Restaurant,float> getEuropeanCuisineWinnerInWilaya(const std::string &,int,int);

    //function to get winner in the coutry
    pair<Restaurant,float> getAlgerianCuisineWinnerInCountry(const std::string &,int,int);
    pair<Restaurant,float> getSyrianCuisineWinnerInCountry(const std::string &,int,int);
    pair<Restaurant,float> getChineseCuisineWinnerInCountry(const std::string &,int,int);
    pair<Restaurant,float> getIndianCuisineWinnerInCountry(const std::string &,int,int);
    pair<Restaurant,float> getEuropeanCuisineWinnerInCountry(const std::string &,int,int);

    //different print function
    void displayAllRestaurants();

    //report functions for a restaurant
    void displayRestaurant(int);
    void printRestaurantSales(int ,int ,int );
    void printMonthlySalesToPublicity(int,int,int);

    //report functions for a specific district
    void displayAllRestaurantsInDistrict(const std::string &);
    void printRestaurantSalesInDistrict(const std::string &,int,int);
    void printMonthlySalesToPublicityInDistrict(const std::string &,int,int);
    void printFiveCuisinesWinnersInDistrict(const std::string &,int,int);

    //report functions for a specific wilaya
    void displayAllRestaurantsInWilaya(const std::string &);
    void printRestaurantSalesInWilaya(const std::string &,int,int);
    void printMonthlySalesToPublicityInWilaya(const std::string &,int,int);
    void printFiveCuisinesWinnersInWilaya(const std::string &,int,int);

    //report functions for a country
    void displayAllRestaurantsInCountry(const std::string &);
    void printRestaurantSalesInCountry(const std::string &,int,int);
    void printMonthlySalesToPublicityInCountry(const std::string &,int,int);
    void printFiveCuisinesWinnersInCountry(const std::string &,int,int);
private:
    size_t findIndex(int restaurantId) const;
};

#endif
void displayWinnerInfo(pair<Restaurant,float>);