#include <vector>
#include <iostream>
#include "DailyCost.h"
#include "Date.h"
class CostsVec {
    private:
    std::vector<dailyCost> Costsvec;        // First Date must be on the first element
    public:
    CostsVec();
    ~CostsVec();
    int getDailyCostIndex(int,int,int);
    float max_cost();
    float min_cost();
    float total_onmonth(int,int);
    float total_onyear(int);
    float total_onperiod(Date,Date);
};