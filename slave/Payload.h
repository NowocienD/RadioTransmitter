#ifndef PAYLOAD_H_
#define PAYLOAD_H_

#include <avr/io.h>
#include "RadioConfig.h"



#define UnitID1		0
#define DATA1		1
#define Data1_ID	2
#define DATA2		3
#define Data2_ID	4
#define Battery		5
#define MASK		7
#define radundant3	6
#define UnitID2		8

uint8_t _payload[RADIO_PAYLOAD_LENGTH];
uint8_t _maskByte;

void PayloadSetID1(uint8_t data);
void PayloadSetID2(uint8_t data);
void PayloadSetData1(uint8_t data);
void PayloadSetData2(uint8_t data);
void PayloadSetDataID1(uint8_t data);
void PayloadSetDataID2(uint8_t data);
void PayloadSetBatteryVoltage(uint8_t data);

void PayloadReset();
void PayloadSetMaskByte(uint8_t maskByte);
void PayloadSetByte(uint8_t byte, uint8_t data);
uint8_t* PayloadGet();
void PayloadMask();

#endif