//Ethan Mahoney
//Function implementations for the Rental Car header file
#include <iostream>
#include "my_string.h"
#include "RentalCar.h"

using namespace std;

RentalCar::RentalCar()
{
    m_year = 0000;
    myStringCopy(m_make, "MAKE");
    myStringCopy(m_model, "MODEL");
    m_price = 0000;
    m_available = false;
}

RentalCar::RentalCar(int year, char *make, char *model, float price, bool available)
{
    m_year = year;
    myStringCopy(m_make, make);
    myStringCopy(m_model, model);
    m_price = price;
    m_available = available;
}

int RentalCar::getYear()
{
    return m_year;
}

char *RentalCar::getMake()
{
    return m_make;
}

char *RentalCar::getModel()
{
    return m_model;
}

float RentalCar::getPrice()
{
    return m_price;
}
 
bool RentalCar::getAvailability()
{
    return m_available;
}

void RentalCar::setYear(int year)
{
    m_year = year;
}

void RentalCar::setMake(char *make)
{
    myStringCopy(m_make, make);
}

void RentalCar::setModel(char *model)
{
    myStringCopy(m_model, model);
}

void RentalCar::setPrice(float price)
{
    m_price = price;
}

void RentalCar::setAvailability(bool available)
{
    m_available = available;
}

void RentalCar::print()
{
    cout << m_year << " " << m_make << " " << m_model << ", $" << m_price << " per day, Available: " << boolalpha << m_available << endl;
}

void RentalCar::estimateCost(int &dayAmt)
{
    cout << "\nTotal cost: $" << m_price*dayAmt << endl;
}
    
