#ifndef VOLTAGE_H_
#define VOLTAGE_H_

#include <avr/io.h>
#include <avr/interrupt.h>

extern uint8_t VoltageMeasure_Get();
extern void VoltageMeasure_Start();
extern void VoltageMeasure_Init();
extern void VoltageMeasure_Stop();

#endif