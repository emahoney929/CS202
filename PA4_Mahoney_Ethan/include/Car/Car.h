#ifndef CAR_H_
#define CAR_H_

#include <iostream>
#include "Sensor/Sensor.h"

using namespace std;

int const SENSORAMT = 3;
int const CAR_AMT = 5;

class Car
{
    public:
       Car();
       Car(int year, char *make, char *model, Sensor *sensors, int sensorCount, float basePrice, float finalprice, bool available, char *owner);
       Car(const Car &car);

       int getYear();
       char *getMake();
       char *getModel();
       Sensor *getSensors();
       int getCount();
       float getBaseprice();
       float getFinalprice();
       bool getAvailable();
       char *getOwner();

       void setYear(int year);
       void setMake(char *make);
       void setModel(char *model);
       void setCount(int sensorCount);
       void setBaseprice(float baseprice);
       void setAvailable(bool available);
       void setOwner(char *owner);

       void updatePrice();
       void print();
       void estimateCost(int days);
       Car & operator + (Sensor &sensor);
       Car & operator + (char *owner);
       friend istream & operator >>(istream &inf, Car &car);
       
    private:
       int m_year;
       char m_make[256];
       char m_model[256];
       Sensor m_sensors[SENSORAMT];
       int m_sensorcount;
       float m_baseprice;
       float m_finalprice;
       bool m_available;
       char m_owner[256];
};

#endif
