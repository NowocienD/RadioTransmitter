#ifndef VOLTAGE_H_
#define VOLTAGE_H_

#include <avr/io.h>

uint8_t VoltageMeasure_Get();
void VoltageMeasure_Start();
void VoltageMeasure_Init();
void VoltageMeasure_Stop();

#endif /* VOLTAGE_H_ */