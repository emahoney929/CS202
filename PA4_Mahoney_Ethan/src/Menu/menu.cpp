//Ethan Mahoney
//Source file that holds the bulk of the menu displayed
#include <iostream>
#include <fstream>
#include "Menu/menu.h"
#include "Agency/Agency.h"
#include "Car/Car.h"
#include "my_string/my_string.h"

using namespace std;
   
//User menu that displays options to the user
void userMenuPrompt()
{
    int userInput;
    Agency rentalAgency;

    do
    {
        cout << "Car Rental!!!\n" << "==================" << endl;
        cout << "1. Save Car Information From File" << endl;
        cout << "2. Display All Cars" << endl;
        cout << "3. Display Available Cars" << endl;
        cout << "4. Reserve A Car" << endl;
        cout << "5. EXIT" << endl;
        cout << "\nEnter an option: ";
        cin >> userInput;
         
  
        switch (userInput) //Calls each supporting function for each option chosen
        {
            case 1:
               readIn(rentalAgency);
               break;
        
            case 2:
               printAll(rentalAgency);
               break;

            case 3:
               printFiltered(rentalAgency);
               break;

            case 4:
               reserveOne(rentalAgency);
               break;
            
            case 5:
               break;

            default:
               cout << "\nPlease try again." << endl << endl;
               break;
        }
    } while (userInput != 5);
}

//Function calls on the read function from the agency class to read from file
void readIn(Agency& agency)
{
    agency.readAllData();
}

//Function calls on another agency function to print all data
void const printAll(Agency& agency)
{
    agency.printData();
}

//Function prints all the cars that are available to reserve
void const printFiltered(Agency& agency)
{
    agency.printActiveSensors();
    agency.printAvailableCars();
}

//Function prompts the user to reserve a car and enter a name for the lessee
void reserveOne(Agency &agency)
{
    int days;
    int carChoice;
    char lessee[100];

    agency.printAvailableCars();

    cout << "Which car would you like to reserve?" << endl;
    cin >> carChoice;

    carChoice -= 1;
    
    while(!agency[carChoice].getAvailable())
    {
        cout << "\nSorry that car is unavailable, please try again." << endl;
        cin >> carChoice;
        carChoice--;
    }

    cout << "\nWhat is the name of the lessee?" << endl;
    cin >> lessee;
 
    agency[carChoice].setOwner(lessee);

    cout << "\nHow many days would you like to rent the car?" << endl;
    cin >> days;

    cout << endl;

    agency[carChoice].estimateCost(days);

    cout << endl << endl;
}
