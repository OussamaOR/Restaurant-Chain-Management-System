#include "../Header Files/RestaurantHashTable.h"
#include "../Header Files/readfiles.h"
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
                Restaurants.displayRestaurant(id);
            }
            else if(j == '2'){
                cout << "Enter The District Name  " << endl;
                string distr;
                cin >> distr;
                Restaurants.displayAllRestaurantsInDistrict(distr);
            }
            else if(j == '3'){
                cout << "Enter The Wilaya Name " << endl;
                string wilaya;
                cin >> wilaya;
                Restaurants.displayAllRestaurantsInWilaya(wilaya);
            }
            else if(j == '4'){
                cout << "Enter The Country Name " << endl;
                string ctry;
                cin >> ctry;
                Restaurants.displayAllRestaurantsInCountry(ctry);
            }
            else if(j == '5'){
                Restaurants.displayAllRestaurants();
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

            Restaurants.printRestaurantSales(id,month,year);
        }
        else if(j =='2'){
            cout << "Enter The District Name " << endl;
            string distr;
            cin >> distr;
            
            cout << "Enter The Month And The Year " << endl;
            int month,year;
            cin >> month >> year;
            Restaurants.printRestaurantSalesInDistrict(distr,month,year);
        }
        else if(j =='3'){
            cout << "Enter The Wilaya Name " << endl;
            string wiliya;
            cin >> wiliya;
            cout << "Enter The Month And The Year " << endl;
            int month,year;
            cin >> month >> year;
            Restaurants.printRestaurantSalesInWilaya(wiliya,month,year);
        }
        else if(j =='4'){
            cout << "Enter The Country Name " << endl;
            string ctr;
            cin >> ctr;
            cout << "Enter The Month And The Year " << endl;
            int month,year;
            cin >> month >> year;
            Restaurants.printRestaurantSalesInCountry(ctr,month,year);
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
            cin >> distr;
            
            cout << "Enter The Month And The Year " << endl;
            int month,year;
            cin >> month >> year;
            Restaurants.printFiveCuisinesWinnersInDistrict(distr,month,year);
        }
        else if(j =='2'){
            cout << "Enter The Wilaya Name " << endl;
            string wiliya;
            cin >> wiliya;
            cout << "Enter The Month And The Year " << endl;
            int month,year;
            cin >> month >> year;
            Restaurants.printFiveCuisinesWinnersInWilaya(wiliya,month,year);
        }
        else if(j =='3'){
            cout << "Enter The Country Name " << endl;
            string ctr;
            cin >> ctr;
            cout << "Enter The Month And The Year " << endl;
            int month,year;
            cin >> month >> year;
            Restaurants.printFiveCuisinesWinnersInCountry(ctr,month,year);
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

            Restaurants.printMonthlySalesToPublicity(id,month,year);
        }
        else if(j =='2'){
            cout << "Enter The District Name " << endl;
            string distr;
            cin >> distr;
            
            cout << "Enter The Month And The Year " << endl;
            int month,year;
            cin >> month >> year;
            Restaurants.printMonthlySalesToPublicityInDistrict(distr,month,year);
        }
        else if(j =='3'){
            cout << "Enter The Wilaya Name " << endl;
            string wiliya;
            cin >> wiliya;
            cout << "Enter The Month And The Year " << endl;
            int month,year;
            cin >> month >> year;
            Restaurants.printMonthlySalesToPublicityInWilaya(wiliya,month,year);
        }
        else if(j =='4'){
            cout << "Enter The Country Name " << endl;
            string ctr;
            cin >> ctr;
            cout << "Enter The Month And The Year " << endl;
            int month,year;
            cin >> month >> year;
            Restaurants.printMonthlySalesToPublicityInCountry(ctr,month,year);
        }
      }
     
    } while (i != '5');
    
    


}