//Ethan Mahoney CS 202 Proj5
//Header file which includes the definition of the Vehicle class and its member functions
#ifndef VEHICLE_H_
#define VEHICLE_H_

using namespace std; 

class Vehicle
{
	public:
		Vehicle();
		Vehicle(int vin, const float *data);
		Vehicle(Vehicle &vehicle);
		~Vehicle();

		void setLla(const float *lla);
		void setVin(const int vin);

		const float *getLla();
		const int getVin();
		static int getIdgen();
		Vehicle & operator=(Vehicle &vehicle);
		friend ostream & operator<<(ostream &outf, Vehicle &vehicle);
		void move(const float *lla);		 
		
	protected:
		float m_lla[3];
		int m_vin;
		
	private:
		static int s_idgen;
};

#endif

