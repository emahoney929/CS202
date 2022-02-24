//Ethan Mahoney
//CS202
//Header file which contains the car struct and prototypes of the menu file
#ifndef MENU_H_
#define MENU_H_


int const MAX_SIZE = 11;
int const TOTAL_CARS = 5;

struct CarInfo
{
    int year;
    char make[MAX_SIZE];
    char model[MAX_SIZE];
    float price;
    bool available;
};


void userMenuPrompt();
void readCars(CarInfo rentalCars[]);
void printCarsToTerminal(CarInfo rentalCars[]);
void printCarsToFile(CarInfo rentalCars[]);
void sortCarsByPrice(CarInfo rentalCars[]);
void rentalCarQuery(CarInfo rentalCars[]);
void rentalCarReserve(CarInfo rentalCars[]);

#endif
