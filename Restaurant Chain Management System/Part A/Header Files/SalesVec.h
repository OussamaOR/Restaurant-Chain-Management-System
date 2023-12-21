#pragma once
#include <vector>
#include <iostream>

#include "Date.h"
struct DailySale
{
    Date date;
    double dailySaleAmount;
    
    public:
    // Default constructor
    DailySale();

    // Constructor with parameters
    DailySale(const Date &date, double dailySaleAmount);

    // Copy constructor
    DailySale(const DailySale &other);

    // Move constructor
    DailySale(DailySale &&other);

    // Destructor
    ~DailySale();

    // getters
    Date getDate() const { return date; }
    double getDailySaleAmount() const { return dailySaleAmount; }

    // setters
    void setDate(const Date &newDate) { date = newDate; }
    void setDailySaleAmount(double amount) { dailySaleAmount = amount; }
    //assignment operator 
    DailySale& operator=(const DailySale &other) {
        if (this != &other) {
            date = other.date;
            dailySaleAmount = other.dailySaleAmount;
        }
        return *this;
    }
    void printSale()
    {
        date.displayDate();
        std::cout<<"dailysale: "<<dailySaleAmount<<std::endl;
    }
};
class SalesVec {
    private:
    std::vector<DailySale> Salesvec;        // First Date must be on the first element
    public:
    SalesVec();
    SalesVec(std::vector<DailySale>&&);
    ~SalesVec();
    int getDailySaleIndex(int,int,int);
    float max_sale();
    float min_sale();
    float total_onmonth(int,int);
    float total_onyear(int);
    float total_onperiod(Date,Date);
    void insert_dailysale(DailySale);
    SalesVec& operator=(const SalesVec& other);
    void printSalesVec();
    void printSalesOnMonth(int,int);
    Date getDateFromIndex(int index);
};
