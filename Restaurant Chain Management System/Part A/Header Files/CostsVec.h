#pragma once
#include <vector>
#include <iostream>
#include "DailyCost.h"
#include "Date.h"
class CostsVec {
    private:
    std::vector<dailyCost> Costsvec;         // First Date must be on the first element
    public:
    CostsVec();
    ~CostsVec();
    CostsVec(std::vector<dailyCost>&&);
    std::vector<dailyCost>& getDailyCosts(){return Costsvec;};
    int getDailyCostIndex(int,int,int);
    float max_cost();
    float min_cost();
    double total_onmonth(int,int);
    double total_onyear(int);
    double total_onperiod(Date,Date);
    void insert_dailycost(dailyCost);
    double getPublicityCost_onperiod(Date,Date);
    double getPublicityCost_onmonth(int,int);
    void print_infos();
    void printCostsOnMonth(int,int);

};
int getNumberOfDaysInMonth(int month, int year);