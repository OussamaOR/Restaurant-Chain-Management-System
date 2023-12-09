
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
float Costs::max_sale(BinarySearchTree<dailyCost>::Node* root,float& current = 0.f){
   
    if(root == nullptr) return;

    if(current < root->data.getTotal()) current = root -> data.getTotal();

    max_sale(root->left,current);
    max_sale(root->right,current);
    return current;
}
float Costs::min_sale(BinarySearchTree<dailyCost>::Node* root,float& current = static_cast<float>(INT32_MAX)){
   
    if(root == nullptr) return;

    if(current > root->data.getTotal()) current = root -> data.getTotal();

    min_sale(root->left,current);
    min_sale(root->right,current);
    return current;
}
float Costs::total_onmonth(BinarySearchTree<dailyCost>::Node* root,float& total = 0,int month,int year){
    if(root == nullptr) return;
    if(root->data.getDate().getYear() == year and root->data.getDate().getMonth() == month) total += root->data.getTotal();

    total_onmonth(root->left,total);
    total_onmonth(root->right,total);
    return total;
}
float Costs::total_onyear(BinarySearchTree<dailyCost>::Node* root,float& total = 0,int month){
     if(root == nullptr) return;
    if( root->data.getDate().getMonth() == month) total += root->data.getTotal();

    total_onmonth(root->left,total);
    total_onmonth(root->right,total);
    return total;
}
float Costs::total_onperiod(BinarySearchTree<dailyCost>::Node* root,float& total = 0,Date start_date,Date end_date){
    if(root == nullptr) return;
    if(root->data.getDate() >= start_date and root->data.getDate() <= end_date) total += root->data.getTotal();

    total_onmonth(root->left,total);
    total_onmonth(root->right,total);
    return total;
}




void prog(){
    ifstream dailycosts_file("../../Database/dailycosts.csv");
    if(!dailycosts_file.is_open()){
        cerr << "couldn't open dailycosts.csv" << endl;
    }
    string lines;
    int number_of_lines = 0;
    while(getline(dailycosts_file,lines)){
        number_of_lines++;
    }
     dailycosts_file.seekg(0, std::ios::beg);
    vector<dailyCost> dailyCosts(number_of_lines);
    for(int i = 0;i<number_of_lines;i++){   //reading each line
        int date_data[3];
        float costs_data[8];
        char slash;
        dailycosts_file >> date_data[0] >> slash >> date_data[1] >> slash >> date_data[2];
        dailyCosts[i].setDate(Date(date_data[0],date_data[1],date_data[2]));
        for(int j = 0;j<8;j++){
            dailycosts_file >> costs_data[j];
        }
        dailyCosts[i].setCosts(costs_data);
    }
    // now we have all the data in a vector , we need to insert it randomly to the bst
    // we get random index
    Costs daily_costs;
    while(!dailyCosts.empty()){
        unsigned x = rand() % dailyCosts.size();
        daily_costs.fill_costsBST(dailyCosts[x]);
        dailyCosts.erase(dailyCosts.begin()+x);
    }

   
}



int main(){
   srand(time(0));
   prog();

}