#ifndef RATINGSBST_H
#define RATINGSBST_H
#include "MonthlyRating.h"
#include <utility>
#include <vector>
#include <iostream>
using namespace std;

class ratingsBST
{
    public:
        ratingsBST(MonthlyRating );
        virtual ~ratingsBST();
        //ratingsBST(const ratingsBST& other);
        float ccalculate_yearrating(ratingsBST* , int );
        void makeEmpty( ratingsBST*& );
        void printDailyratingdetails(ratingsBST* );
        void printMonthlyRating(ratingsBST* );
        void remove_Mrating(MonthlyRating&  ,ratingsBST*& );
        void insert_Mrating(MonthlyRating&  ,ratingsBST*& );
        ratingsBST* getLeft() const {return left;};
        ratingsBST* getRight() const {return right;};
        MonthlyRating getData() const{return data ;};
        float getmounthlyrating();
        float get_maxrating(ratingsBST* );
        float get_minrating(ratingsBST* );
    protected:
   float mrating;
   MonthlyRating data;
   ratingsBST* left;
   ratingsBST* right;
    private:
    void calculate_yearrating_helper(ratingsBST*, int , float& );

};

#endif 
