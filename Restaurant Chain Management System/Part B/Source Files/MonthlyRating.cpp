// this is the class for the avl part
#include "MonthlyRating.h"
#include <iostream>

// default constructor
MonthlyRating::MonthlyRating()
{
    ratingdate.first = 1;
    ratingdate.second = 2000;
    ratings = std::vector<int>(31, 1);
    leftChild = nullptr;
    rightChild = nullptr;
    height = 0;

}
MonthlyRating::MonthlyRating(int a, int b, std::vector<int> r)
{
    ratingdate.first = (a > 0 && a <= 12) ? a : 1;
    ratingdate.second = (b > 1999) ? b : 2000;
    ratings = r;
    leftChild = nullptr;
    rightChild = nullptr;
    height = 0;
}
// copy constructor
MonthlyRating::MonthlyRating(const MonthlyRating &other)
{
    *this = other;
}
// move constructor
MonthlyRating::MonthlyRating(MonthlyRating &&other) : ratingdate(std::move(other.ratingdate)), ratings(std::move(other.ratings)) {}

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
    std::string months[] =
    {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    std::cout << months[ratingdate.first -1] << " " << ratingdate.second << " :\n ";
    std::cout << "Average mothly rating : " << this->averageRating() << std::endl;
}

// insert function
void MonthlyRating::insertMonthlyRating(int n)
{
    ratings.push_back((n > 0 && n < 6) ? n : 1);
}

// calculate the average for a month
double MonthlyRating::averageRating() const
{
    double average = 0;
    for (int i = 0; i < ratings.size(); i++)
    {
        average += ratings[i];
    }
    return average / ratings.size();
}

// operator overloading
bool MonthlyRating::operator<(const std::pair<int, int> &z) const
{
    if (ratingdate.second < z.second)
    {
        return true;
    }
    else
    {
        if (ratingdate.second == z.second && ratingdate.first < z.first)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
bool MonthlyRating ::operator>(const std::pair<int, int> &z) const
{
    if (ratingdate.second > z.second)
    {
        return true;
    }
    else
    {
        if (ratingdate.second == z.second && ratingdate.first > z.first)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool MonthlyRating ::operator==(const std::pair<int, int> &z) const
{
    if (ratingdate.second == z.second && ratingdate.first == z.first)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MonthlyRating ::operator!=(const std::pair<int, int> &z) const
{
    return !(*this == z);
}

bool MonthlyRating ::operator<=(const std::pair<int, int> &z) const
{
    return !(*this > z);
}

bool MonthlyRating::operator>=(const std::pair<int, int> &z) const
{
    return !(*this < z);
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

// destructor
MonthlyRating::~MonthlyRating() {}

//setters and getters needed for BST
MonthlyRating *MonthlyRating::getLeftChild() const
{
    return leftChild;
}

MonthlyRating *MonthlyRating::getRightChild() const
{
    return rightChild;
}

void MonthlyRating::setLeftChild(MonthlyRating *left)
{
    leftChild = left;
}

void MonthlyRating::setRightChild(MonthlyRating *right)
{
    rightChild = right;
}


