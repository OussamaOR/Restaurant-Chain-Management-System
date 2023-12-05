#pragma once
#include "Date.h"
enum DailyPayments {
    DailyRent,
    EmployeesPayments,
    Electricity,
    Gas,
    Vegetables,
    Meats,
    OtherIngredients,
    PublicitySpending
};

class DailyCost
{
    Date date;
    double costs[8];
};