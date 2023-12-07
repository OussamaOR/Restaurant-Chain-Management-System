#ifndef COSTSBST_H
#define COSTSBST_H
#include "date.h"
enum costType
{
    rent,
    employeePayments,
    electricity,
    gas,
    vegetables,
    meats,
    otherIngredients,
    publicitySpending
};
class dailyCost
{
    Date date;
    costType costType[8];
    // getters
    // setters
    // function to retun total daily cost (summing all the elements of the array)
};
class costsBST
{
    dailyCost *root;
    // isertion
    // deletion + useful funcions for BST (ISEMPTY() , CONTAINS()..,ETC)
    //function to return min and max (daily sale) (you can add it for the max sale on a month if you see it's useful)
    // function to return costs on a specific period
    // function to return total costs on a month
    // function to return total costs on a year
};
#endif
