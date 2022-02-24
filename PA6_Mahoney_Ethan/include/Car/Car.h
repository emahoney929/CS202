/**
 * @brief  CS-202 Project 6 Car Header File
 * @Author Ethan Mahoney
 *
 * This file is an header file for the Car class prescribed in Project 6 of CS-202
 */

#ifndef CAR_H_
#define CAR_H_

#include "Vehicle/Vehicle.h"

class Car: public Vehicle
{
	public:
		Car();
		Car(const float *lla);
		Car(Car &car);
		~Car();

		void setThrottle(const int throttle);
		int getThrottle();

		void drive(const int throttle);
		void Move(const float *lla);
		Car & operator=(Car &car);
				
	private:
		int m_throttle;
		void serialize(ostream &os);
};

#endif
