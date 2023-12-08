#include "../Utilities Files/BinarySearchTree.h"
#include "../Header Files/dailyCost.h"
#include <iostream>
#include <vector>
#include <cstdlib>  // For rand()
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;
void prog(){
    ifstream dailycosts("../../Database/dailycosts.csv");
    if(!dailycosts.is_open()){
        cerr << "couldn't open dailycosts file!!" << endl;
    }
    int date[3];
    char slash;
    if(!(dailycosts >> date[0] >> slash  >> date[1] >> slash >>date[2])){
        cerr << "error reading data";
    }
    
    cout << date[0] << endl << date[1] << endl <<  date[2];
}
int main(){
   srand(time(0));
    prog();

}