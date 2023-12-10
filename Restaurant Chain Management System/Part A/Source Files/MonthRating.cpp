#include "MonthRating.h"
#include <utility>
#include <vector>
#include <iostream>
using namespace std;
//add a get the mounth / year / rating in a spesific date
// if setiing values will affect the size
MonthRating::MonthRating(int a ,int b )
{
    ratingdate.first = (a > 0 && a <= 12) ? a : 1;
    ratingdate.second = (b> 1999)?b:1999;
    dayindex = 0;
     if (a == 1 || a == 3 || a == 5 || a == 7 || a == 8 || a == 10 || a == 12) {
        maxsize = 31;
    }
    else if (a == 4 || a == 6 || a == 9 || a == 11) {
        maxsize = 30;
    }
    else if (a == 2) {
        if (b % 4 == 0) {
            maxsize = 29;
        } else {
            maxsize = 28;
        }
    }
    ratings = std::vector<int>(maxsize, 0);
}
//destructor:
MonthRating::~MonthRating()
{
}

// the ratingdate functions :
void  MonthRating::set_RatingDates(int a, int b){
    ratingdate.first = (a > 0 && a <= 12) ? a : 1;
    ratingdate.second = (b> 1999)?b:1999;
 }
 pair<int, int> MonthRating:: get_RatingDates(){
      return ratingdate;
 }
void  MonthRating::print_RatingDates()const{
std::string months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"};
 std::cout<<months[ratingdate.first]<<" "<<ratingdate.second<<" : ";
 }

 //insert function
void MonthRating::insert_dayrating(int n){
 if(dayindex <ratings.size()){
    ratings[dayindex]= n;
 }
 dayindex++;
 }

//print function : print all rating in order of the days depending on the month
void MonthRating::printdilyrating() const {
        std::cout << "rating of the month : ";
        for (const auto& element : ratings) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
// calculate the average for a month
float MonthRating::averagerating(){
    int averate = 0;
for(int i =0 ; i<maxsize ; i++){
    averate += ratings[i];
}
return averate/maxsize;
}

// operator overloading :
// the code gives priority to the year then the month
bool MonthRating :: operator<(const MonthRating& z)const {
if(ratingdate.second < z.ratingdate.second){return true;}
else{
    if(ratingdate.second == z.ratingdate.second && ratingdate.first< z.ratingdate.first){
            return true;}else{ return false;}}
}
bool MonthRating :: operator>(const MonthRating& z)const {
return!(*this < z);}

bool MonthRating :: operator==(const MonthRating&z)const {
 if(ratingdate.second == z.ratingdate.second && ratingdate.first == z.ratingdate.first){
return true;}else{ return false;}}

bool MonthRating :: operator!=(const MonthRating&z)const {
return !(*this == z);}

bool MonthRating :: operator<=(const MonthRating&z)const {
  if(ratingdate.second < z.ratingdate.second){return true;}
else{
    if(ratingdate.second == z.ratingdate.second && ratingdate.first<= z.ratingdate.first){
            return true;}else{ return false;}}
}

bool MonthRating :: operator>=(const MonthRating&z)const {
return !(*this <= z);}


