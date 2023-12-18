#include <vector>
#include <iostream>
#include "SalesBST.h"
#include "Date.h"
class SalesVec {
    private:
    std::vector<DailySale> Salesvec;        // First Date must be on the first element
    public:
    SalesVec();
    ~SalesVec();
    int getDailySaleIndex(int,int,int);
    float max_sale();
    float min_sale();
    float total_onmonth(int,int);
    float total_onyear(int);
    float total_onperiod(Date,Date);
    void insert_dailysale(DailySale);
    SalesVec& operator=(const SalesVec& other);
};