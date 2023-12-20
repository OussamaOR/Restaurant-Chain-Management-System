#pragma once
#include "Date.h"
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
    float total;
    public:
    dailyCost();
    void setDailyCost(float[8]);
    dailyCost(Date);
    dailyCost(Date,float[8]);
    float totalDailyCost();
    bool operator>(const dailyCost& ) const;
    bool operator<(const dailyCost& )const;
    
    void setDate(const Date&);
    void setCosts(float [8]);
    float getTotal();
    Date getDate();
    float getPublicityCost();
    // getters
    // setters
    // function to retun total daily cost (summing all the elements of the array)
};
