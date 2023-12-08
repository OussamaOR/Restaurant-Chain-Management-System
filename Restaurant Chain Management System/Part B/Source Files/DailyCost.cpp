#include "../Header Files/dailyCost.h"

dailyCost::dailyCost(){
    for(int i = 0;i<8;i++){
        costs[i] = 0.0;
    }
}
dailyCost::dailyCost(Date cost_date,float cost_arr[8]): date(cost_date) {
    for(int i = 0;i<8;i++){
        costs[i] = cost_arr[i];
    }
}
float dailyCost::totalDailyCost(){
    float total = 0;
    for(int i = 0;i<8;i++){
        total += costs[i];
    }
    return total;
}
