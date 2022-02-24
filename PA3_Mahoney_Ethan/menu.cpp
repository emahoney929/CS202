//Ethan Mahoney
//CS202
//File contains implementations to the functions declared in the header file
#include <iostream>
#include <fstream>
#include "RentalCar.h"
#include "menu.h"

int const AGENCY_SIZE = 3;

using namespace std;

RentalAgency agencies[AGENCY_SIZE];

//Function creates the main menu for the entire program
void userMenuPrompt()
{
    int userInput;
    RentalAgency *agency_ptr;

    do
    {
        cout << "Car Rental!!!\n" << "==================" << endl;
        cout << "1. Save Car Information From File" << endl;
        cout << "2. Display Car Information" << endl;
        cout << "3. Estimate Cost" << endl;
        cout << "4. Find Cheapest Rental" << endl; 
        cout << "5. Reserve A Car" << endl;
        cout << "6. EXIT" << endl;
        cout << "\nEnter an option: ";
        cin >> userInput;
         
  
        switch (userInput) //Calls each supporting function for each option chosen
        {
            case 1:
               readCars(agencies);
               break;
        
            case 2:
               agency_ptr = agencies;

               for(int count = 0; count < AGENCY_SIZE; count++) //Iterates through each agency
               {
                   printAgenciesToTerminal(agency_ptr);
                   agency_ptr++;
               }
               break;

            case 3:
               estimateRentalCost(agencies);
               break;

            case 4:
               findCheapestRental(agencies);
               break;

            case 5:
               reserveCar(agencies);
               break;
            
            case 6:
               break;

            default:
               cout << "\nPlease try again." << endl << endl;
               break;
        }
    } while (userInput != 6);
}

//Function takes the input from the file and reads all of it into each struct(agency)
void readCars(RentalAgency *agency)
{
    ifstream infile;
    char input[MAX_STR_SIZE];
    

    cout << "\nEnter an input file: ";
    cin >> input;

    cout << endl;
    
    infile.open(input);
    
    if(infile)
    {
        for(int i = 0; i < AGENCY_SIZE; i++)
        {
            *agency = readToStruct(infile); //Reads all the information into each struct then increments them
            agency++;
        }
    }
    else
    {
        cout << "Cannot open file\n" << endl;
    }

    infile.close();
}

//Function reads the information to a temporary struct then sends that struct to the agency struct
RentalAgency readToStruct(ifstream &file)
{
    RentalAgency tempStruct;
    RentalCar *temp_inventory = tempStruct.inventory;
    char *AgencyNames = tempStruct.name;
    char tempNames[MAX_STR_SIZE];
    char *temp_ptr;
    int year;
    char model[MAX_SIZE];
    char make[MAX_SIZE];
    float price;
    bool available;

//Reads in each Agency Name  
    file >> tempNames;

    temp_ptr = tempNames;
    
    while(*temp_ptr != '\0')
    {
        *AgencyNames = *temp_ptr;
        AgencyNames++;
        temp_ptr++;
    }
    
    *AgencyNames = '\0';
        
//Reads the zipcode
    readZipcode(file, tempStruct.zipcode);

//Reads in information for each car
    for(int index = 0; index < INVENTORY_SPACE; index++)
    {
        file >> year >> make >> model >> price >> available;
        temp_inventory->setYear(year);
        temp_inventory->setMake(make);
        temp_inventory->setModel(model);
        temp_inventory->setPrice(price);
        temp_inventory->setAvailability(available);

        temp_inventory++;
    }

    return tempStruct;
}

//Function reads each zipcode from the file and breaks it down by each number for the array
void readZipcode(ifstream &input, int *zip_ptr)
{
    int zip;
    int temp;

    input >> zip;
    
    while(zip != 0)
    {
        temp = zip;
        temp %= 10;
        *zip_ptr = temp;
        zip_ptr++;
        zip /= 10;
    }
}

//Function iterates through every element in each struct member in order to print to the screen
void const printAgenciesToTerminal(RentalAgency *agency)
{
    int *agency_zip = agency->zipcode + ZIP_LENGTH - 1;
    RentalCar *temp_cars = agency->inventory;
    char *agent_name = agency->name;

    cout << endl;

    while(*agent_name != '\0') //Prints Agency names to the screen
    {
        cout << *agent_name;
        agent_name++;
    }

    cout << " ";

    for(int i = 0; i < ZIP_LENGTH; i++) //Prints Agency zipcodes to the screen
    {
        cout << *agency_zip;
        agency_zip--;
    }
     
    cout << "\n" << endl;

    for(int count = 0; count < INVENTORY_SPACE; count++) //Prints Car info to the screen
    {
        temp_cars->print();
        temp_cars++;
    }

    cout << endl;
}

