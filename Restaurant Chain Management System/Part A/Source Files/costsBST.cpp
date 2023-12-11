
#include "../Header Files/dailyCost.h"
#include "../Header Files/costsBST.h"
#include "../Header Files/Date.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>

using namespace std;
void Costs::fill_costsBST(const dailyCost& d_cost)  {
    dailyCostsBST.insert(d_cost);
}
float Costs::max_sale(BinarySearchTree<dailyCost>::Node* root, float& current) {
    if (root == nullptr) return current;

    if (current < root->data.getTotal()) current = root->data.getTotal();

    max_sale(root->left, current);
    max_sale(root->right, current);

    return current;
}

float Costs::min_sale(BinarySearchTree<dailyCost>::Node* root, float& current) {
    if (root == nullptr) return current;

    if (current > root->data.getTotal()) current = root->data.getTotal();

    min_sale(root->left, current);
    min_sale(root->right, current);

    return current;
}

float Costs::total_onmonth(BinarySearchTree<dailyCost>::Node* root, float& total, int month, int year) {
    if (root == nullptr) return total;

    if (root->data.getDate().getYear() == year && root->data.getDate().getMonth() == month)
        total += root->data.getTotal();

    total_onmonth(root->left, total, month, year);
    total_onmonth(root->right, total, month, year);

    return total;
}

float Costs::total_onyear(BinarySearchTree<dailyCost>::Node* root, float& total, int year) {
    if (root == nullptr) return total;

    if (root->data.getDate().getYear() == year) total += root->data.getTotal();

    total_onyear(root->left, total, year);
    total_onyear(root->right, total, year);

    return total;
}

float Costs::total_onperiod(BinarySearchTree<dailyCost>::Node* root, float& total, Date start_date, Date end_date) {
    if (root == nullptr) return total;

    if (root->data.getDate() >= start_date && root->data.getDate() <= end_date)
        total += root->data.getTotal();

    total_onperiod(root->left, total, start_date, end_date);
    total_onperiod(root->right, total, start_date, end_date);

    return total;
}










int main(){
   

}