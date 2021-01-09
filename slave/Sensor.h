#ifndef SENSOR_H_
#define SENSOR_H_

#include "Pin config.h"
#include <avr/io.h>

void SensorInit();
void SensorStop();
uint8_t SensorGet(uint8_t sensorNum);

#endif 