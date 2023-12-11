

#include "CostsVec.h"

int CostsVec::getDailyCostIndex(int day,int month,int year){
    return (year - Costsvec[0].getDate().getYear())*365  + (month - Costsvec[0].getDate().getMonth())*30 +  day - Costsvec[0].getDate().getDay();
}
float CostsVec::max_cost(){
    float current = 0.f;
    for (int i = 0; i < Costsvec.size(); i++) {
        if (Costsvec[i].totalDailyCost() > current)
            current = Costsvec[i].totalDailyCost();
    }
    return current;
}

float CostsVec::min_cost() {
    float current = static_cast<float>(INT32_MAX);
    for (int i = 0; i < Costsvec.size(); i++) {
        if (Costsvec[i].totalDailyCost() < current)
            current = Costsvec[i].totalDailyCost();
    }
    return current;
}

float CostsVec::total_onmonth(int year, int month) {
    float total = 0.f;
    // Use the getDailyCostIndex function to get the starting and ending indices for the month
    for (int i = getDailyCostIndex(1, month, year); i <= std::min(static_cast<int>(Costsvec.size()), getDailyCostIndex(30, month, year)); i++) {
        total += Costsvec[i].totalDailyCost();
    }
    return total;
}

float CostsVec::total_onyear(int year) {
    float total = 0.f;
    // Use the getDailyCostIndex function to get the starting and ending indices for the year
    for (int i = getDailyCostIndex(1, 1, year); i <= std::min(static_cast<int>(Costsvec.size()), getDailyCostIndex(30, 12, year)); i++) {
        total += Costsvec[i].totalDailyCost();
    }
    return total;
}

// Member function to calculate the total cost in a specific period
float CostsVec::total_onperiod(Date start_date, Date end_date) {
    float total = 0.f;
    // Use the getDailyCostIndex function to get the starting and ending indices for the period
    for (int i = getDailyCostIndex(start_date.getDay(), start_date.getMonth(), start_date.getYear()); i <= getDailyCostIndex(end_date.getDay(), end_date.getMonth(), end_date.getYear()); i++) {
        total += Costsvec[i].totalDailyCost();
    }
    return total;
}