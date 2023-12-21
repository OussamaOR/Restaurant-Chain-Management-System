#include "../Header Files/RestaurantHashTable.h"
#include <cmath>
#include "../Header Files/readfiles.h"
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
        return;
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
// function to display all the restaurants in the hashtable
void RestaurantHashTable::displayAllRestaurants()
{
    for (int i = 0; i < table.size(); i++)
    {
        if (table[i].getState() == ACTIVE)
        {
            table[i].print();
        }
    }
}
void RestaurantHashTable::displayRestaurant(int key)
{
    Restaurant r;
    if (this->search(key, r))
        r.print();
}

// function to get winner in the coutry
pair<Restaurant, float> RestaurantHashTable::getAlgerianCuisineWinner(const std::string &country, int month, int year)
{
    Restaurant winner;
    float maxAveragePrize = 0.0;

    for (int i = 0; i < table.size(); i++)
    {
        // Checking if the restaurant is in the specified coutry
        if (table[i].getCountry() == country)
        {
            // Geting the average prize for Algerian cuisine in the restaurant
            float averagePrize = table[i].getAlgeriancuisineAveragePrize(month, year);

            if (averagePrize > maxAveragePrize)
            {
                maxAveragePrize = averagePrize;
                winner = table[i];
            }
        }
    }
    return make_pair(winner, maxAveragePrize);
}
pair<Restaurant, float> RestaurantHashTable::getSyrianCuisineWinner(const std::string &country, int month, int year)
{
    Restaurant winner;
    float maxAveragePrize = 0.0;

    for (int i = 0; i < table.size(); i++)
    {
        // Checking if the restaurant is in the specified coutry
        if (table[i].getCountry() == country)
        {
            // Geting the average prize for Algerian cuisine in the restaurant
            float averagePrize = table[i].getSyriancuisineAveragePrize(month, year);

            if (averagePrize > maxAveragePrize)
            {
                maxAveragePrize = averagePrize;
                winner = table[i];
            }
        }
    }
    return make_pair(winner, maxAveragePrize);
}
pair<Restaurant, float> RestaurantHashTable::getChineseCuisineWinner(const std::string &country, int month, int year)
{
    Restaurant winner;
    float maxAveragePrize = 0.0;

    for (int i = 0; i < table.size(); i++)
    {
        // Checking if the restaurant is in the specified coutry
        if (table[i].getCountry() == country)
        {
            // Geting the average prize for Algerian cuisine in the restaurant
            float averagePrize = table[i].getChinesecuisineAveragePrize(month, year);

            if (averagePrize > maxAveragePrize)
            {
                maxAveragePrize = averagePrize;
                winner = table[i];
            }
        }
    }
    return make_pair(winner, maxAveragePrize);
}
pair<Restaurant, float> RestaurantHashTable::getIndianCuisineWinner(const std::string &country, int month, int year)
{
    Restaurant winner;
    float maxAveragePrize = 0.0;

    for (int i = 0; i < table.size(); i++)
    {
        // Checking if the restaurant is in the specified coutry
        if (table[i].getCountry() == country)
        {
            // Geting the average prize for Algerian cuisine in the restaurant
            float averagePrize = table[i].getIndiancuisineAveragePrize(month, year);

            if (averagePrize > maxAveragePrize)
            {
                maxAveragePrize = averagePrize;
                winner = table[i];
            }
        }
    }
    return make_pair(winner, maxAveragePrize);
}
pair<Restaurant, float> RestaurantHashTable::getEuropeanCuisineWinner(const std::string &country, int month, int year)
{
    Restaurant winner;
    float maxAveragePrize = 0.0;

    for (int i = 0; i < table.size(); i++)
    {
        // Checking if the restaurant is in the specified coutry
        if (table[i].getCountry() == country)
        {
            // Geting the average prize for Algerian cuisine in the restaurant
            float averagePrize = table[i].getEuropeancuisineAveragePrize(month, year);

            if (averagePrize > maxAveragePrize)
            {
                maxAveragePrize = averagePrize;
                winner = table[i];
            }
        }
    }
    return make_pair(winner, maxAveragePrize);
}

// funcions for reports and listings
void RestaurantHashTable::printRestaurantSales(int key, int month, int year)
{
    Restaurant r;
    if (this->search(key, r))
    {
        cout << "-- report of sales for each cuisine for " << month << "/" << year << endl;
        cout << "Algerian cuisines :\n";
        r.getCuisine(ALGERIAN).printCuisineSalesOnMonth(month,year);
        cout <<"total sale: "<< (r.getCuisine(ALGERIAN)).getTotalSaleOnMonth(month, year);
        cout << "Syrian cuisines :\n";
        r.getCuisine(SYRIAN).printCuisineSalesOnMonth(month,year);
        cout <<"total sale: "<< (r.getCuisine(SYRIAN)).getTotalSaleOnMonth(month, year);
        cout << "Chinese cuisines :\n";
        r.getCuisine(CHINESE).printCuisineSalesOnMonth(month,year);
        cout <<"total sale: "<< (r.getCuisine(CHINESE)).getTotalSaleOnMonth(month, year);
        cout << "Indian cuisines :\n";
        r.getCuisine(INDIAN).printCuisineSalesOnMonth(month,year);
        cout <<"total sale: "<< (r.getCuisine(INDIAN)).getTotalSaleOnMonth(month, year);
        cout << "European cuisines :\n";
        r.getCuisine(EUROPEAN).printCuisineSalesOnMonth(month,year);
        cout <<"total sale: "<< (r.getCuisine(EUROPEAN)).getTotalSaleOnMonth(month, year);
        cout << endl;
    }
}
void RestaurantHashTable::printFiveCuisinesWinners(int month,int year)
{
      cout<<"the winners for "<<month<<"/"<<year<<": \n";
      cout<<"Algerian cuisine: \n";
      cout<<"restaurant id : "<<this->getAlgerianCuisineWinner("Algeria",month,year).first.getRestaurantId()<<endl;
      cout<<"restaurant name : "<<this->getAlgerianCuisineWinner("Algeria",month,year).first.getRestaurantName()<<endl;
      cout<<"Syrian cuisine: \n";
      cout<<"restaurant id : "<<this->getSyrianCuisineWinner("Algeria",month,year).first.getRestaurantId()<<endl;
      cout<<"restaurant name : "<<this->getSyrianCuisineWinner("Algeria",month,year).first.getRestaurantName()<<endl;
      cout<<"Chines cuisine: \n";
      cout<<"restaurant id : "<<this->getChineseCuisineWinner("Algeria",month,year).first.getRestaurantId()<<endl;
      cout<<"restaurant name : "<<this->getChineseCuisineWinner("Algeria",month,year).first.getRestaurantName()<<endl;
      cout<<"Indian cuisine: \n";
      cout<<"restaurant id : "<<this->getIndianCuisineWinner("Algeria",month,year).first.getRestaurantId()<<endl;
      cout<<"restaurant name : "<<this->getIndianCuisineWinner("Algeria",month,year).first.getRestaurantName()<<endl;
      cout<<"European cuisine: \n";
      cout<<"restaurant id : "<<this->getEuropeanCuisineWinner("Algeria",month,year).first.getRestaurantId()<<endl;
      cout<<"restaurant name : "<<this->getEuropeanCuisineWinner("Algeria",month,year).first.getRestaurantName()<<endl;
}
int main()
{
    RestaurantHashTable Restaurants;
    readRestaurantCSV("../../Database/restaurant.csv", Restaurants);

    //Restaurants.printFiveCuisinesWinners(2,2023);
    Restaurants.printRestaurantSales(310610000,2,2023);
}