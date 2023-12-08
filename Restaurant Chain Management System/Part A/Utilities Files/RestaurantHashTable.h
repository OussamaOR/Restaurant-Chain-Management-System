#ifndef RESTAURANTHASHTABLE_H
#define RESTAURANTHASHTABLE_H
#include "Restaurant.h"

class RestaurantHashTable {
private:
    static const int TABLE_SIZE = 2000;
    Restaurant* table[TABLE_SIZE];

public:
    RestaurantHashTable();
    ~RestaurantHashTable();

    // Hash functions
    int hashFunction(int key);

    // Probing methods
    int linearProbe(int index, int attempt);
    int quadraticProbe(int index, int attempt);
    int doubleHash(int index, int attempt);

    // Hash table operations
    void insert(const Restaurant& restaurant);
    void remove(int restaurantId);
    Restaurant* search(int restaurantId);

    // Helper functions
    void rehash();
};
#endif