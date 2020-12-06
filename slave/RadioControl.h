#ifndef _RADIOCONTROL_H_
#define _RADIOCONTROL_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "RadioConfiguration.h"
#include "nRF24L01.h"
#include "RadioRegs.h"

extern void RadioInit();
extern void RadioSendPayload(uint8_t*);

extern void RadioSetRxAddress(uint8_t pipeNum, uint8_t * address);
extern void RadioSetTxAddress(uint8_t*);

#endif 
