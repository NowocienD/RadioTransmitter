#ifndef PAYLOAD_H_
#define PAYLOAD_H_

#include <avr/io.h>
#include "RadioConfig.h"



#define UnitID 0
#define DATA1 1
#define DATA2 2
#define Battery 3
#define MASK 7
#define radundant1 1
#define radundant2 1
#define radundant3 1

uint8_t _payload[RADIO_PAYLOAD_LENGTH];
uint8_t _maskByte;

void PayloadSetID(uint8_t data);
void PayloadSetData1(uint8_t data);
void PayloadSetData2(uint8_t data);
void PayloadSetBatteryVoltage(uint8_t data);

void PayloadReset();
void PayloadSetMaskByte(uint8_t maskByte);
void PayloadSetByte(uint8_t byte, uint8_t data);
uint8_t* PayloadGet();
void PayloadMask();

#endif