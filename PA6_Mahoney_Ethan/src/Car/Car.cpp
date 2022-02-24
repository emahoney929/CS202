/**
 * @brief  CS-202 Project 6 Car Implentation File
 * @Author Ethan Mahoney
 *
 * This file is an implementation file for the Car class prescribed in Project 6 of CS-202
 */

#include "Car/Car.h"

Car::Car() : m_throttle(0) 
{
	cout << "Car: Default-ctor" << endl;
}

Car::Car(const float *lla) : m_throttle(0), Vehicle(lla)
{
	for(int i = 0; i < LOCATESIZE; i++)
	{
		m_lla[i] = *lla++;
	}
	
	cout << "Car: Parameterized-ctor" << endl;
}

Car::Car(Car &car)
{
	float *lla_ptr = car.m_lla;

	for(int i = 0; i < LOCATESIZE; i++)
	{
		m_lla[i] = *lla_ptr++;
	}
	
	cout << "Car: Copy-ctor" << endl;
}

Car::~Car()
{
	cout << "Car: Dtor" << endl;
}

void Car::setThrottle(const int throttle) {m_throttle = throttle;}

int Car::getThrottle() {return m_throttle;}

void Car::drive(const int throttle)
{
	m_throttle = throttle;
}

void Car::Move(const float *lla)
{
	SetLLA(lla);

	cout << "Car: DRIVE to destination, with throttle @ 75" << endl;

	drive(75);
}

Car & Car::operator=(Car &car)
{
	m_throttle = car.m_throttle;

	for(int i = 0; i < LOCATESIZE; i++)
	{
		m_lla[i] = car.m_lla[i];
	}
	
	return *this;
}

void Car::serialize(ostream &os)
{
	os << "Car: Throttle: " << m_throttle << " @ [" << m_lla[0] << ", " << m_lla[1] << ", " << m_lla[2] << "]" << endl;
}


	
