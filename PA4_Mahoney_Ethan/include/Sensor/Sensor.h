#ifndef SENSOR_H_
#define SENSOR_H_

float const NONE = 0.00;
float const GPS_PRICE = 5.00;
float const CAMERA_PRICE = 10.00;
float const LIDAR_PRICE = 15.00;
float const RADAR_PRICE = 20.00;



class Sensor
{
    public:
       Sensor();
       Sensor(char *type, float extracost, int gps, int camera, int lidar, int radar);
       Sensor(const Sensor &sensor);


       int getGps();
       int getCamera();
       int getLidar();
       int getRadar();
       void resetGps();
       void resetCamera();
       void resetLidar();
       void resetRadar();

      /* void setGps(int gps);
       void setCamera(int camera);
       void setLidar(int lidar);
       void setRadar(int radar);*/

       char *getType();
       float const getExtracost();

       void setType(char *type);
       void setExtracost(float extracost);
       
       bool operator == (const Sensor &obj);

    private:
       char m_type[256];
       float m_extracost;
       static int gps_cnt;
       static int camera_cnt;
       static int lidar_cnt;
       static int radar_cnt;
};

#endif
