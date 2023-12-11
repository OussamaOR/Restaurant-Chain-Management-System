#include "MonthlyRating.h"
#include <utility>
#include <vector>
#include <iostream>
using namespace std;
//add a get the mounth / year / rating in a spesific date
// if setiing values will affect the size
MonthlyRating::MonthlyRating(int a ,int b )
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
MonthlyRating::~MonthlyRating()
{
}

// the ratingdate functions :
void  MonthlyRating::set_RatingDates(int a, int b){
    ratingdate.first = (a > 0 && a <= 12) ? a : 1;
    ratingdate.second = (b> 1999)?b:1999;
 }
 pair<int, int> MonthlyRating:: get_RatingDates(){
      return ratingdate;
 }
void  MonthlyRating::print_RatingDates()const{
std::string months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"};
 std::cout<<months[ratingdate.first]<<" "<<ratingdate.second<<" : ";
 }

 //insert function
void MonthlyRating::insert_dayrating(int n){
 if(dayindex <ratings.size()){
    ratings[dayindex]= n;
 }
 dayindex++;
 }

//print function : print all rating in order of the days depending on the month
void MonthlyRating::printdilyrating() const {
        std::cout << "rating of the month : ";
        for (const auto& element : ratings) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
// calculate the average for a month
float MonthlyRating::averagerating(){
    int averate = 0;
for(int i =0 ; i<maxsize ; i++){
    averate += ratings[i];
}
return averate/maxsize;
}

// operator overloading :
// the code gives priority to the year then the month
bool MonthlyRating :: operator<(const MonthlyRating& z)const {
if(ratingdate.second < z.ratingdate.second){return true;}
else{
    if(ratingdate.second == z.ratingdate.second && ratingdate.first< z.ratingdate.first){
            return true;}else{ return false;}}
}
bool MonthlyRating :: operator>(const MonthlyRating& z)const {
return!(*this < z);}

bool MonthlyRating :: operator==(const MonthlyRating&z)const {
 if(ratingdate.second == z.ratingdate.second && ratingdate.first == z.ratingdate.first){
return true;}else{ return false;}}

bool MonthlyRating :: operator!=(const MonthlyRating&z)const {
return !(*this == z);}

bool MonthlyRating :: operator<=(const MonthlyRating&z)const {
  if(ratingdate.second < z.ratingdate.second){return true;}
else{
    if(ratingdate.second == z.ratingdate.second && ratingdate.first<= z.ratingdate.first){
            return true;}else{ return false;}}
}

bool MonthlyRating :: operator>=(const MonthlyRating&z)const {
return !(*this <= z);}


//setters and getters 
void MonthlyRating::setRatingDate(int m, int y)
{
    ratingdate.first = (m > 0 && m <= 12) ? m : 1;
    ratingdate.second = (y> 1999)?y:1999;
}

std::pair<int, int> MonthlyRating::getRatingDate() const
{
    return ratingdate;
}

// Setter and Getter for ratings
void MonthlyRating::setRatings(const std::vector<int>& newRatings)
{
    ratings = newRatings;
}

std::vector<int> MonthlyRating::getRatings() const
{
    return ratings;
}

// Setter and Getter for dayIndex
void MonthlyRating::setDayIndex(std::size_t newDayIndex)
{
    if(dayindex>=0)
    dayindex = newDayIndex;
}

std::size_t MonthlyRating::getDayIndex() const
{
    return dayindex;
}

// Setter and Getter for maxSize
void MonthlyRating::setMaxSize(std::size_t newMaxSize)
{
    if(maxsize>=0)
    maxsize = newMaxSize;
}

std::size_t MonthlyRating::getMaxSize() const
{
    return maxsize;
}