//Function estimates the cost of a car per daily renting
void estimateRentalCost(RentalAgency *agencies)
{
    RentalAgency *Agency = agencies;
    int agent;
    int car;
    int days;

    cout << "What agency would you like to rent from?\n" << endl;

    for(int amount = 0; amount < AGENCY_SIZE; amount++)
    {
        cout << "[" << (amount + 1) << "]:" << " " << Agency->name << endl << endl;
        Agency++;
    }

    cout << "\n";
    cin >> agent;
    
    if(agent < 1 || agent > 3)
    {
        while(agent < 1 || agent > 3)
        {
            cout << "Please try again\n" << endl;
            cin >> agent;
        }
    }

    agent -= 1;

    Agency = (agencies) + agent;

    RentalCar *carClass = Agency->inventory;

    cout << "\nWhich car would you like?\n" << endl;

    for(int i = 0; i < INVENTORY_SPACE; i++)
    {
        cout << "[" << (i + 1) << "]:" << " ";
        carClass->print(); 
        cout << endl;
        carClass++;
    }

    cin >> car;

    if(car < 1 || car > 5)
    {
        while(car < 1 || car > 5)
        {
            cout << "Please try again\n" << endl;
            cin >> car;
        }
    }

    car -= 1;


    carClass = (Agency->inventory) + car;


    cout << "\nHow many days would you like to rent the car?\n" << endl;
    cin >> days;

    carClass->estimateCost(days);
    cout << endl;
}

//Function takes the rental struct and goes through each agency and their inventory to find the cheapest car
void findCheapestRental(RentalAgency *agencies)
{
    RentalCar *tempCar2 = agencies->inventory;
    RentalCar tempCar = *agencies->inventory;
    tempCar2++;

    for(int i = 0; i < AGENCY_SIZE; i++)
    {
        tempCar2 = agencies->inventory;
        for(int j = 0; j < INVENTORY_SPACE; j++)
        {
            if(tempCar.getPrice() > tempCar2->getPrice() && tempCar2->getAvailability())
            {
                tempCar = *tempCar2;
            }
            tempCar2++;   
        }
        agencies++;
    }
    
    cout << endl;

    tempCar.print();

    cout << endl;
}

//Function prompts the user to choose a rental car then displays the final cost
void reserveCar(RentalAgency *agencies)
{
    RentalAgency *CarAgency = agencies;
    int agent;
    int car;

    cout << "What agency would you like to rent from?\n" << endl;

    for(int i = 0; i < AGENCY_SIZE; i++)
    {
        cout << "[" << (i + 1) << "]:" << " " << CarAgency->name << endl << endl;
        CarAgency++;
    }

    cout << "\n";
    cin >> agent;
    
    if(agent < 1 || agent > 3) //Checks to see if the user input is within range or display error message
    {
        while(agent < 1 || agent > 3)
        {
            cout << "Please try again\n" << endl;
            cin >> agent;
        }
    }

    agent -= 1;

    CarAgency = (agencies) + agent;

    RentalCar *Car = CarAgency->inventory;

    cout << "Which car would you like?\n" << endl;

    for(int i = 0; i < INVENTORY_SPACE; i++) 
    {
        cout << "[" << (i + 1) << "]:" << " ";
        Car->print(); 
        cout << endl;
        Car++;
    }

    cin >> car;

    if(car < 1 || car > 5)  //Checks to see if the user input is within range
    {
        while(car < 1 || car > 5)
        {
            cout << "Please try again\n" << endl;
            cin >> car;
        }
    }

    car -= 1;


    Car = (CarAgency->inventory) + car;

    if(Car->getAvailability()) //Checks for car availability
    {
        cout << endl;
        Car->setAvailability(false);
        cout << "Thank you for your purchase of the: " << Car->getYear() << " " 
        << Car->getMake() << " " << Car->getModel() << endl << endl;
    }
    else
    {
        cout << "Sorry that car is not available.\n" << endl; //Displays error message for unavailable cars
    }
}
