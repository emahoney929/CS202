//Ethan Mahoney
//Source file for the Agency Header file
#include <iostream>
#include <fstream>
#include "Agency/Agency.h"
#include "my_string/my_string.h"

using namespace std;

Agency::Agency()
{
    myStringCopy(m_name, "\0");
    m_zipcode = 0;
}

char *Agency::getName()
{
    return m_name;
}

int Agency::getZipcode()
{
    return m_zipcode;
}

Car *Agency::getInventory()
{
    return m_inventory;
}

void Agency::setName(const char *name)
{
    myStringCopy(m_name, name);
}

void Agency::setZipcode(const int zipcode)
{
    m_zipcode = zipcode;
}

//Member function to read all the agency data from the file
void Agency::readAllData()
{
    ifstream infile;
    Car *cars = m_inventory;
    char name[100];

    cout << "\nPlease enter a name of a file: ";
    cin >> name;

    cout << endl;

    infile.open(name);

    if(infile)
    {
        infile >> m_name;
        infile >> m_zipcode;

	for(int i = 0; i < CAR_AMT; i++)
        {
            infile >> *cars;
            cars->updatePrice();
            cars++;
        }
        
    }
    else
    {
        cout << "File does not exist" << endl;
    }
}

//Member function to print the agency name and zipcode
void Agency::printData()
{     
    cout << endl << m_name << " " << m_zipcode << endl;

    printActiveSensors();
    printAllCars();
}
    
//Member function to print out all the active sensors in use by cars
void Agency::printActiveSensors()
{
    Car *cars = m_inventory;
    Sensor *sensor;
    char *type;
    int gps_cnt = 0;
    int camera_cnt = 0;
    int lidar_cnt = 0;
    int radar_cnt = 0; 

    for(int i = 0; i < CAR_AMT; i++)
    {
        sensor = cars->getSensors();

        for(int j = 0; j < SENSORAMT; j++)
        {
            type = sensor->getType();

            if(!myStringCompare(type, "gps"))
            {
                gps_cnt++;
               sensor->setExtracost(GPS_PRICE);
            }
            else if(!myStringCompare(type, "camera"))
            {
                camera_cnt++;
                sensor->setExtracost(CAMERA_PRICE);
            }
            else if(!myStringCompare(type, "lidar"))
            {
                lidar_cnt++;
                sensor->setExtracost(LIDAR_PRICE);
            }
            else if(!myStringCompare(type, "radar"))
            {
                radar_cnt++;
                sensor->setExtracost(RADAR_PRICE);
            }
            else if(!myStringCompare(type, "NONE"))
            {
                sensor->setExtracost(NONE);
            }
            sensor++;
            
        }
        cars->updatePrice();
        cars++;
    }
    cout << "\nActive sensors: {gps}: " << gps_cnt << " {camera}: " << camera_cnt;
    cout << " {lidar}: " << lidar_cnt << " {radar}: " << radar_cnt << endl << endl;
}

//Member function to print out all available cars to the screen.
void Agency::printAllCars()
{
    Car *cars = m_inventory;

    for(int i = 0; i < CAR_AMT; i++)
    {
        cout << "[" << i+1 << "] ";
        cars->print();
        cout << endl << endl;
        cars++;
    } 
}

//Member function to print all the available cars
void Agency::printAvailableCars()
{
    Car *cars = m_inventory;
    
    for(int i = 0; i < CAR_AMT; i++)
    {
        if(cars->getAvailable())
        {
            cout << "[" << i+1 << "] ";
            cars->print();
            cout << endl << endl;   
        }
        cars++;
    } 
}

//Operator overloading to return car index.
Car & Agency::operator [](int index)
{
    return m_inventory[index];
}

