//Ethan Mahoney
//Header file that contains the struct used in other files
#ifndef AGENCY_H_
#define AGENCY_H_

#include "RentalCar.h"

int const MAX_SIZE = 256;
int const ZIP_LENGTH = 5;
int const INVENTORY_SPACE = 5;

struct RentalAgency 
{
    char name[MAX_SIZE];
    int zipcode[ZIP_LENGTH];
    RentalCar inventory[INVENTORY_SPACE];
};

#endif
    
    
    
