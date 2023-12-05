#include "../Header Files/Date.h"
#include <iostream>
Date::Date(){
    day = month = 1;
    year = 2000;
}
Date::Date(int d, int m , int y) : day(d), month(m), year(y) {};
int Date::getDay() const{return day;}
int Date::getMonth() const {return month;}
int Date::getYear()const{return year;}
void Date::setDay(int d){
    if(d > 0 && d <= 31) day = d;
    else std::cerr << "invalid day" << std::endl;
}
void Date::setMonth(int m){
    if(m > 0 && m < 13) month = m;
    else std::cerr << "invalid month" << std::endl;
}
void Date::setYear(int y){
    if(y > 0) year = y;
    else std::cerr << "invalid year" << std::endl;
}
void Date::displayDate() const {
    std::cout << "Date: " << day << "/" << month << "/" << year << std::endl;
}

