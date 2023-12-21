#include "../Header Files/RestaurantHashTable.h"
#include <cmath>
#include "readfiles.cpp"
// finding prime numbers functions
bool isPrime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int findNextPrime(int num)
{
    while (!isPrime(num))
    {
        num++;
    }
    return num;
}

int findPreviousPrime(int num)
{
    while (!isPrime(num))
    {
        num--;
    }
    return num;
}
size_t RestaurantHashTable::hashFunction(int key) const
{
    if (key <= 0)
    {
        cout << "Invalid key" << endl;
        return maxSize;
    }
    return key % table.size();
}

size_t RestaurantHashTable::hashFunction2(int key) const
{
    if (key <= 0)
    {
        cout << "Invalid key" << endl;
        return maxSize;
    }
    return findPreviousPrime(maxSize) - (key % findPreviousPrime(maxSize));
}

size_t RestaurantHashTable::linearProbing(size_t index, int attempt) const
{
    return (index + attempt) % maxSize;
}

size_t RestaurantHashTable::doubleHashing(size_t index, int attempt) const
{
    size_t hash1 = hashFunction(index);
    size_t hash2 = hashFunction2(index);
    return (hash1 + attempt * hash2) % maxSize;
}

void RestaurantHashTable::rehash()
{
    std::vector<Restaurant> oldTable = table;
    table.clear();
    currentSize = 0;
    maxSize *= 2;
    table.resize(maxSize);

    for (std::vector<Restaurant>::const_iterator it = oldTable.begin(); it != oldTable.end(); ++it)
    {
        const Restaurant &restaurant = *it;

        if (restaurant.getState() == ACTIVE)
        {
            insert(restaurant);
        }
    }
}

RestaurantHashTable::RestaurantHashTable() : currentSize(0), maxSize(2000), loadFactor(0.75)
{
    table.resize(maxSize);
}

void RestaurantHashTable::insert(const Restaurant &restaurant)
{
    if (currentSize >= maxSize * loadFactor)
    {
        rehash();
    }

    int key = restaurant.getRestaurantId();
    size_t index = hashFunction(key);
    size_t originalIndex = index;

    int attempt = 0;
    while (table[index].getState() == ACTIVE)
    {
        index = linearProbing(originalIndex, ++attempt);

        if (index == originalIndex)
        {
            throw std::overflow_error("Table is full");
        }
    }

    table[index] = restaurant;
    table[index].setState(ACTIVE);
    currentSize++;
}

void RestaurantHashTable::remove(int restaurantId)
{
    if (restaurantId <= 0)
    {
        cout << "Invalid restaurant ID" << endl;
        return ;
    }
    size_t index = findIndex(restaurantId);
    if (index != maxSize)
    {
        table[index].setState(DELETED);
        currentSize--;
    }
}

bool RestaurantHashTable::search(int restaurantId, Restaurant &result) const
{
    if (restaurantId <= 0)
    {
        cout << "Invalid restaurant ID" << endl;
        return false;
    }
    size_t index = findIndex(restaurantId);
    if (index != maxSize && table[index].getState() == ACTIVE)
    {
        result = table[index];
        return true;
    }
    cout << "Restaurant not found for ID: " << restaurantId << endl;
    return false;
}

size_t RestaurantHashTable::findIndex(int restaurantId) const
{
    if (restaurantId <= 0)
    {
        cout << "Invalid restaurant ID" << endl;
        return maxSize;
    }
    size_t index = hashFunction(restaurantId);
    size_t originalIndex = index;

    int attempt = 0;
    while (table[index].getState() != EMPTY)
    {
        if (table[index].getState() == ACTIVE && table[index].getRestaurantId() == restaurantId)
        {
            return index;
        }

        index = linearProbing(originalIndex, ++attempt);

        if (index == originalIndex)
        {
            break;
        }
    }

    cout << "Restaurant not found for ID: " << restaurantId << endl;
    return maxSize;
}

// getting the total sale on a given month for a given wilaya
float RestaurantHashTable::totalSalesInWilaya(const std::string &wilaya, int month, int year)
{
    float totalSales = 0.0;

    for (int i = 0; i < table.size(); i++)
    {
        if (table[i].getState() == ACTIVE && table[i].getWilaya() == wilaya)
        {
            totalSales += table[i].totalSalesOnMonth(month, year);
        }
    }

    return totalSales;
}

// getting the total sale on a given month for a given district
float RestaurantHashTable::RestaurantHashTable::totalSalesInDistrict(const std::string &district, int month, int year)
{
    float totalSales = 0.0;

    for (int i = 0; i < table.size(); i++)
    {
        if (table[i].getState() == ACTIVE && table[i].getDistrict() == district)
        {
            totalSales += table[i].totalSalesOnMonth(month, year);
        }
    }

    return totalSales;
}
// getting the total sales for the whole country
float RestaurantHashTable::totalSalesInCountry(const std::string &country, int month, int year)
{
    float totalSales = 0.0;

    for (int i = 0; i < table.size(); i++)
    {
        if (table[i].getState() == ACTIVE && table[i].getCountry() == country)
        {
            totalSales += table[i].totalSalesOnMonth(month, year);
        }
    }

    return totalSales;
}
//function to display all the restaurants in the hashtable
void RestaurantHashTable::displayAllRestaurants() {
    for (int i=0;i<table.size();i++) {
        if (table[i].getState() == ACTIVE) {
            table[i].print();
        }
    }
}
int main()
{
    RestaurantHashTable Restaurants;
    readRestaurantCSV("../../Database/restaurant.csv",Restaurants);

    Restaurants.displayAllRestaurants();
}

