/**
 * @brief  CS-202 Project 6 Vehicle Implentation File
 * @Author Ethan Mahoney
 *
 * This file is an implementation file for the Vehicle class prescribed in Project 6 of CS-202
 */

#include <cstring>
#include "Vehicle/Vehicle.h"

Vehicle::Vehicle()
{
	cout << "Vehicle: Default-ctor" << endl;
}

Vehicle::Vehicle(const float *lla)
{
	for(int i = 0; i < LOCATESIZE; i++)
	{
		m_lla[i] = *lla;
		lla++;
	}

	cout << "Vehicle: Parameterized-ctor" << endl;
}

Vehicle::Vehicle(Vehicle &vehicle)
{
	float *lla_ptr = vehicle.m_lla;

	for(int i = 0; i < LOCATESIZE; i++)
	{
		m_lla[i] = *lla_ptr;
		lla_ptr++;
	}

	cout << "Vehicle: Copy-ctor" << endl;
}

Vehicle::~Vehicle()
{
	cout << "Vehicle: Dtor" << endl;
}

void Vehicle::SetLLA(const float* lla)
{
	for(int i = 0; i < LOCATESIZE; i++)
	{
		m_lla[i] = *lla;
		lla++;
	}
}

float * Vehicle::getLla()
{
	return m_lla;
}

Vehicle & Vehicle::operator=(Vehicle &vehicle)
{
	float *lla_ptr = vehicle.m_lla;

	for(int i = 0; i < LOCATESIZE; i++)
	{
		m_lla[i] = *lla_ptr;
		lla_ptr++;
	}

	cout << "Vehicle: Assignment" << endl;

	return *this;
}

void Vehicle::Move(const float *lla) {}

ostream & operator<<(ostream &outf, Vehicle &vehicle)
{
	vehicle.serialize(outf);
	
	return outf;
}

void Vehicle::serialize(ostream &os)
{
	os << "Vehicle @ [" << m_lla[0] << ", " << m_lla[1] << ", " << m_lla[2] << "]" << endl;
}
		

