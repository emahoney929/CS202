//Ethan Mahoney
//Source file for Sensor Header file
#include <iostream>
#include <fstream>
#include "Sensor/Sensor.h"
#include "my_string/my_string.h"

//Declaration of static variables
int Sensor::gps_cnt;
int Sensor::camera_cnt;
int   Sensor::lidar_cnt;
int Sensor::radar_cnt;

using namespace std;

Sensor::Sensor()
{
    myStringCopy(m_type, "NONE");
    m_extracost = 0.00;
    gps_cnt = 0;
    camera_cnt = 0;
    lidar_cnt = 0;
    radar_cnt = 0;
}
  
Sensor::Sensor(char *type, float extracost, int gps, int camera, int lidar, int radar)
{
    myStringCopy(m_type, type);
    m_extracost = extracost;
    gps_cnt = gps;
    camera_cnt = camera;
    lidar_cnt = lidar;
    radar_cnt = radar;
}

Sensor::Sensor(const Sensor &sensor)
{
    myStringCopy(m_type, sensor.m_type);
    m_extracost = sensor.m_extracost;
    gps_cnt = sensor.gps_cnt;
    camera_cnt = sensor.camera_cnt;
    lidar_cnt = sensor.lidar_cnt;
    radar_cnt = sensor.radar_cnt;
}

char *Sensor::getType()
{
    return m_type;
}

float const Sensor::getExtracost() 
{
    return m_extracost;
}

int Sensor::getGps()
{
    return gps_cnt;
}
 
void Sensor::resetGps()
{
    gps_cnt = 0;
}
 
int Sensor::getCamera()
{
    return camera_cnt;
}
 
void Sensor::resetCamera()
{
    camera_cnt = 0;
}
 
int Sensor::getLidar()
{
    return lidar_cnt;
}
 
void Sensor::resetLidar()
{
    lidar_cnt = 0;
}
 
int Sensor::getRadar()
{
    return radar_cnt;
}
 
void Sensor::resetRadar()
{
    radar_cnt = 0;
}
 
void Sensor::setType(char *type)
{
    /*if(myStringCompare(type, "gps"))
    {
        gps_cnt++;
        setExtracost(GPS_PRICE);
    }
    else if(myStringCompare(type, "camera"))
    {
        camera_cnt++;
        setExtracost(CAMERA_PRICE);
    }
    else if(myStringCompare(type, "lidar"))
    {
        lidar_cnt++;
        setExtracost(LIDAR_PRICE);
    }
    else if(myStringCompare(type, "radar"))
    {
        radar_cnt++;
        setExtracost(RADAR_PRICE);
    }
    else if(myStringCompare(type, "NONE"))
    {
        
    }*/
    if(!myStringCompare(type, " "))
    {
        myStringCopy(type, "NONE");
        //setExtracost(NONE);
    }
    else
    {
        myStringCopy(m_type, type);
    }
}

//Function to set extra cost for each sensor
void Sensor::setExtracost(float extracost)
{    
    m_extracost = extracost;
}

//Operator overloading to compare to two sensor objects
bool Sensor::operator ==(const Sensor &obj1)
{
    if(myStringCompare(m_type, obj1.m_type) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}  
