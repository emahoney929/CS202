/**
 * @brief  CS-202 Project 6 Vehicle Header File
 * @Author Ethan Mahoney
 *
 * This file is an header file for the Header class prescribed in Project 6 of CS-202
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <iostream>
using namespace std;

const int LOCATESIZE = 3;

class Vehicle
{	
	friend ostream & operator<<(ostream &outf, Vehicle &vehicle);

	public:
		Vehicle();
		Vehicle(const float *lla);
		Vehicle(Vehicle &vehicle);
		virtual ~Vehicle();
		
		void SetLLA(const float *lla);
		float *getLla();

		Vehicle & operator=(Vehicle &vehicle);
		virtual void Move(const float *lla) = 0;		 
		
	protected:
		float m_lla[3];

	private:
		virtual void serialize(ostream &os);
};

#endif

