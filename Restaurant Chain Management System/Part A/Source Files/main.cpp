#include "../Header Files/RestaurantHashTable.h"
#include "../Header Files/readfiles.h"
int main()
{
    RestaurantHashTable Restaurants;
    readRestaurantCSV("../../Database/restaurant.csv", Restaurants);

    
    // country 
    Restaurants.displayAllRestaurantsInDistrict("abc");

}