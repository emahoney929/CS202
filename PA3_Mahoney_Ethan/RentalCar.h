//Ethan Mahoney
//Header file contains the class and function prototypes to class function implementations
#ifndef RENTALCAR_H_
#define RENTALCAR_H_

int const MAX_STR_SIZE = 100;

class RentalCar
{
    public:
       RentalCar();
       RentalCar(int year, char *make, char *model, float price, bool available);

       int getYear();
       char *getMake();
       char *getModel();
       float getPrice();
       bool getAvailability();

       void setYear(int year);
       void setMake(char *make);
       void setModel(char *model);
       void setPrice(float price);
       void setAvailability(bool available);
       void print();
       void estimateCost(int &dayAmt);
     
    private:
       int m_year;
       char m_make[MAX_STR_SIZE];
       char m_model[MAX_STR_SIZE];
       float m_price;
       bool m_available;
};

#endif
