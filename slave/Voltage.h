#ifndef VOLTAGE_H_
#define VOLTAGE_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include "Config.h"
#include "UART.h"

volatile uint8_t voltage;
uint8_t seed;

extern uint8_t VoltageGetSeed();
extern void VoltageGiveRandomSeed();
extern uint8_t VoltageMeasure_Get();
extern void VoltageMeasure_Init();
extern void VoltageMeasure_Start();
extern void VoltageMeasure_Stop();

#endif