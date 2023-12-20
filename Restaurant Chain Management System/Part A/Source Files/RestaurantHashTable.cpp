#include "../Header Files/RestaurantHashTable.h"
#include <cmath>
#include <fstream>
#include <sstream>
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
    return key % table.size();
}

size_t RestaurantHashTable::hashFunction2(int key) const
{
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
    size_t index = findIndex(restaurantId);
    if (index != maxSize)
    {
        table[index].setState(DELETED);
        currentSize--;
    }
}

bool RestaurantHashTable::search(int restaurantId, Restaurant &result) const
{
    size_t index = findIndex(restaurantId);
    if (index != maxSize && table[index].getState() == ACTIVE)
    {
        result = table[index];
        return true;
    }
    return false;
}

size_t RestaurantHashTable::findIndex(int restaurantId) const
{
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
            std::cout << "Restaurant ID: " << table[i].getRestaurantId() << std::endl;
            std::cout << "Name: " << table[i].getRestaurantName() << std::endl;
            std::cout << "Number of Employees: " << table[i].getNumOfEmployees() << std::endl;
            std::cout << "District: " << table[i].getDistrict() << std::endl;
            std::cout << "Wilaya: " << table[i].getWilaya() << std::endl;
            std::cout << "Country: " << table[i].getCountry() << std::endl;
            std::cout << "------------------------" << std::endl;
        }
    }
}
//function to read data from the restaurant csv file
void readRestaurantCSV(const std::string& filename, RestaurantHashTable& restaurantTable) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    std::string line;
     std::string first_line;
     std::getline(file,first_line);
    while (std::getline(file, line)) {
        try {
         
            std::istringstream iss(line);
            std::string token;
            std::vector<std::string> tokens;
           
            while (std::getline(iss, token, ',')) {
                tokens.push_back(token);
            }

            if (tokens.size() == 7) {
                int restaurantId = std::stoi(tokens[0]);
                std::string restaurantName = tokens[1];
                int numOfEmployees = std::stoi(tokens[2]);
                RestaurantType restaurantType;
                if (tokens[3] == "OWNED") {
                    restaurantType = OWNED;
                } else if (tokens[3] == "FRANCHISED") {
                    restaurantType = FRANCHISED;
                } else {
                    throw std::invalid_argument("Invalid restaurant type");
                }

                std::string district = tokens[4];
                std::string wilaya = tokens[5];
                std::string country = tokens[6];

                
                Restaurant restaurant(restaurantId, numOfEmployees, restaurantType, restaurantName,
                                      district, wilaya, country, CostsVec(), Cuisine(),Cuisine(),Cuisine(),Cuisine(),Cuisine());

                
                restaurantTable.insert(restaurant);
            } else {
                throw std::invalid_argument("Invalid number of columns in CSV");
            }
        } catch (const std::exception& e) {
            
            std::cerr << "Error while processing a line: " << e.what() << std::endl;
        }
    }

    file.close();
}

int main()
{
    RestaurantHashTable Restaurants;
    readRestaurantCSV("../../Database/restaurant.csv",Restaurants);

    Restaurants.displayAllRestaurants();
}