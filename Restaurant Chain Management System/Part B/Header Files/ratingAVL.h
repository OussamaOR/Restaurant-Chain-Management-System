#include "../Header Files/MonthlyRating.h"
#ifndef RATINGAVL_H
#define RATINGAVL_H

class ratingAVL
{
public:
    ratingAVL();
    ~ratingAVL();
    ratingAVL(MonthlyRating &);
    void insertRatingAVL(MonthlyRating &);
    void insertRatingAVL(std::pair<int, int>, std::vector<int>);
    void removeAVL(MonthlyRating &);
    void removeAVL(std::pair<int, int>, std::vector<int>);
    void printAVL(MonthlyRating *);
    void printLevelOrder(MonthlyRating *);
    bool makeEmpty(MonthlyRating *);
    MonthlyRating *getRoot() const     {   return root;   }
    double getAverageRatingByMonth(MonthlyRating *, int, int); 
    double getAverageRatingByMonth(MonthlyRating *, std::pair<int, int>);
    double getAverageratingByYear(MonthlyRating *, int);
    double getAverageratingByPeriod(MonthlyRating *, std::pair<int, int>, std::pair<int, int>);

private:
    MonthlyRating *root;
    // helper functions
    MonthlyRating *insertHelperAVL(MonthlyRating *, std::pair<int, int>, std::vector<int>);
    MonthlyRating *removeHelperAVL(MonthlyRating *, std::pair<int, int>, std::vector<int>);
    MonthlyRating *findMin(MonthlyRating *) const;
    double getAverageRatingByMonthHelper(MonthlyRating *, std::pair<int, int>);
    double getAverageratingByYearHelper(MonthlyRating *, int, int &, double &);
    double getAverageratingByPeriodHelper(MonthlyRating *, std::pair<int, int>, std::pair<int, int>);
    bool checkDate(std::pair<int, int>);
    void printHelper(MonthlyRating *) const;
    MonthlyRating *balanceAVL(MonthlyRating *node);
    MonthlyRating *rotateRight(MonthlyRating *y);
    MonthlyRating *rotateLeft(MonthlyRating *x);
    int getHeight(MonthlyRating *node);
    int getBalanceFactor(MonthlyRating *node);
    bool DateInBst(MonthlyRating* , std::pair<int ,int> );
    bool YearInBst(MonthlyRating* , int );
};

#endif // RATINGAVL_H