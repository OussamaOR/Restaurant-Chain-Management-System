#ifndef MONTHLYRATING_H
#define MONTHLYRATING_H
#include <utility>
#include <vector>

class MonthlyRating
{
public:
    // default constructor
    MonthlyRating();
    // constructor with parameters
    MonthlyRating(int, int, std::vector<int>);
    // copy constructor
    MonthlyRating(const MonthlyRating &);
    // move constructor
    MonthlyRating(MonthlyRating &&);

    // setter and getter for rating dates
    void set_RatingDates(int, int);
    std::pair<int, int> get_RatingDates();
    // setters and getters for ratings
    void setRatings(const std::vector<int> &ratings);
    std::vector<int> getRatings() const;

    // print function
    void printAverageMonthlyRating() const;
    // insert function
    void insertMonthlyRating(int n);
    // function that return the average monthly rating
    float averageRating() const;

    // operator overloading
    bool operator<(const MonthlyRating &) const;
    bool operator>(const MonthlyRating &) const;
    bool operator==(const MonthlyRating &) const;
    bool operator!=(const MonthlyRating &) const;
    bool operator<=(const MonthlyRating &) const;
    bool operator>=(const MonthlyRating &) const;
    MonthlyRating &operator=(const MonthlyRating &);

    // destructor
    ~MonthlyRating();

private:
    std::pair<int, int> ratingdate;
    std::vector<int> ratings;
};
#endif
