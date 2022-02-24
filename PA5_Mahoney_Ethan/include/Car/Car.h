//Ethan Mahoney CS 202 Proj5
//Header file which includes the definition of the Car class and its inheritance from the Vehicle class
#ifndef CAR_H_
#define CAR_H_

#include <Vehicle/Vehicle.h>

using namespace std;

class Car: public Vehicle
{
	public:
		Car();
		Car(char *plates, int vin, float *data);
		Car(Car &car);
		~Car();

		void setPlates(char *plates);
		void setThrottle(int throttle);

		char *getPlates();
		int getThrottle();

		void drive(int throttle);
		Car & operator=(Car &car);
		friend ostream & operator<<(ostream &outf, Car &car);
		void move(float *lla);

	private:
		char m_plates[256];
		int m_throttle;
};

#endif
