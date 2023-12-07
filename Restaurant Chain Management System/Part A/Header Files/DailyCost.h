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
    costType costType[8];
    // getters
    // setters
    // function to retun total daily cost (summing all the elements of the array)
};
