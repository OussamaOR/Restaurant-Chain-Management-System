#include "../Header Files/SalesVec.h"
//struct DailySale
DailySale::DailySale() : dailySaleAmount(0.0) {}
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
SalesVec::SalesVec(std::vector<DailySale>&& salesVector) : Salesvec(std::move(salesVector)) {}
SalesVec::SalesVec(){}
SalesVec::~SalesVec(){}
void SalesVec::insert_dailysale(DailySale d){
    Salesvec.push_back(d);
}
int SalesVec::getDailySaleIndex(int day = 1, int month = 1, int year = 0)
{
    return (year - Salesvec[0].getDate().getYear()) * 365 + (month - Salesvec[0].getDate().getMonth()) * 30 + day - Salesvec[0].getDate().getDay();
}
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
float SalesVec::total_onperiod(Date start_date, Date end_date)
{
    float total = 0.f;
    if (getDailySaleIndex(getDailySaleIndex(start_date.getDay(), start_date.getMonth(), start_date.getYear())) >= Salesvec.size())
        return 0;
    for (int i = getDailySaleIndex(start_date.getDay(), start_date.getMonth(), start_date.getYear()); i <= std::min(static_cast<int>(Salesvec.size()), getDailySaleIndex(end_date.getDay(), end_date.getMonth(), end_date.getYear())); i++)
    {
        total += Salesvec[i].getDailySaleAmount();
    }
    return total;
}
SalesVec &SalesVec::operator=(const SalesVec &other)
{
    if (this != &other)
    {
        Salesvec.clear();
        Salesvec = other.Salesvec;
    }
    return *this;
}
void SalesVec::printSalesVec() {
    for (int i=0;i<Salesvec.size();i++) {
        Salesvec[i].printSale();
    }
}
Date SalesVec::getDateFromIndex(int index) {
    Date baseDate = Salesvec[0].getDate();
    
    int totalDays = index;
    
    int years = totalDays / 365;
    totalDays %= 365;

    int months = totalDays / 30;
    totalDays %= 30;

    int days = totalDays;

    Date resultDate;
    resultDate = {baseDate.getDay() + days, baseDate.getMonth() + months, baseDate.getYear() + years};

    return resultDate;
}


void SalesVec::printSalesOnMonth(int month, int year) {
    if (getDailySaleIndex(1, month, year) >= Salesvec.size())
        return;
    std::cout << "Daily Sales on " << month << "/" << year << ": " << std::endl;
    for (int i = getDailySaleIndex(1, month, year); i <= std::min(static_cast<int>(Salesvec.size()), getDailySaleIndex(30, month, year)); i++) {
       Salesvec[i].printSale();
    }
}
