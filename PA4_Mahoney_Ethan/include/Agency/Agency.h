#ifndef AGENCY_H_
#define AGENCY_H_

#include "Car/Car.h"

using namespace std;

class Agency
{
    

    public:
       Agency();
       
       char *getName();
       int getZipcode();
       Car *getInventory();

       void setName(const char *name);
       void setZipcode(const int zipcode);

       void readAllData();
       void printData();
       void printActiveSensors();
       void printAllCars();
       void printAvailableCars();
       Car & operator [](int index);

    private:
       char m_name[256];
       int m_zipcode;
       Car m_inventory[CAR_AMT];
};

#endif
