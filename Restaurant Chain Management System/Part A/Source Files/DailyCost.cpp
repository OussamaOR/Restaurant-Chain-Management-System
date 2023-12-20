#include "../Header Files/DailyCost.h"

void dailyCost::setDailyCost(float d_costs[8]){
    costs[rent] = d_costs[0];
    costs[employeePayments] = d_costs[1];
    costs[electricity] = d_costs[2];
    costs[gas] = d_costs[3];
    costs[vegetables] = d_costs[4];
    costs[meats] = d_costs[5];
    costs[otherIngredients] = d_costs[6];
    costs[publicitySpending] = d_costs[7];
    for(int i = 0;i<8;i++){
        total += costs[i];
    }
}
dailyCost::dailyCost(){
    Date date;
    for(int i = 0;i<8;i++){
        costs[i] = 0.0;
    }
    total = 0.f;
}
dailyCost::dailyCost(Date d_cost){
    date.setDay(d_cost.getDay());
    date.setMonth(d_cost.getMonth());
    date.setYear(d_cost.getYear());
    for(int i =0;i<8;i++){
        costs[i] = 0.f;
    }
    total = 0.f;
}
dailyCost::dailyCost(Date cost_date,float cost_arr[8]): date(cost_date) {
    setDailyCost(cost_arr);
    
}
float dailyCost::totalDailyCost(){
    float total = 0;
    for(int i = 0;i<8;i++){
        total += costs[i];
    }
    return total;
}
bool dailyCost::operator<(const dailyCost& other) const {
    return date < other.date;
}
bool dailyCost::operator>(const dailyCost& other) const {
    return date > other.date;
}
void dailyCost::setDate(const Date& d){
    date.setDay(d.getDay());
    date.setMonth(d.getMonth());
    date.setYear(d.getYear());
}
void dailyCost::setCosts(float cost_arr[8]){
    for(int i = 0;i<8;i++){
        costs[i] = cost_arr[i];
    }
}
float dailyCost::getTotal(){
    return total;
}
Date dailyCost::getDate(){
    return date;
}
float dailyCost::getPublicityCost(){return costs[publicitySpending];}


void dailyCost::print_infos(){
    std::cout << "Date : ";
    date.displayDate();
    std::cout << "Costs : " << std::endl << "Rent: " << costs[0] << std::endl << "employeePayments: " << costs[1] << std::endl << "Electricity: " << costs[2] << std::endl << "Gas: " << costs[3] << std::endl << "Vegetables: " << costs[4] << std::endl << "Meats: " << costs[5] << std::endl << "Other Ingredients: " << costs[6] << std::endl << "Publicity Spending: " << costs[7] << std::endl;
    std:: cout << "Total : " << total << std::endl;
    
}