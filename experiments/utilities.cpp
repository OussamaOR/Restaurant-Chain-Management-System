#include "utilities.h"
using namespace std;

int daysInMonth(int year, int month) {
    // array of days in each month (non-leap year)
    int daysInMonthNonLeap[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Check if it's a leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        // leap year, update days in february
        daysInMonthNonLeap[2] = 29;
    }

    // return the number of days in the specified month
    return daysInMonthNonLeap[month];
}

std::pair<int,int> extractMonthYear(const std::string& date) {
    std::istringstream iss(date);
    char delimiter;
    int month, year;
    iss >> month >> delimiter >> year;
    return std::make_pair(month, year);
}

std::string getRestauName( std::string restauid,  std::string restaurants_filepath) {
    std::string resto_name;
    std::ifstream input(restaurants_filepath);
    std::string first_line, line;

    std::getline(input, first_line);
    while (std::getline(input, line)) {
        std::istringstream iss(line);
        std::string current_token;
        while (std::getline(iss, current_token, ',')) {
            if (current_token == restauid) {
             
                std::getline(iss, resto_name, ',');
                return resto_name; 
            }
        }
    }

    return "";
}
/*
std::string CastDateToString(Date date) {
    std::string datee = "";
    datee.append(std::to_string(date.getDay()) + "/" + std::to_string(date.getMonth()) + "/" + std::to_string(date.getYear()));
    return datee;
}

std::vector<int> CastSalesvecToIntVec(SalesVec sales) {
    std::vector<int> vec(sales.getSales().size());
    for (int i = 0;i < vec.size();i++) {
        vec[i] = sales.getSales()[i].getDailySaleAmount();
    }
    return vec;
}
*/