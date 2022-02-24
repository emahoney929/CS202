//Ethan Mahoney CS202 Proj5
//Implementation file which contains the implementations of the Vehicle class and its member functions
#include <iostream>
#include <cstring>
#include <Vehicle/Vehicle.h>

using namespace std;

int Vehicle::s_idgen = 0;

Vehicle::Vehicle() : m_vin(s_idgen++)
{
	cout << "Vehicle #" << m_vin << ": Default-ctor" << endl;
}

Vehicle::Vehicle(int vin, const float *data)
{
	if(m_vin == vin)
	{
		vin = ++s_idgen;
	}

	setVin(vin);
	
	for(int i = 0; i < 3; i++)
	{
		m_lla[i] = *data;
		data++;
	}

	cout << "Vehicle #" << m_vin << ": Parameterized-ctor" << endl;
}
	
Vehicle::Vehicle(Vehicle &vehicle)
{
	float *data = vehicle.m_lla;

	m_vin = s_idgen++;

	for(int i = 0; i < 3; i++)
	{
		m_lla[i] = *data;
		data++;
	}
	
	cout << "Vehicle #" << m_vin << ": Copy-ctor" << endl;
}

Vehicle::~Vehicle()
{
	cout << "Vehicle #" << m_vin << ": Dtor" << endl;
}

void Vehicle::setLla(const float *data)
{
	for(int i = 0; i < 3; i++)
	{
		m_lla[i] = *data++;
	}
}

void Vehicle::setVin(const int vin)
{
	int *vin_ptr = &m_vin;
	*vin_ptr = vin;
}

int Vehicle::getIdgen()
{
	return s_idgen;
}

const float * Vehicle::getLla()
{
	return m_lla;
}

const int Vehicle::getVin()
{
	return m_vin;
}

void Vehicle::move(const float *data)
{
	cout << "Vehicle #" << m_vin << ": CAN'T MOVE-I DON'T KNOW HOW" << endl;
}

Vehicle & Vehicle::operator=(Vehicle &vehicle)
{
	for(int i = 0; i < 3; i++)
	{
		m_lla[i] = vehicle.m_lla[i];
	}

	cout << "Vehicle # " << m_vin << ": Assignment" << endl;

	return *this;
}

ostream & operator<<(ostream &outf, Vehicle &vehicle)
{
	outf << "Vehicle #" << vehicle.m_vin << " [" << vehicle.m_lla[0] << ", " << vehicle.m_lla[1] << ", " << vehicle.m_lla[2] << "]" << endl;

	return outf;
}
