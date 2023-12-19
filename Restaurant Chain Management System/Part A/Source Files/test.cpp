#include "../Header Files/SalesVec.h"
#include "../Header Files/MonthlyRating.h"
#include "../Header Files/RatingsBST.h"
int main()
{
    std::vector<int> ratingsJan = {2, 4, 3, 1, 5, 2, 3, 4, 1, 3, 2, 4, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4};
    std::vector<int> ratingsFeb = {5, 4, 4, 5, 2, 3, 1, 4, 3, 5, 1, 2, 4, 5, 3, 1, 2, 4, 5, 3, 1, 2, 4, 5, 3, 1, 2, 4, 5, 3, 1};
    std::vector<int> ratingsMar = {4, 3, 4, 5, 1, 2, 3, 4, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4};
    std::vector<int> ratingsApr = {4, 5, 3, 5, 1, 2, 3, 4, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4};
    std::vector<int> ratingsMay = {2, 1, 5, 3, 4, 2, 3, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2};
    std::vector<int> ratingsJun = {3, 2, 4, 1, 5, 3, 1, 4, 2, 3, 5, 4, 1, 2, 3, 5, 4, 1, 2, 3, 5, 4, 1, 2, 3, 5, 4, 1, 2, 3, 5};
    std::vector<int> ratingsJul = {1, 4, 5, 3, 2, 1, 3, 5, 4, 2, 1, 3, 5, 4, 2, 1, 3, 5, 4, 2, 1, 3, 5, 4, 2, 1, 3, 5, 4, 2, 1};
    std::vector<int> ratingsAug = {5, 2, 3, 1, 4, 5, 1, 3, 2, 4, 5, 3, 1, 2, 4, 5, 3, 1, 2, 4, 5, 3, 1, 2, 4, 5, 3, 1, 2, 4, 5};
    std::vector<int> ratingsSep = {2, 5, 1, 4, 3, 2, 5, 4, 1, 3, 2, 5, 4, 1, 3, 2, 5, 4, 1, 3, 2, 5, 4, 1, 3, 2, 5, 4, 1, 3, 2};
    std::vector<int> ratingsOct = {3, 2, 5, 4, 1, 3, 5, 2, 4, 1, 3, 5, 2, 4, 1, 3, 5, 2, 4, 1, 3, 5, 2, 4, 1, 3, 5, 2, 4, 1, 3};
    std::vector<int> ratingsNov = {4, 1, 3, 5, 2, 3, 1, 4, 3, 5, 1, 2, 4, 5, 3, 1, 2, 4, 5, 3, 1, 2, 4, 5, 3, 1, 2, 4, 5, 3, 1};
    std::vector<int> ratingsDec = {1, 4, 2, 3, 5, 1, 3, 2, 4, 5, 3, 1, 2, 4, 5, 3, 1, 2, 4, 5, 3, 1, 2, 4, 5, 3, 1, 2, 4, 5, 3};

    // Dates corresponding to each set of ratings
    std::pair<int, int> dateJan = {1, 2023};
    std::pair<int, int> dateFeb = {2, 2023};
    std::pair<int, int> dateMar = {3, 2023};
    std::pair<int, int> dateApr = {4, 2023};
    std::pair<int, int> dateMay = {5, 2023};
    std::pair<int, int> dateJun = {6, 2020};
    std::pair<int, int> dateJul = {7, 2020};
    std::pair<int, int> dateAug = {8, 2020};
    std::pair<int, int> dateSep = {9, 2020};
    std::pair<int, int> dateOct = {10, 2020};
    std::pair<int, int> dateNov = {11, 2020};
    std::pair<int, int> dateDec = {12, 2020};

    MonthlyRating ratingJan(dateJan.first, dateJan.second, ratingsJan);
    MonthlyRating ratingFeb(dateFeb.first, dateFeb.second, ratingsFeb);
    MonthlyRating ratingMar(dateMar.first, dateMar.second, ratingsMar);
    MonthlyRating ratingApr(dateApr.first, dateApr.second, ratingsApr);
    MonthlyRating ratingMay(dateMay.first, dateMay.second, ratingsMay);
    MonthlyRating ratingJun(dateJun.first, dateJun.second, ratingsJun);
    MonthlyRating ratingJul(dateJul.first, dateJul.second, ratingsJul);
    MonthlyRating ratingAug(dateAug.first, dateAug.second, ratingsAug);
    MonthlyRating ratingSep(dateSep.first, dateSep.second, ratingsSep);
    MonthlyRating ratingOct(dateOct.first, dateOct.second, ratingsOct);
    MonthlyRating ratingNov(dateNov.first, dateNov.second, ratingsNov);
    MonthlyRating ratingDec(dateDec.first, dateDec.second, ratingsDec);

    ratingsBST r1;
    r1.insertRating(ratingJan);
    r1.insertRating(ratingFeb);
    r1.insertRating(ratingMar);
    r1.insertRating(ratingApr);
    r1.insertRating(ratingMay);
    r1.insertRating(ratingJun);
    r1.insertRating(ratingJul);
    r1.insertRating(ratingAug);
    r1.insertRating(ratingSep);
    r1.insertRating(ratingOct);
    r1.insertRating(ratingNov);
    r1.insertRating(ratingDec);

    r1.print(r1.getRoot());
}