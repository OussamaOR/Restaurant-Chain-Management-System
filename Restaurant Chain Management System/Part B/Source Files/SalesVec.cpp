#include "../Header Files/SalesVec.h"
#include "../Header Files/CostsVec.h"

// Definitions for the DailySale struct

// Default constructor
DailySale::DailySale() : dailySaleAmount(0.0) {}

// Destructor
DailySale::~DailySale() {}

// Constructor with parameters
DailySale::DailySale(const Date &date, double dailySaleAmount)
    : date(date), dailySaleAmount(dailySaleAmount) {}

// Copy constructor
DailySale::DailySale(const DailySale &other)
    : date(other.date), dailySaleAmount(other.dailySaleAmount) {}

// Move constructor
DailySale::DailySale(DailySale &&other)
    : date(other.date), dailySaleAmount(other.dailySaleAmount)
{
     other.dailySaleAmount = 0.0;
}

// Definitions for the SalesVec class

// Constructor with rvalue reference for efficient move semantics
SalesVec::SalesVec(std::vector<DailySale>&& salesVector) : Salesvec(std::move(salesVector)) {}

// Default constructor
SalesVec::SalesVec(){}

// Destructor
SalesVec::~SalesVec(){}

// Method to insert a DailySale object into the SalesVec
void SalesVec::insert_dailysale(DailySale d){
    Salesvec.push_back(d);
}

// Method to get the index of a specific day in the SalesVec
int SalesVec::getDailySaleIndex(int day, int month, int year)
{
    return (year - Salesvec[0].getDate().getYear()) * 365 + (month - Salesvec[0].getDate().getMonth()) * 30 + day - Salesvec[0].getDate().getDay();
}

// Method to find the maximum sale amount in the SalesVec
float SalesVec::max_sale()
{
    float current = 0.f;
    for (int i = 0; i < Salesvec.size(); i++)
    {
        if (Salesvec[i].getDailySaleAmount() > current)
            current = Salesvec[i].getDailySaleAmount();
    }
    return current;
}

// Method to find the minimum sale amount in the SalesVec
float SalesVec::min_sale()
{
    float current = static_cast<float>(INT32_MAX);
    for (int i = 0; i < Salesvec.size(); i++)
    {
        if (Salesvec[i].getDailySaleAmount() < current)
            current = Salesvec[i].getDailySaleAmount();
    }
    return current;
}

// Method to calculate the total sales for a specific month and year
float SalesVec::total_onmonth(int month, int year)
{
    float total = 0.f;
    if (getDailySaleIndex(1, month, year) >= Salesvec.size())
        return 0;
    for (int i = getDailySaleIndex(1, month, year); i <= std::min(static_cast<int>(Salesvec.size()), getDailySaleIndex(30, month, year)); i++)
    {
        total += Salesvec[i].getDailySaleAmount();
    }
    return total;
}

// Method to calculate the total sales for a specific year
float SalesVec::total_onyear(int year)
{
    float total = 0.f;
    if (getDailySaleIndex(1, 1, year) >= Salesvec.size())
        return 0;
    for (int i = getDailySaleIndex(1, 1, year); i <= std::min(static_cast<int>(Salesvec.size()), getDailySaleIndex(30, 12, year)); i++)
    {
        total += Salesvec[i].getDailySaleAmount();
    }
    return total;
}

// Method to calculate the total sales for a specified period of time
float SalesVec::total_onperiod(Date start_date, Date end_date)
{
    float total = 0.f;
    if (getDailySaleIndex(start_date.getDay(), start_date.getMonth(), start_date.getYear()) >= Salesvec.size())
        return 0;
    for (int i = getDailySaleIndex(start_date.getDay(), start_date.getMonth(), start_date.getYear()); i <= std::min(static_cast<int>(Salesvec.size()), getDailySaleIndex(end_date.getDay(), end_date.getMonth(), end_date.getYear())); i++)
    {
        total += Salesvec[i].getDailySaleAmount();
    }
    return total;
}

// Copy assignment operator
SalesVec &SalesVec::operator=(const SalesVec &other)
{
    if (this != &other)
    {
        Salesvec.clear();
        Salesvec = other.Salesvec;
    }
    return *this;
}

// Method to print the DailySale objects in the SalesVec
void SalesVec::printSalesVec() {
    for (int i=0; i<Salesvec.size(); i++) {
        Salesvec[i].printSale();
    }
}

// Method to print the DailySale objects for a specific month and year
void SalesVec::printSalesOnMonth(int month, int year) {
    if (getDailySaleIndex(1, month, year) >= Salesvec.size())
        return;
    std::cout << "Daily Sales on " << month << "/" << year << ": " << std::endl;
    for (int i = getDailySaleIndex(1, month, year); i <= std::min(static_cast<int>(Salesvec.size()), getDailySaleIndex(getNumberOfDaysInMonth(month,year), month, year)); i++) {
       Salesvec[i].printSale();
    }
}
