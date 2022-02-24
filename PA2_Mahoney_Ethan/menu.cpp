//Ethan Mahoney
//CS202
//Menu file which holds the impementations of the menu header file

#include <iostream>
#include <fstream>
#include "menu.h"
#include "my_string.h"

using namespace std;

CarInfo rentalCars[TOTAL_CARS];

//Function creates car rental menu and prompts user for choice
   void userMenuPrompt()
   {
       int userInput;

       do
       {
           cout << "Car Rental!!!\n" << "==================" << endl;
           cout << "1. Save Car Information From File" << endl;
           cout << "2. Display Car Information" << endl;
           cout << "3. Store Car Information In File" << endl;
           cout << "4. Sort Car Prices" << endl; 
           cout << "5. Rent A Car" << endl;
           cout << "6. Reserve A Car" << endl;
           cout << "7. EXIT" << endl;
           cout << "\nEnter an option: ";
           cin >> userInput;
           
           switch (userInput)
           {
               case 1:
                  readCars(rentalCars);
                  break;
        
               case 2:
                  printCarsToTerminal(rentalCars);
                  break;

               case 3:
                  printCarsToFile(rentalCars);
                  break;

               case 4:
                  sortCarsByPrice(rentalCars);
                  break;

               case 5:
                  rentalCarQuery(rentalCars);
                  break;

               case 6:
                  rentalCarReserve(rentalCars);
                  break;

               case 7:
                  break;
        
               default:
                  cout << "\nPlease try again." << endl << endl;
                  break;
           }
       } while (userInput != 7);
   }

//Function takes information from inputted file and puts data in correct structures
   void readCars(CarInfo rentalCars[])
   {
       char input[100];
       ifstream infile;
       int index = 0;

       cout << "\nEnter an  file name: ";
       cin >> input;
       cout << endl;
    
       infile.open(input);

       if(infile)
       {
           while (!infile.eof())
           {
               infile >> rentalCars[index].year >> rentalCars[index].make 
               >> rentalCars[index].model >> rentalCars[index].price >> rentalCars[index].available;
               index++;
           }
       }
       else
       {
           cout << "\nCannot open user file." << endl;
           cout << endl;
       }
       infile.close();
   }

//Function takes contents from structures and displays them to the screen
   void printCarsToTerminal(CarInfo rentalCars[])
   {
       for(int i = 0; i < TOTAL_CARS; i++)
       {
           cout << "\n[" << i << "] " << rentalCars[i].year << " " << rentalCars[i].make << " " << rentalCars[i].model 
           << ", $" << rentalCars[i].price << " per day, Available:" << boolalpha << rentalCars[i].available << endl;
       }
       cout << endl;
   }

//Function takes contents of structures and displays the information to a inputted output file
   void printCarsToFile(CarInfo rentalCars[])
   {
       char output[100];
       ofstream outfile;

       cout << "\nEnter an output file name: ";
       cin >> output;

       outfile.open(output);

       if(outfile)
       {
           for(int i = 0; i < TOTAL_CARS; i++)
           {
               outfile << rentalCars[i].year << " " << rentalCars[i].make << " " <<
               rentalCars[i].model << " " << rentalCars[i].price << " " << boolalpha << rentalCars[i].available << endl;
           }
        }
        else
        {
            cout << "Cannot open user file." << endl;
        }
        outfile.close();
        cout << endl;
   }

//Function bubble sorts structs of car information depending on car price (ascending order)
   void sortCarsByPrice(CarInfo rentalCars[])
   {
       CarInfo tempCars;
       for(int index = 0; index < TOTAL_CARS - 1; index++)
       {
           for(int index2 = 0; index2 < TOTAL_CARS - index - 1; index2++)
           {
               if(rentalCars[index2].price > rentalCars[index2+1].price)
               {
                   tempCars = rentalCars[index2];
                   rentalCars[index2] = rentalCars[index2+1];
                   rentalCars[index2+1] = tempCars;
               }
           }
       }
       cout << endl;
   }

//Function prompts user for days of rental then calculates the price and displays results to screen
   void rentalCarQuery(CarInfo rentalCars[])
   {
       int rentalDays;

       cout << "\nHow many days would you like to rent a car?" << endl;
       cin >> rentalDays;

       sortCarsByPrice(rentalCars);

       for(int i = 0; i < TOTAL_CARS; i++)
       {
           if (rentalCars[i].available)
           {
               cout << "[" << i << "]: " << rentalCars[i].year << " " << rentalCars[i].make << " ";
               cout << rentalCars[i].model << ", Total Cost: $" << (rentalCars[i].price * rentalDays) << endl << endl; 
           }
       }
       cout << endl;
   }

//Function prompts user to select available cars for rental then switches availability of said car
   void rentalCarReserve(CarInfo rentalCars[])
   {
       int carChoice;
       int dayAmt;

       cout << "\nWhich car would you like to rent?" << endl;
       cin >> carChoice;

       if(!rentalCars[carChoice].available)
       {
           cout << "\nSorry that car is not available." << endl;
       }
       else
       {
           cout << "\nHow many days would you like to rent for?" << endl;
           cin >> dayAmt;

           rentalCars[carChoice].available = false;
           cout << "\nThank you for your purchase of the " << rentalCars[carChoice].make << " ";
           cout << rentalCars[carChoice].model << "! Total cost is $" << (rentalCars[carChoice].price*dayAmt) << endl;
       }
       cout << endl;
   }
