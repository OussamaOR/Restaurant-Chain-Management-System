#ifndef MONTHLYRATING_H
#define MONTHLYRATING_H
#include <utility>
#include <vector>

class MonthlyRating
{
    public:
        MonthlyRating( int , int );
        virtual ~MonthlyRating();
        void set_RatingDates(int , int );
        std::pair<int, int> get_RatingDates();
        void print_RatingDates() const;
        void insert_dayrating(int n);
        void printdilyrating() const;
        float averagerating();
        bool operator<(const MonthlyRating&)const ;
        bool operator>(const MonthlyRating&)const ;
        bool operator==(const MonthlyRating&)const ;
        bool operator!=(const MonthlyRating&)const ;
        bool operator<=(const MonthlyRating&)const ;
        bool operator>=(const MonthlyRating&)const ;
    protected:
     std::pair<int , int> ratingdate;
     std::vector<int > ratings;
     std::size_t dayindex;
     std::size_t maxsize;
};
#endif 
