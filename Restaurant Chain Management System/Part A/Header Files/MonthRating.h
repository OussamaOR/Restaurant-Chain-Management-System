#ifndef MONTHRATING_H
#define MONTHRATING_H
#include <utility>
#include <vector>

class MonthRating
{
    public:
        MonthRating( int , int );
        virtual ~MonthRating();
        void set_RatingDates(int , int );
        std::pair<int, int> get_RatingDates();
        void print_RatingDates() const;
        void insert_dayrating(int n);
        void printdilyrating() const;
        float averagerating();
        bool operator<(const MonthRating&)const ;
        bool operator>(const MonthRating&)const ;
        bool operator==(const MonthRating&)const ;
        bool operator!=(const MonthRating&)const ;
        bool operator<=(const MonthRating&)const ;
        bool operator>=(const MonthRating&)const ;
    protected:
     std::pair<int , int> ratingdate;
     std::vector<int > ratings;
     std::size_t dayindex;
     std::size_t maxsize;
};

#endif // MONTHRATING_H
