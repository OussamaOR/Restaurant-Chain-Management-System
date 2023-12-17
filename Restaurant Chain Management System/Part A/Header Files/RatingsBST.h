#include "MonthlyRating.h"
// #include "../Source Files/BinarySearchTree.cpp"
#ifndef RATINGSBST_H
#define RATINGSBST_H

class ratingsBST
{

public:
    ratingsBST();
    ~ratingsBST();
    ratingsBST(MonthlyRating &);
    void insertRating(MonthlyRating &);
    void insertRating(std::pair<int, int>, std::vector<int>);
    void remove(MonthlyRating &);
    void remove(std::pair<int, int>, std::vector<int>);
    void print(MonthlyRating *);
    bool makeEmpty(MonthlyRating *);
    MonthlyRating *getRoot() const { return root; }

    // functions used when print the needed results
    float getAverageRatingByMonth(MonthlyRating *, int, int); 
    float getAverageRatingByMonth(MonthlyRating *, std::pair<int, int>);
    float getAverageratingByYear(MonthlyRating *, int);
    float getAverageratingByPeriod(MonthlyRating *, std::pair<int, int>, std::pair<int, int>);

private:
    MonthlyRating *root;

    // helper functions
    MonthlyRating *insertHelper(MonthlyRating *, std::pair<int, int>, std::vector<int>);
    MonthlyRating *removeHelper(MonthlyRating *, std::pair<int, int>, std::vector<int>);
    MonthlyRating *findMin(MonthlyRating *) const;
    double getAverageRatingByMonthHelper(MonthlyRating *, std::pair<int, int>);
    double getAverageratingByYearHelper(MonthlyRating *, int, int &, double &);
    double getAverageratingByPeriodHelper(MonthlyRating *, std::pair<int, int>, std::pair<int, int>);
    bool checkDate(std::pair<int, int>);
    void printHelper(MonthlyRating *) const;
     bool DateInBst(MonthlyRating* , std::pair<int ,int> );
    bool YearInBst(MonthlyRating* , int );

};

#endif
