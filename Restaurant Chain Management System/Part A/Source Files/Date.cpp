#include "../Header Files/Date.h"
#include <iostream>
#include <stdexcept>

// Default constructor sets initial date to January 1, 2000
Date::Date() : day(1), month(1), year(2000)
{
    validateDate(); // Validate the initial date
}

// Parameterized constructor to set date during object creation
Date::Date(int d, int m, int y) : day(d), month(m), year(y)
{
    validateDate(); // Validate the provided date
}

// Getter methods for day, month, and year
int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}

// Setter methods with validation for day, month, and year
void Date::setDay(int d)
{
    if (isValidDay(d, month, year))
    {
        day = d;
    }
    else
    {
        throw std::invalid_argument("Invalid day");
    }
}

void Date::setMonth(int m)
{
    if (isValidMonth(m))
    {
        month = m;
        setDay(day); // Adjust day if necessary after changing the month
    }
    else
    {
        throw std::invalid_argument("Invalid month");
    }
}

void Date::setYear(int y)
{
    if (isValidYear(y))
    {
        year = y;
        setDay(day); // Adjust day if necessary after changing the year
    }
    else
    {
        throw std::invalid_argument("Invalid year");
    }
}

// Display the date in the specified format
void Date::displayDate() const
{
    std::cout << "Date: " << day << "/" << month << "/" << year << std::endl;
}

// Validate the entire date (day, month, and year)
void Date::validateDate()
{
    if (!isValidDay(day, month, year) || !isValidMonth(month) || !isValidYear(year))
    {
        throw std::invalid_argument("Invalid date");
    }
}

// Helper method to check if a day is valid for a given month and year
bool Date::isValidDay(int d, int m, int y) const
{
    int daysInThisMonth = daysInMonth(m, y);
    return d > 0 && d <= daysInThisMonth;
}

// Helper method to check if a month is valid
bool Date::isValidMonth(int m) const
{
    return m > 0 && m <= 12;
}

// Helper method to check if a year is valid
bool Date::isValidYear(int y) const
{
    return y > 0;
}

// Helper method to get the number of days in a given month
int Date::daysInMonth(int m, int y) const
{
    static const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = daysInMonth[m];
    
    // Check for leap year and adjust days in February if necessary
    if (m == 2 && isLeapYear(y))
    {
        days = 29;
    }

    return days;
}

// Helper method to check if a year is a leap year
bool Date::isLeapYear(int y) const
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}


