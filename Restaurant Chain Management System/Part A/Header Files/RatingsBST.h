#include "MonthlyRating.h"
#include "../Source Files/BinarySearchTree.cpp"
#ifndef RATINGSBST_H
#define RATINGSBST_H

class ratingsBST
{

public:
    ratingsBST();
    ~ratingsBST();
    ratingsBST(MonthlyRating &);
    void insertRating(MonthlyRating &);
    void insertRating(std::pair<int,int> , std::vector<int>);
    void remove(MonthlyRating &);
    void remove(std::pair<int,int> , std::vector<int>);
    void print(MonthlyRating*);
    bool makeEmpty(MonthlyRating* );

    //functions used when print the needed results
    float getAverageRatingByMonth(MonthlyRating*,int , int);//int month and int year;
    float getAverageRatingByMonth(MonthlyRating*,std::pair<int,int>);

    float getAverageratingByYear(MonthlyRating*,int);

    float getAverageratingByPeriod(MonthlyRating*,std::pair<int,int>,std::pair<int,int>);
    private:

    MonthlyRating *root;
    //helper functions
    MonthlyRating *insertHelper(MonthlyRating *, std::pair<int,int> , std::vector<int>);
    MonthlyRating *removeHelper(MonthlyRating *,std::pair<int,int> , std::vector<int>);
    MonthlyRating *findMin(MonthlyRating *) const;
    float getAverageRatingByMonthHelper(MonthlyRating* ,int , int);
    float getAverageratingByYearHelper(MonthlyRating*,int);
    float getAverageratingByPeriod(MonthlyRating*,std::pair<int,int>,std::pair<int,int>);
    void printHelper(MonthlyRating *) const;
};

#endif
