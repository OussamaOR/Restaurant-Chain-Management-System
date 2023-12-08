
#include "../Header Files/dailyCost.h"
#include "../Header Files/costsBST.h"
#include "../Header Files/Date.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>

using namespace std;

void prog(){
    ifstream dailycosts("../../Database/dailycosts.csv");
    if(!dailycosts.is_open()){
        cerr << "couldn't open dailycosts.csv" << endl;
    }
    string lines;
    int number_of_lines = 0;
    while(getline(dailycosts,lines)){
        number_of_lines++;
    }
    
    vector<vector<float>> dailycosts_values(number_of_lines);
    Date date;
    int x;
    dailycosts >> x;
    cout << x;
}



int main(){
   srand(time(0));
   prog();

}