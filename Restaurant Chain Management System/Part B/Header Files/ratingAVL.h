#include "..\Restaurant-Chain-Management-System\Restaurant Chain Management System\Part B\Header Files\MonthlyRating.h"
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
    bool makeEmpty(MonthlyRating *);
    MonthlyRating *getRoot() const
    {
        return root;
    }
    void printLevelOrder(MonthlyRating *);
    // functions used when print the needed results
    double getAverageRatingByMonth(MonthlyRating *, int, int); // int month and int year;
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
};

#endif // RATINGAVL_H