//Ethan Mahoney
//Header file contains prototypes to menu implementations
#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <fstream>
#include "Agency.h"

using namespace std; 

void userMenuPrompt();
void readCars(RentalAgency *agency);
void const printAgenciesToTerminal(RentalAgency *agency);
void estimateRentalCost(RentalAgency *agencies);
void findCheapestRental(RentalAgency *agencies);
void reserveCar(RentalAgency *agencies);
void readZipcode(ifstream &input, int *ptr);
RentalAgency readToStruct(ifstream &file);
#endif

