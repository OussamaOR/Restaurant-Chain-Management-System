#include "../Source Files/BinarySearchTree.cpp"
#include "dailyCost.h"

class Costs {
    private:
    BinarySearchTree<dailyCost> dailyCostsBST;

    public:
    void fill_costsBST(const dailyCost&);
    float max_sale(BinarySearchTree<dailyCost>::Node*,float&);
    float mix_sale(BinarySearchTree<dailyCost>::Node*,float&);
    float total_onmonth(BinarySearchTree<dailyCost>::Node*,float&,int,int);
    float total_onyear(BinarySearchTree<dailyCost>::Node*,float&,int);
    float total_onperiod(BinarySearchTree<dailyCost>::Node*,float&,Date,Date);
};
