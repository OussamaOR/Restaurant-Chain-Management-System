#include "..Utilities Files/RestaurantHashTable.h"
#include <cmath>

//finding prime numbers functions
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int findNextPrime(int num) {
    while (!isPrime(num)) {
        num++;
    }
    return num;
}

int findPreviousPrime(int num) {
    while (!isPrime(num)) {
        num--;
    }
    return num;
}

//default constructor
RestaurantHashTable::RestaurantHashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table[i] = nullptr;
    }
}

//destructor
RestaurantHashTable::~RestaurantHashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        delete table[i];
    }
}

//hash function
int RestaurantHashTable::hashFunction(int key) {
    return key % TABLE_SIZE;
}

//quadratic probing
int RestaurantHashTable::quadraticProbe(int index, int attempt) {
    return (index + attempt * attempt) % TABLE_SIZE;
}

//hash table operations (insertion)
void RestaurantHashTable::insert(const Restaurant& restaurant) {
    int key = restaurant.getRestaurantId();
    int index = hashFunction(key);

    int attempt = 0;
    while (table[index] != nullptr && table[index]->getState() != EntryState::EMPTY) {
        if (table[index]->getRestaurantId() == key && table[index]->getState() != EntryState::DELETED) {
            // Restaurant with the same key already exists (duplicate), handle accordingly
            return;
        }

        attempt++;
        index = quadraticProbe(index, attempt);
    }

    if (table[index] == nullptr) {
        table[index] = new Restaurant(restaurant);
    } else {
        // Reuse the existing entry
        *table[index] = restaurant;
    }

    table[index]->setState(EntryState::ACTIVE);
}

//hash table operations (deletion)
void RestaurantHashTable::remove(int restaurantId) {
    int index = hashFunction(restaurantId);

    int attempt = 0;
    while (table[index] != nullptr) {
        if (table[index]->getRestaurantId() == restaurantId && table[index]->getState() != EntryState::DELETED) {
            table[index]->setState(EntryState::DELETED);
            return;
        }

        attempt++;
        index = quadraticProbe(index, attempt);
    }
}

//hash table operations (searching)
Restaurant* RestaurantHashTable::search(int restaurantId) {
    int index = hashFunction(restaurantId);

    int attempt = 0;
    while (table[index] != nullptr) {
        if (table[index]->getRestaurantId() == restaurantId && table[index]->getState() != EntryState::DELETED) {
            return table[index];
        }

        attempt++;
        index = quadraticProbe(index, attempt);
    }

    return nullptr;
}

//rehash function
void RestaurantHashTable::rehash() {
    int newSize = findNextPrime(TABLE_SIZE * 2);
    
}

