#include "MonthlyRating.h"
#include "../Source Files/BinarySearchTree.cpp"
#ifndef RATINGSBST_H
#define RATINGSBST_H

class ratingsBST
{
private:
    MonthlyRating *root;

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
private:
    MonthlyRating *insertHelper(MonthlyRating *, std::pair<int,int> , std::vector<int>);
    MonthlyRating *removeHelper(MonthlyRating *,std::pair<int,int> , std::vector<int>);
    MonthlyRating *findMin(MonthlyRating *) const;
    void printHelper(MonthlyRating *) const;
};

#endif
