
#include <fstream>
#include "../Header Files/CostsVec.h"
#include <iomanip>

using namespace std;
CostsVec::CostsVec(){}
CostsVec::~CostsVec(){}
int CostsVec::getDailyCostIndex(int day,int month,int year){
    return (year - Costsvec[0].getDate().getYear())*365  + (month - Costsvec[0].getDate().getMonth())*30 +  day - Costsvec[0].getDate().getDay();
}
float CostsVec::max_cost(){
    float current = 0.f;
    for (int i = 0; i < Costsvec.size(); i++) {
        if (Costsvec[i].totalDailyCost() > current)
            current = Costsvec[i].totalDailyCost();
    }
    return current;
}

float CostsVec::min_cost() {
    float current = static_cast<float>(INT32_MAX);
    for (int i = 0; i < Costsvec.size(); i++) {
        if (Costsvec[i].totalDailyCost() < current)
            current = Costsvec[i].totalDailyCost();
    }
    return current;
}

double CostsVec::total_onmonth(int month, int year) {
    double total = 0.f;
    if(getDailyCostIndex(1,month,year) >= Costsvec.size()) return 0;
    // Use the getDailyCostIndex function to get the starting and ending indices for the month
    for (int i = getDailyCostIndex(1, month, year); i <= std::min(static_cast<int>(Costsvec.size()), getDailyCostIndex(30, month, year)); i++) {
        total += Costsvec[i].totalDailyCost();
    }
    return total;
}

double CostsVec::total_onyear(int year) {
    float total = 0.f;
    if(getDailyCostIndex(1,1,year) >= Costsvec.size()) return 0;
    // Use the getDailyCostIndex function to get the starting and ending indices for the year
    for (int i = getDailyCostIndex(1, 1, year); i <= std::min(static_cast<int>(Costsvec.size()), getDailyCostIndex(30, 12, year)); i++) {
        total += Costsvec[i].totalDailyCost();
    }
    return total;
}

// Member function to calculate the total cost in a specific period
double CostsVec::total_onperiod(Date start_date, Date end_date) {
    double total = 0.f;
    if(getDailyCostIndex(start_date.getDay(),start_date.getMonth(),start_date.getYear()) >= Costsvec.size()  ) return 0;
    // Use the getDailyCostIndex function to get the starting and ending indices for the period
    for (int i = getDailyCostIndex(start_date.getDay(), start_date.getMonth(), start_date.getYear()); i <= std::min(static_cast<int>(Costsvec.size()),getDailyCostIndex(end_date.getDay(), end_date.getMonth(), end_date.getYear())); i++) {
        total += Costsvec[i].totalDailyCost();
    }
    return total;
}
void CostsVec::insert_dailycost(dailyCost d_cost){
    Costsvec.push_back(d_cost);
}
CostsVec::CostsVec(std::vector<dailyCost> &&vec): Costsvec(std::move(vec)){}

double CostsVec::getPublicityCost_onperiod(Date start_date,Date end_date){
   double total = 0.f;
    if(getDailyCostIndex(start_date.getDay(),start_date.getMonth(),start_date.getYear()) >= Costsvec.size()  ) return 0;
    for (int i = getDailyCostIndex(start_date.getDay(), start_date.getMonth(), start_date.getYear()); i <= std::min(static_cast<int>(Costsvec.size()),getDailyCostIndex(end_date.getDay(), end_date.getMonth(), end_date.getYear())); i++) {
        total += Costsvec[i].getPublicityCost();
    }
    return total;
}
double CostsVec::getPublicityCost_onmonth(int month,int year){
    double total = 0.f;
    if(getDailyCostIndex(1,month,year) >= Costsvec.size()) return 0;
    for (int i = getDailyCostIndex(1, month, year); i <= std::min(static_cast<int>(Costsvec.size()), getDailyCostIndex(30, month, year)); i++) {
        total += Costsvec[i].getPublicityCost();
    }
    return total;
}
void program(){
    ifstream costs("../../Database/dailycosts.csv");
    if(!costs.is_open()){
        cout << "couldnt open dailycosts.csv file" << endl;
    }
    int date_data[3];
    float costs_data[8];
    char c;
    string first_line;
    costs >> first_line;
    CostsVec costs_vec;
    while(!costs.eof()){
        costs >> date_data[0] >> c >> date_data[1] >> c >> date_data[2] >> c;
        for(int i = 0;i<7;i++){
            costs >> costs_data[i] >> c; 
        }    
        costs >> costs_data[7];
        dailyCost daily_c(Date(date_data[0],date_data[1],date_data[2]),costs_data);
        costs_vec.insert_dailycost(daily_c);
    }

    
}
