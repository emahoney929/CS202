#ifndef MENU_H_
#define MENU_H_

#include "Agency/Agency.h"
#include "Sensor/Sensor.h"
#include "Car/Car.h"

void userMenuPrompt();
void readIn(Agency& agency);
void const printAll(Agency& agency);
void const printFiltered(Agency& agency);
void reserveOne(Agency& agency);

#endif
