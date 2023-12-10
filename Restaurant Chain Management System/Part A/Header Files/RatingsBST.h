#ifndef BSTRATING_H
#define BSTRATING_H
#include "MonthRating.h"
#include <utility>
#include <vector>
#include <iostream>
using namespace std;

class bstrating
{
    public:
        bstrating(MonthRating );
        virtual ~bstrating();
        //bstrating(const bstrating& other);
        float ccalculate_yearrating(bstrating* , int );
        void makeEmpty( bstrating*& );
        void printDailyratingdetails(bstrating* );
        void printMonthlyRating(bstrating* );
        void remove_Mrating(MonthRating&  ,bstrating*& );
        void insert_Mrating(MonthRating&  ,bstrating*& );
        bstrating* getLeft() const {return left;};
        bstrating* getRight() const {return right;};
        MonthRating getData() const{return data ;};
        float getmounthlyrating();
        float get_maxrating(bstrating* );
        float get_minrating(bstrating* );
    protected:
   float mrating;
   MonthRating data;
   bstrating* left;
   bstrating* right;
    private:
    void calculate_yearrating_helper(bstrating*, int , float& );

};

#endif // BSTRATING_H
