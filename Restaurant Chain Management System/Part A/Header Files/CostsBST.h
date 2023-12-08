#ifndef COSTSBST_H
#define COSTSBST_H
#include "DailyCost.h"
class costsBST
{
      struct Node {
        dailyCost cost;
        Node* right;
        Node* left;
        Node(dailyCost dCost,Node* r,Node* l):cost(dCost),right(r),left(l){};
        Node():right(0),left(0){};
    };
    






    // isertion
    // deletion + useful funcions for BST (ISEMPTY() , CONTAINS()..,ETC)
    //function to return min and max (daily sale) (you can add it for the max sale on a month if you see it's useful)
    // function to return costs on a specific period
    // function to return total costs on a month
    // function to return total costs on a year
};
#endif
