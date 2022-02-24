//Ethan Mahoney
//Source file that includes the implementations to the Car Header file
#include <iostream>
#include <fstream>
#include "Sensor/Sensor.h"
#include "Car/Car.h"
#include "my_string/my_string.h"

using namespace std;


Car::Car()
{
    m_year = 0;
    myStringCopy(m_make, "\0");
    myStringCopy(m_model, "\0");
    m_sensorcount = 0;
    m_baseprice = 0.00;
    m_finalprice = 0.00;
    m_available = 0;
    myStringCopy(m_owner, "\0");
}

Car::Car(int year, char *make, char *model, Sensor *sensors, int sensorCount, float basePrice, float finalprice, bool available, char *owner)
{
    Sensor *temp = m_sensors;

    m_year = year;
    myStringCopy(m_make, make);
    myStringCopy(m_model, model);

    for(int i = 0; i < SENSORAMT; i++)
    {
        *temp = *sensors;
        temp++;
        sensors++;   
    }
    m_sensorcount = sensorCount;
    m_baseprice = basePrice;
    m_finalprice = finalprice;
    m_available = available;
    myStringCopy(m_owner, owner);
}

Car::Car(const Car &car)
{
    const Sensor *tempSensor = car.m_sensors;
    Sensor *sensor = m_sensors;


    m_year = car.m_year;
    myStringCopy(m_make, car.m_make);
    myStringCopy(m_model, car.m_model);

    for(int i = 0; i < SENSORAMT; i++)
    {
        *sensor = *tempSensor;
        tempSensor++;
        sensor++;
    }

    m_sensorcount = car.m_sensorcount;
    m_baseprice = car.m_baseprice;
    m_finalprice = car.m_finalprice;
    m_available = car.m_available;
    myStringCopy(m_owner, car.m_owner);
}

int Car::getYear()
{
    return m_year;
}
 
char *Car::getMake()
{
    return m_make;
}

char *Car::getModel()
{
    return m_model;
}

Sensor *Car::getSensors()
{
    return m_sensors;
}

int Car::getCount()
{
    return m_sensorcount;
}

float Car::getBaseprice()
{
    return m_baseprice;
}

float Car::getFinalprice()
{
    return m_finalprice;
}

bool Car::getAvailable()
{
    return m_available;
}

char *Car::getOwner()
{
    return m_owner;
}

void Car::setYear(int year)
{
    m_year = year;
}

void Car::setMake(char *make)
{
    myStringCopy(m_make, make);
}

void Car::setModel(char *model)
{
    myStringCopy(m_model, model);
}

void Car::setCount(int sensorCount)
{
    m_sensorcount = sensorCount;
}

void Car::setBaseprice(float basePrice)
{
    m_baseprice = basePrice;
}

void Car::setAvailable(bool available)
{
    m_available = available;
}

void Car::setOwner(char *owner)
{
    myStringCopy(m_owner, owner);
}

void Car::updatePrice()
{
    Sensor *sensorCost = m_sensors;
    float cost = m_baseprice;

    for(int i = 0; i < SENSORAMT; i++)
    {
        cost += sensorCost->getExtracost();
        sensorCost++;
    }
    m_finalprice = cost;
}
    
void Car::print()
{
    Sensor *sensor = m_sensors;
    int count = 0;

    cout << m_year << " " << m_make << " " << m_model << " Base: $" << m_baseprice << " With { ";

    while(count < SENSORAMT)
    {
        if(myStringCompare(sensor->getType(), "NONE") != 0)
        {
            cout << sensor->getType() << " ";
        }
        else
        {
            break;
        }
        sensor++;
        count++;
    }
    cout << "}: $" << m_finalprice << "   Available: " << boolalpha << m_available;
}

void Car::estimateCost(int days)
{
    
    cout << "Thank You " << m_owner << " Final price is: $" << (getFinalprice()*days);
    m_available = false;
}

Car & Car::operator + (Sensor &sensor)
{
    Sensor *ptr = m_sensors;

    for(int count = 0; count < SENSORAMT; count++)
    {
        if(myStringCompare(ptr->getType(), "NONE") == 0)
        {
            ptr->setType(sensor.getType());
            ptr++;
            m_sensorcount++;
            return *this;
        }
       // updatePrice();
    }
    return *this;
}

Car & Car::operator + (char *owner)
{
    if(myStringLength(m_owner) == 0)
    {
        setOwner(owner);
        setAvailable(false);
    }
    return *this;
}

istream & operator >>(istream &inf, Car &car)
{
    char tempLetter;
    char temp[100];
    char *type = temp;
    Sensor *sensor = car.m_sensors;
    bool available;
    

    inf >> car.m_year >> car.m_make >> car.m_model >> car.m_baseprice;

    inf >> tempLetter;
            
            do
            {
                inf >> noskipws >> tempLetter;
                
                if(tempLetter == '}' || tempLetter == ' ')
                {
                    *type = '\0';
                    //cout << temp << endl;

                    sensor->setType(temp);
                    car + *sensor;
                    sensor++;
                    type = temp;
                }
                else
                {
                    *type = tempLetter;
                   // cout << *type << endl;
                    type++;
                }
            }
            while(tempLetter != '}');
                    
            inf >> skipws >> available;
            
            car.setAvailable(available);

            if(!available)
            {
                inf >> temp;
                car.setOwner(temp);
            }
            //car++;
       // }
        return inf;
}
