#pragma once
#include "date.h"
enum costType
{
    rent,
    employeePayments,
    electricity,
    gas,
    vegetables,
    meats,
    otherIngredients,
    publicitySpending
};
class dailyCost
{
    Date date;
    float costs[8];
    public:
     dailyCost();
    dailyCost(Date,float[8]);
    float totalDailyCost();
    // getters
    // setters
    // function to retun total daily cost (summing all the elements of the array)
};
