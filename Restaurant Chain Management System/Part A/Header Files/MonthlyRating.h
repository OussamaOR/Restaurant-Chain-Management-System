#ifndef MONTHLYRATING_H
#define MONTHLYRATING_H
#include <utility>
#include <vector>

class MonthlyRating
{
public:
    MonthlyRating(int, int);
    virtual ~MonthlyRating();
    void set_RatingDates(int, int);
    std::pair<int, int> get_RatingDates();
    void print_RatingDates() const;
    void insert_dayrating(int n);
    void printdilyrating() const;
    float averagerating();
    bool operator<(const MonthlyRating &) const;
    bool operator>(const MonthlyRating &) const;
    bool operator==(const MonthlyRating &) const;
    bool operator!=(const MonthlyRating &) const;
    bool operator<=(const MonthlyRating &) const;
    bool operator>=(const MonthlyRating &) const;

    // setters and getters
    void setRatingDate(int year, int month);
    std::pair<int, int> getRatingDate() const;

    void setRatings(const std::vector<int> &ratings);
    std::vector<int> getRatings() const;

    void setDayIndex(std::size_t dayIndex);
    std::size_t getDayIndex() const;

    void setMaxSize(std::size_t maxSize);
    std::size_t getMaxSize() const;

private:
    std::pair<int, int> ratingdate;
    std::vector<int> ratings;
    std::size_t dayindex;
    std::size_t maxsize;
};
#endif
