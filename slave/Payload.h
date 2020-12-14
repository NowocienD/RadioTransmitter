#ifndef PAYLOAD_H_
#define PAYLOAD_H_

#include <avr/io.h>
#include "RadioConfig.h"

volatile uint8_t _payload[RADIO_PAYLOAD_LENGTH];
volatile uint8_t _maskByte;

void PayloadReset();
void PayloadSetMaskByte(uint8_t maskByte);
void PayloadSetByte(uint8_t byte, uint8_t data);
uint8_t PayloadGet();
void PayloadMask();

#endif