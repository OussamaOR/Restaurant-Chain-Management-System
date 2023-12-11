#include "MonthlyRating.h"
#include <iostream>

// default constructor
MonthlyRating::MonthlyRating()
{
    ratingdate.first = 1;
    ratingdate.second = 2000;
    ratings = std::vector<int>(31, 1);
}
MonthlyRating::MonthlyRating(int a, int b, std::vector<int> r)
{
    ratingdate.first = (a > 0 && a <= 12) ? a : 1;
    ratingdate.second = (b > 1999) ? b : 2000;
    ratings = r;
}
// copy constructor
MonthlyRating::MonthlyRating(const MonthlyRating &other)
{
    *this = other;
}
// move constructor
MonthlyRating::MonthlyRating(MonthlyRating && other) : ratingdate(std::move(other.ratingdate)), ratings(std::move(other.ratings)) {}

// Setter and Getter
// the ratingdate setters and getters
void MonthlyRating::set_RatingDates(int a, int b)
{
    ratingdate.first = (a > 0 && a <= 12) ? a : 1;
    ratingdate.second = (b > 1999) ? b : 2000;
}
std::pair<int, int> MonthlyRating::get_RatingDates()
{
    return ratingdate;
}
// ratings setters and getters
void MonthlyRating::setRatings(const std::vector<int> &newRatings)
{
    ratings = newRatings;
}
std::vector<int> MonthlyRating::getRatings() const
{
    return ratings;
}

// print function
void MonthlyRating::printAverageMonthlyRating() const
{
    std::string months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"};
    std::cout << months[ratingdate.first] << " " << ratingdate.second << " :\n ";
    std::cout << "Average mothly rating : " << this->averageRating() << std::endl;
}

// insert function
void MonthlyRating::insertMonthlyRating(int n)
{
    ratings.push_back(n);
}

// calculate the average for a month
float MonthlyRating::averageRating() const
{
    float average = 0;
    for (int i = 0; i < ratings.size(); i++)
    {
        average += ratings[i];
    }
    return average / ratings.size();
}

// operator overloading
bool MonthlyRating ::operator<(const MonthlyRating &z) const
{
    if (ratingdate.second < z.ratingdate.second)
    {
        return true;
    }
    else
    {
        if (ratingdate.second == z.ratingdate.second && ratingdate.first < z.ratingdate.first)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
bool MonthlyRating ::operator>(const MonthlyRating &z) const
{
    return !(*this < z);
}

bool MonthlyRating ::operator==(const MonthlyRating &z) const
{
    if (ratingdate.second == z.ratingdate.second && ratingdate.first == z.ratingdate.first)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MonthlyRating ::operator!=(const MonthlyRating &z) const
{
    return !(*this == z);
}

bool MonthlyRating ::operator<=(const MonthlyRating &z) const
{
    if (ratingdate.second < z.ratingdate.second)
    {
        return true;
    }
    else
    {
        if (ratingdate.second == z.ratingdate.second && ratingdate.first <= z.ratingdate.first)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool MonthlyRating ::operator>=(const MonthlyRating &z) const
{
    return !(*this <= z);
}
MonthlyRating &MonthlyRating::operator=(const MonthlyRating &other)
{
    if (this != &other)
    {
        this->ratingdate = other.ratingdate;

        this->ratings = other.ratings;
    }
    return *this;
}

//destructor 
MonthlyRating::~MonthlyRating(){}