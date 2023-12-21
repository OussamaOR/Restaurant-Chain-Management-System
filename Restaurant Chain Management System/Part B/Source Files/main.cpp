#include "../Header Files/RestaurantHashTable.h"
#include "../Header Files/readfiles.h"
#include <chrono>
using namespace std::chrono;
int main()
{
    RestaurantHashTable Restaurants;
    readRestaurantCSV("../../Database/restaurant.csv", Restaurants);

    char i,j;

    do
    {
      cout << "Restaurant Chain Management System : " << endl;
      cout << "Please Choose What Type Of Information You Want To Show : " << endl;
      cout << "1. General Informations " << endl;  //displayRestaurant , displayAllRestaurant
      cout << "2. Report on Restaurant Sales" << endl;
      cout << "3. Prize Winners Cuisines" << endl;
      cout << "4. Ratio of the monthly sales to the publicity cost" << endl;
      cout << "5. Exit" << endl;
      cin >> i;

      if(i == '1'){
        cout << "Please Choose What Result You Want To Show " << endl;
        cout << "1. Display The Informations Of A Restaurant " << endl;
        cout << "2. Display The Informations Of All Restaurant In A District" << endl;
        cout << "3. Display The Informations Of All Restaurant In A Wilaya" << endl;
        cout << "4. Display The Informations Of All Restaurant In A Country" << endl;
        cout << "5. Display The Informations Of All Restaurants" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter : ";
         cin >> j;
         
         
        
            if(j == '1'){
                cout << "Enter The ID Of The Restaurant " << endl;
                int id;
                cin >> id;
                auto start = high_resolution_clock::now();
             Restaurants.displayRestaurant(id);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start).count();
            cout << "The Time Taken by the function is : " << duration << " milliseconds" << endl;
               
            }
            else if(j == '2'){
                cout << "Enter The District Name  " << endl;
                string distr;
                getline(cin >> ws,distr);
               auto start = high_resolution_clock::now();
            Restaurants.displayAllRestaurantsInDistrict(distr);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start).count();
            cout << "The Time Taken by the function is : " << duration << " milliseconds" << endl;
                
            }
            else if(j == '3'){
                cout << "Enter The Wilaya Name " << endl;
                string wilaya;
                getline(cin >> ws,wilaya);
                auto start = high_resolution_clock::now();
           Restaurants.displayAllRestaurantsInWilaya(wilaya);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start).count();
            cout << "The Time Taken by the function is : " << duration << " milliseconds" << endl;
                
            }
            else if(j == '4'){
                cout << "Enter The Country Name " << endl;
                string ctry;
                getline(cin >> ws,ctry);
                auto start = high_resolution_clock::now();
            Restaurants.displayAllRestaurantsInCountry(ctry);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start).count();
            cout << "The Time Taken by the function is : " << duration << " milliseconds" << endl;
                
            }
            else if(j == '5'){
                auto start = high_resolution_clock::now();
            Restaurants.displayAllRestaurants();
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start).count();
            cout << "The Time Taken by the function is : " << duration << " milliseconds" << endl;
                
            } 
      }
      else if(i == '2'){
        cout << "Please Choose What Result You Want To Show " << endl;
        cout << "1. Display The Sales Of A Restaurant In Given Month " << endl;
        cout << "2. Display The Sales Of Restaurants In A District " << endl;
        cout << "3. Display The Sales Of Restaurants In A Wilaya " << endl;
        cout << "4. Display The Sales Of Restaurants In A Country " << endl;
        cout << "5. Exit" << endl;
        cin >> j;
        if(j == '1'){
            cout << "Enter The ID Of The Restaurant " << endl;
            int id;
            cin >> id;
            cout << "Enter The Month And The Year " << endl;
            int month,year;
            cin >> month >> year;

            auto start = high_resolution_clock::now();
           Restaurants.printRestaurantSales(id,month,year);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start).count();
            cout << "The Time Taken by the function is : " << duration << " milliseconds" << endl;
            
        }
        else if(j =='2'){
            cout << "Enter The District Name " << endl;
            string distr;
            getline(cin >> ws,distr);
            
            cout << "Enter The Month And The Year " << endl;
            int month,year;
            cin >> month >> year;

            auto start = high_resolution_clock::now();
           Restaurants.printRestaurantSalesInDistrict(distr,month,year);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start).count();
            cout << "The Time Taken by the function is : " << duration << " milliseconds" << endl;
            
        }
        else if(j =='3'){
            cout << "Enter The Wilaya Name " << endl;
            string wilaya;
            getline(cin >> ws,wilaya);
            cout << "Enter The Month And The Year " << endl;
            int month,year;
            cin >> month >> year;

            auto start = high_resolution_clock::now();
             Restaurants.printRestaurantSalesInWilaya(wilaya,month,year);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start).count();
            cout << "The Time Taken by the function is : " << duration << " milliseconds" << endl;
           
        }
        else if(j =='4'){
            cout << "Enter The Country Name " << endl;
            string ctr;
           getline(cin >> ws,ctr);
            cout << "Enter The Month And The Year " << endl;
            int month,year;
            cin >> month >> year;


            auto start = high_resolution_clock::now();
            Restaurants.printRestaurantSalesInCountry(ctr,month,year);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start).count();
            cout << "The Time Taken by the function is : " << duration << " milliseconds" << endl;
            
        }

      }
      else if(i == '3'){
        cout << "Please Choose What Result You Want To Show " << endl;
        cout << "1. Display Five Cuisines Winners In A District " << endl;
        cout << "2. Display Five Cuisines Winners In A Wilaya " << endl;
        cout << "3. Display Five Cuisines Winners In A Country " << endl;
        cout << "4. Exit" << endl;
    cin >> j;

         if(j =='1'){
            cout << "Enter The District Name " << endl;
            string distr;
            getline(cin >> ws,distr);
            
            cout << "Enter The Month And The Year " << endl;
            int month,year;
            cin >> month >> year;

            auto start = high_resolution_clock::now();
            Restaurants.printFiveCuisinesWinnersInDistrict(distr,month,year);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start).count();
            cout << "The Time Taken by the function is : " << duration << " milliseconds" << endl;
            
        }
        else if(j =='2'){
            cout << "Enter The Wilaya Name " << endl;
            string wilaya;
            getline(cin >> ws,wilaya);
            cout << "Enter The Month And The Year " << endl;
            int month,year;
            cin >> month >> year;

            auto start = high_resolution_clock::now();
            Restaurants.printFiveCuisinesWinnersInWilaya(wilaya,month,year);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start).count();
            cout << "The Time Taken by the function is : " << duration << " milliseconds" << endl;
           
        }
        else if(j =='3'){
            cout << "Enter The Country Name " << endl;
            string ctr;
            getline(cin >> ws,ctr);
            cout << "Enter The Month And The Year " << endl;
            int month,year;
            cin >> month >> year;

            auto start = high_resolution_clock::now();
            Restaurants.printFiveCuisinesWinnersInCountry(ctr,month,year);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start).count();
            cout << "The Time Taken by the function is : " << duration << " milliseconds" << endl;
            
        }
      }
      else if(i == '4'){

        cout << "Please Choose What Result You Want To Show " << endl;
        cout << "1. Display Monthly Ratio Of Sales To Publicity Cost For A Restaurant " << endl;
        cout << "2. Display Monthly Ratio Of Sales To Publicity Cost In A District " << endl;
        cout << "3. Display Monthly Ratio Of Sales To Publicity Cost In A Wilaya " << endl;
        cout << "4. Display Monthly Ratio Of Sales To Publicity Cost In A Country " << endl;
        cout << "5. Exit" << endl;
    cin >> j;
        if(j == '1'){
             cout << "Enter The ID Of The Restaurant " << endl;
            int id;
            cin >> id;
            cout << "Enter The Month And The Year " << endl;
            int month,year;
            cin >> month >> year;
            auto start = high_resolution_clock::now();
             Restaurants.printMonthlySalesToPublicity(id,month,year);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start).count();
            cout << "The Time Taken by the function is : " << duration << " milliseconds" << endl;
           
        }
        else if(j =='2'){
            cout << "Enter The District Name " << endl;
            string distr;
            getline(cin >> ws,distr);
            
            cout << "Enter The Month And The Year " << endl;
            int month,year;
            cin >> month >> year;

            auto start = high_resolution_clock::now();
            Restaurants.printMonthlySalesToPublicityInDistrict(distr,month,year);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start).count();
            cout << "The Time Taken by the function is : " << duration << " milliseconds" << endl;
            
        }
        else if(j =='3'){
            cout << "Enter The Wilaya Name " << endl;
            string wilaya;
            getline(cin >> ws,wilaya);
            cout << "Enter The Month And The Year " << endl;
            int month,year;
            cin >> month >> year;

            auto start = high_resolution_clock::now();
            Restaurants.printMonthlySalesToPublicityInWilaya(wilaya,month,year);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start).count();
            cout << "The Time Taken by the function is : " << duration << " milliseconds" << endl;
            
        }
        else if(j =='4'){
            cout << "Enter The Country Name " << endl;
            string ctr;
           getline(cin >> ws,ctr);
            cout << "Enter The Month And The Year " << endl;
            int month,year;
            cin >> month >> year;

            auto start = high_resolution_clock::now();
             Restaurants.printMonthlySalesToPublicityInCountry(ctr,month,year);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start).count();
            cout << "The Time Taken by the function is : " << duration << " milliseconds" << endl;
           
        }
      }
     
    } while (i != '5');
    
    


}