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

    //function to display all information about each restaurant
    void displayAllRestaurants();

private:
    size_t findIndex(int restaurantId) const;
};

#endif
