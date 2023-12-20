#include "../Header Files/RestaurantHashTable.h"
/*
int main()
{
    // costs vector
    float costs1[8] = {1600, 10517, 300, 200, 4610.71, 17206, 5606.28, 19276.6};
    Date date1(1, 5, 2015);
    float costs2[8] = {1600, 13848.4, 300, 200, 4229.22, 26056.4, 3997.19, 7422.38};
    Date date2(2, 5, 2015);
    float costs3[8] = {1600, 13135.3, 300, 200, 4871.4, 12249.2, 3469.22, 19824.9};
    Date date3(3, 5, 2015);
    float costs4[8] = {1600, 14168.1, 300, 200, 3152.53, 18387.7, 5296.67, 23614.2};
    Date date4(4, 5, 2015);
    float costs5[8] = {1600, 10116.7, 300, 200, 4066.87, 14286.6, 4691.95, 17162.7};
    Date date5(5, 5, 2015);
    float costs6[8] = {1600, 11462.4, 300, 200, 4561.51, 12517.8, 6446.91, 18668.9};
    Date date6(6, 5, 2015);

    dailyCost dailycost1(date1, costs1);
    dailyCost dailycost2(date2, costs2);
    dailyCost dailycost3(date3, costs3);
    dailyCost dailycost4(date4, costs4);
    dailyCost dailycost5(date5, costs5);
    dailyCost dailycost6(date6, costs6);
    std::vector<dailyCost> firstCost =
        {dailycost1, dailycost2, dailycost3, dailycost4, dailycost5, dailycost6};

    float costs7[8] = {1600, 11224.4, 300, 200, 4708.73, 27403.5, 6947.87, 4400.98};
    Date date7(7, 5, 2015);
    float costs8[8] = {1600, 11485.9, 300, 200, 3473.04, 21529.9, 4006.04, 16350.6};
    Date date8(8, 5, 2015);
    float costs9[8] = {1600, 14830.3, 300, 200, 4330.3, 14456.3, 4261.79, 16835};
    Date date9(9, 5, 2015);
    float costs10[8] = {1600, 12434.8, 300, 200, 4306.56, 16443.1, 3571.92, 28059};
    Date date10(10, 5, 2015);
    float costs11[8] = {1600, 13026.7, 300, 200, 4079.68, 17491.7, 3047.61, 1224.74};
    Date date11(11, 5, 2015);
    float costs12[8] = {1600, 13538.6, 300, 200, 4019.87, 28768.3, 5386.39, 27022.7};
    Date date12(12, 5, 2015);

    dailyCost dailycost7(date7, costs7);
    dailyCost dailycost8(date8, costs8);
    dailyCost dailycost9(date9, costs9);
    dailyCost dailycost10(date10, costs10);
    dailyCost dailycost11(date11, costs11);
    dailyCost dailycost12(date12, costs12);
    std::vector<dailyCost> secondCost =
        {dailycost7, dailycost8, dailycost9, dailycost10, dailycost11, dailycost12};

    CostsVec costsvec1(move(firstCost));
    CostsVec costsvec2(move(secondCost));

    // sales vector
    Date d1(1, 2, 2023);
    Date d2(2, 2, 2023);
    Date d3(3, 2, 2023);
    Date d4(4, 2, 2023);
    Date d5(5, 2, 2023);
    Date d6(6, 2, 2023);
    Date d7(7, 2, 2023);
    Date d8(8, 2, 2023);
    DailySale dailysale1(d1, 1920);
    DailySale dailysale2(d2, 4170);
    DailySale dailysale3(d3, 3910);
    DailySale dailysale4(d4, 4360);
    DailySale dailysale5(d5, 3040);
    DailySale dailysale6(d6, 2340);
    DailySale dailysale7(d7, 3740);
    DailySale dailysale8(d8, 2130);

    std::vector<DailySale> sales1 = {dailysale1, dailysale2, dailysale3, dailysale4,
                                     dailysale5, dailysale6, dailysale7, dailysale8};

    DailySale dailysale9(d1, 3240);
    DailySale dailysale10(d2, 5710);
    DailySale dailysale11(d3, 5060);
    DailySale dailysale12(d4, 6770);
    DailySale dailysale13(d5, 4430);
    DailySale dailysale14(d6, 3510);
    DailySale dailysale15(d7, 6030);
    DailySale dailysale16(d8, 2770);

    std::vector<DailySale> sales2 = {dailysale9, dailysale10, dailysale11, dailysale12,
                                     dailysale13, dailysale14, dailysale15, dailysale16};

    DailySale dailysale17(d1, 7450);
    DailySale dailysale18(d2, 2190);
    DailySale dailysale19(d3, 4860);
    DailySale dailysale20(d4, 3850);
    DailySale dailysale21(d5, 2970);
    DailySale dailysale22(d6, 6060);
    DailySale dailysale23(d7, 3470);
    DailySale dailysale24(d8, 9130);

    std::vector<DailySale> sales3 = {dailysale17, dailysale18, dailysale19, dailysale20,
                                     dailysale21, dailysale22, dailysale23, dailysale24};

    DailySale dailysale25(d1, 4880);
    DailySale dailysale26(d2, 1640);
    DailySale dailysale27(d3, 7390);
    DailySale dailysale28(d4, 3180);
    DailySale dailysale29(d5, 5720);
    DailySale dailysale30(d6, 4590);
    DailySale dailysale31(d7, 8250);
    DailySale dailysale32(d8, 2210);

    std::vector<DailySale> sales4 = {dailysale25, dailysale26, dailysale27, dailysale28,
                                     dailysale29, dailysale30, dailysale31, dailysale32};

    DailySale dailysale33(d1, 3240);
    DailySale dailysale34(d2, 5710);
    DailySale dailysale35(d3, 5060);
    DailySale dailysale36(d4, 6770);
    DailySale dailysale37(d5, 4430);
    DailySale dailysale38(d6, 3510);
    DailySale dailysale39(d7, 6030);
    DailySale dailysale40(d8, 2770);

    std::vector<DailySale> sales5 = {dailysale33, dailysale34, dailysale35, dailysale36,
                                     dailysale37, dailysale38, dailysale39, dailysale40};

    SalesVec salesvec1(move(sales1));
    SalesVec salesvec2(move(sales2));
    SalesVec salesvec3(move(sales3));
    SalesVec salesvec4(move(sales4));
    SalesVec salesvec5(move(sales5));

    DailySale dailysale41(d1, 2490);
    DailySale dailysale42(d2, 3760);
    DailySale dailysale43(d3, 4320);
    DailySale dailysale44(d4, 3170);
    DailySale dailysale45(d5, 2870);
    DailySale dailysale46(d6, 1980);
    DailySale dailysale47(d7, 4020);
    DailySale dailysale48(d8, 1640);

    std::vector<DailySale> sales6 = {dailysale41, dailysale42, dailysale43, dailysale44,
                                     dailysale45, dailysale46, dailysale47, dailysale48};

    DailySale dailysale49(d1, 4620);
    DailySale dailysale50(d2, 3180);
    DailySale dailysale51(d3, 5070);
    DailySale dailysale52(d4, 2590);
    DailySale dailysale53(d5, 6430);
    DailySale dailysale54(d6, 3850);
    DailySale dailysale55(d7, 7120);
    DailySale dailysale56(d8, 1940);

    std::vector<DailySale> sales7 = {dailysale49, dailysale50, dailysale51, dailysale52,
                                     dailysale53, dailysale54, dailysale55, dailysale56};

    DailySale dailysale57(d1, 3890);
    DailySale dailysale58(d2, 2530);
    DailySale dailysale59(d3, 4620);
    DailySale dailysale60(d4, 2140);
    DailySale dailysale61(d5, 5890);
    DailySale dailysale62(d6, 3270);
    DailySale dailysale63(d7, 6780);
    DailySale dailysale64(d8, 1750);

    std::vector<DailySale> sales8 = {dailysale57, dailysale58, dailysale59, dailysale60,
                                     dailysale61, dailysale62, dailysale63, dailysale64};

    DailySale dailysale65(d1, 4250);
    DailySale dailysale66(d2, 2910);
    DailySale dailysale67(d3, 4890);
    DailySale dailysale68(d4, 2420);
    DailySale dailysale69(d5, 6070);
    DailySale dailysale70(d6, 3450);
    DailySale dailysale71(d7, 6940);
    DailySale dailysale72(d8, 1910);

    std::vector<DailySale> sales9 = {dailysale65, dailysale66, dailysale67, dailysale68,
                                     dailysale69, dailysale70, dailysale71, dailysale72};

    DailySale dailysale73(d1, 3980);
    DailySale dailysale74(d2, 2570);
    DailySale dailysale75(d3, 4720);
    DailySale dailysale76(d4, 2250);
    DailySale dailysale77(d5, 5840);
    DailySale dailysale78(d6, 3650);
    DailySale dailysale79(d7, 7110);
    DailySale dailysale80(d8, 1780);

    std::vector<DailySale> sales10 = {dailysale73, dailysale74, dailysale75, dailysale76,
                                      dailysale77, dailysale78, dailysale79, dailysale80};

    SalesVec salesvec6(move(sales6));
    SalesVec salesvec7(move(sales7));
    SalesVec salesvec8(move(sales8));
    SalesVec salesvec9(move(sales9));
    SalesVec salesvec10(move(sales10));

    // ratings BST
    std::vector<int> rating1 = {2, 4, 3, 1, 5, 2, 3, 4, 1, 3, 2, 4, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4};
    std::vector<int> rating2 = {5, 4, 4, 5, 2, 3, 1, 4, 3, 5, 1, 2, 4, 5, 3, 1, 2, 4, 5, 3, 1, 2, 4, 5, 3, 1, 2, 4, 5, 3};

    std::vector<int> rating3 = {4, 3, 4, 5, 1, 2, 3, 4, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4};
    std::vector<int> rating4 = {4, 5, 3, 5, 1, 2, 3, 4, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4};

    std::vector<int> rating5 = {2, 5, 3, 4, 1, 4, 2, 3, 5, 1, 3, 2, 4, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4};
    std::vector<int> rating6 = {5, 3, 1, 4, 2, 4, 3, 1, 5, 2, 3, 4, 1, 2, 3, 5, 4, 1, 2, 3, 5, 4, 1, 2, 3, 5, 4, 1, 2, 3, 5};

    std::vector<int> rating7 = {4, 1, 5, 3, 2, 1, 3, 5, 4, 2, 1, 3, 5, 4, 2, 1, 3, 5, 4, 2, 1, 3, 5, 4, 2, 1, 3, 5, 4, 2, 1};
    std::vector<int> rating8 = {2, 3, 5, 1, 4, 2, 3, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4, 3};

    std::vector<int> rating9 = {1, 5, 2, 3, 4, 3, 1, 5, 2, 4, 3, 2, 4, 1, 2, 5, 3, 1, 2, 4, 5, 1, 4, 2, 3, 5, 1, 4, 3, 2, 5};
    std::vector<int> rating10 = {4, 2, 5, 3, 1, 4, 2, 3, 1, 5, 2, 3, 4, 1, 2, 3, 5, 4, 1, 2, 3, 5, 4, 1, 2, 3, 5, 4, 1, 2, 3};

    std::vector<int> rating11 = {3, 1, 4, 2, 5, 1, 3, 2, 4, 5, 3, 1, 2, 4, 5, 3, 1, 2, 4, 5, 3, 1, 2, 4, 5, 3, 1, 2, 4, 5, 3};
    std::vector<int> rating12 = {2, 3, 5, 1, 4, 2, 3, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4, 3};

    std::vector<int> rating13 = {3, 1, 5, 2, 4, 3, 1, 5, 2, 4, 1, 3, 5, 2, 4, 1, 3, 5, 2, 4, 1, 3, 5, 2, 4, 1, 3, 5, 2, 4, 1};
    std::vector<int> rating14 = {4, 2, 1, 5, 3, 4, 2, 1, 5, 3, 2, 4, 1, 3, 5, 2, 4, 1, 3, 5, 2, 4, 1, 3, 5, 2, 4, 1, 3, 5, 2};

    std::vector<int> rating15 = {2, 3, 4, 1, 5, 2, 4, 1, 3, 5, 2, 4, 1, 3, 5, 2, 4, 1, 3, 5, 2, 4, 1, 3, 5, 2, 4, 1, 3, 5, 2};
    std::vector<int> rating16 = {5, 1, 3, 2, 4, 5, 1, 3, 2, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4, 3, 2, 5, 1, 4, 3};

    std::vector<int> rating17 = {3, 2, 4, 1, 5, 2, 3, 1, 4, 5, 2, 1, 3, 4, 5, 2, 3, 1, 4, 5, 3, 1, 2, 4, 5, 3, 2, 1, 4, 5, 3};
    std::vector<int> rating18 = {4, 1, 5, 3, 2, 1, 3, 4, 5, 2, 1, 3, 4, 5, 3, 1, 2, 4, 5, 3, 2, 1, 4, 5, 3, 2, 1, 4, 5, 3, 1};

    std::vector<int> rating19 = {2, 4, 1, 5, 3, 2, 1, 4, 5, 3, 2, 1, 4, 5, 3, 1, 2, 4, 5, 3, 1, 2, 4, 5, 3, 1, 2, 4, 5, 3, 2};
    std::vector<int> rating20 = {5, 3, 2, 1, 4, 5, 3, 2, 1, 4, 5, 3, 1, 2, 4, 5, 3, 1, 2, 4, 5, 3, 1, 2, 4, 5, 3, 1, 2, 4, 5};


    MonthlyRating monthRating1(1,2023,rating1);
    MonthlyRating monthRating2(2,2023,rating2);
    MonthlyRating monthRating3(1,2023,rating3);
    MonthlyRating monthRating4(2,2023,rating4);
    MonthlyRating monthRating5(1,2023,rating5);
    MonthlyRating monthRating6(2,2023,rating6);
    MonthlyRating monthRating7(1,2023,rating7);
    MonthlyRating monthRating8(2,2023,rating8);
    MonthlyRating monthRating9(1,2023,rating9);
    MonthlyRating monthRating10(2,2023,rating10);
    MonthlyRating monthRating11(1,2023,rating11);
    MonthlyRating monthRating12(2,2023,rating12);
    MonthlyRating monthRating13(1,2023,rating13);
    MonthlyRating monthRating14(2,2023,rating14);
    MonthlyRating monthRating15(1,2023,rating15);
    MonthlyRating monthRating16(2,2023,rating16);
    MonthlyRating monthRating17(1,2023,rating17);
    MonthlyRating monthRating18(2,2023,rating18);
    MonthlyRating monthRating19(1,2023,rating19);
    MonthlyRating monthRating20(2,2023,rating20);
    
    ratingsBST ratingBST1;
    ratingBST1.insertRating(monthRating1);
    ratingBST1.insertRating(monthRating2);
    ratingsBST ratingBST2;
    ratingBST2.insertRating(monthRating3);
    ratingBST2.insertRating(monthRating4);
    ratingsBST ratingBST3;
    ratingBST3.insertRating(monthRating5);
    ratingBST3.insertRating(monthRating6);
    ratingsBST ratingBST4;
    ratingBST4.insertRating(monthRating7);
    ratingBST4.insertRating(monthRating8);
    ratingsBST ratingBST5;
    ratingBST5.insertRating(monthRating9);
    ratingBST5.insertRating(monthRating10);
    ratingsBST ratingBST6;
    ratingBST6.insertRating(monthRating11);
    ratingBST6.insertRating(monthRating12);
    ratingsBST ratingBST7;
    ratingBST7.insertRating(monthRating13);
    ratingBST7.insertRating(monthRating14);
    ratingsBST ratingBST8;
    ratingBST8.insertRating(monthRating15);
    ratingBST8.insertRating(monthRating16);
    ratingsBST ratingBST9;
    ratingBST9.insertRating(monthRating17);
    ratingBST9.insertRating(monthRating18);
    ratingsBST ratingBST10;
    ratingBST10.insertRating(monthRating19);
    ratingBST10.insertRating(monthRating20);

    Cuisine cuisine1(ALGERIAN,salesvec1,ratingBST1);
    Cuisine cuisine2(SYRIAN,salesvec2,ratingBST2);
    Cuisine cuisine3(CHINESE,salesvec3,ratingBST3);
    Cuisine cuisine4(INDIAN,salesvec4,ratingBST4);
    Cuisine cuisine5(EUROPEAN,salesvec5,ratingBST5);
    Cuisine cuisine6(ALGERIAN,salesvec6,ratingBST6);
    Cuisine cuisine7(SYRIAN,salesvec7,ratingBST7);
    Cuisine cuisine8(CHINESE,salesvec8,ratingBST8);
    Cuisine cuisine9(INDIAN,salesvec9,ratingBST9);
    Cuisine cuisine10(EUROPEAN,salesvec10,ratingBST10);

    Cuisine cuisines1[5]={cuisine1,cuisine2,cuisine3,cuisine4,cuisine5};
    Cuisine cuisines2[5]={cuisine6,cuisine7,cuisine8,cuisine9,cuisine10};
    Restaurant restaurant1(3106100002,31,OWNED,"Gourmet Delight","Oran","Arzew",
    "Algeria",costsvec1,cuisine1,cuisine2,cuisine3,cuisine4,cuisine5);
    Restaurant restaurant2(1621131201,40,FRANCHISED,"Rustic Roots","Alger",
    "Bab Ezzouar","Algeria",costsvec2,cuisine6,cuisine7,cuisine8,cuisine9,cuisine10);

    cout<<"the total sales for restaurant 1:"<<restaurant1.totalSalesOnMonth(1,2023)<<endl;
    cout<<"the total sales for restaurant 2:"<<restaurant2.totalSalesOnMonth(1,2023)<<endl;

    cout<<"the total costs for restaurant 1:"<<restaurant1.totalCostOnmonth(1,2023)<<endl;
    cout<<"the total costs for restaurant 2:"<<restaurant2.totalCostOnmonth(1,2023)<<endl;
    RestaurantHashTable table1;
    table1.insert(restaurant1);
    table1.insert(restaurant2);

    cout<<"the total sales in the coutry: "<<table1.totalSalesInCountry("Algeria",1,2023)<<endl;
 
}
*/