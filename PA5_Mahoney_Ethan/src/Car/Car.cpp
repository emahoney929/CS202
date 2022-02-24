//Ethan Mahoney CS 202 Proj5
//Implementation file which contains the implementations of the Car class and its member functions
#include <iostream>
#include <cstring>
#include "Car/Car.h"

using namespace std;

Car::Car()
{
	cout << "Car #" << m_vin << ": Default-ctor" << endl;
	m_throttle = 0;
}

Car::Car(char *plates, int vin, float *data)
{
	char *m_platePtr = m_plates;

	strcpy(m_platePtr, plates);

	if(m_vin == vin)
	{
		vin = getIdgen() + 1;
	}
	
	setVin(vin);
	
	for(int i = 0; i < 3; i++)
	{
		m_lla[i] = *data++;
	}

	m_throttle = 0;

	cout << "Car #" << m_vin << ": Parameterized-ctor" << endl;
}

Car::Car(Car &car)
{
	char *plates = car.m_plates;
	char *m_ptr = m_plates;

	strcpy(m_ptr, plates);

	for(int i = 0; i < 3; i++)
	{
		m_lla[i] = car.m_lla[i];
	}

	m_throttle = car.m_throttle;

	cout << "Car #" << m_vin << ": Copy-ctor" << endl;
}

Car::~Car()
{
	cout << "Car #" << m_vin << ": Dtor" << endl;
}

void Car::setPlates(char *plates)
{
	strcpy(m_plates, plates);
}

void Car::setThrottle(int throttle)
{
	m_throttle = throttle;
}
	
char * Car::getPlates()
{
	return m_plates;
}

int Car::getThrottle()
{
	return m_throttle;
}

void Car::drive(int throttle)
{
	m_throttle = throttle;
}

void Car::move(float *lla)
{
	drive(75);

	cout << "Car #" << m_vin << ": DRIVE to destination, with throttle @ " << m_throttle << endl;
}

Car & Car::operator=(Car &car)
{
	char *plates = car.m_plates;
	char *m_ptr = m_plates;

	strcpy(m_ptr, plates);

	m_throttle = car.m_throttle;

	for(int i = 0; i < 3; i++)
	{
		m_lla[i] = car.m_lla[i];
	}

	cout << "Car # " << m_vin << ": Assignment" << endl;

	return *this;
}

ostream & operator<<(ostream &outf, Car &car)
{
	outf << "Car #" << car.m_vin << " Plates: " << car.m_plates << ", Throttle: " << car.m_throttle << " @ [" << car.m_lla[0] << ", " << car.m_lla[1] << ", " << car.m_lla[2] << "]" << endl;

	return outf;
}
