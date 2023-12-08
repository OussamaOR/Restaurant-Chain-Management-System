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

private:
    size_t findIndex(int restaurantId) const;
};

#endif

