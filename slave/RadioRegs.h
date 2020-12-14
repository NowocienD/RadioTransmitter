#ifndef _RADIOREGS_H_
#define _RADIOREGS_H_

#include <avr/io.h>
#include "RadioConfig.h"
#include "spi.h"
#include "nRF24L01.h"

extern void SingleRegisterConfig(uint8_t reg, uint8_t value);
extern void RegisterRead(uint8_t reg, uint8_t * value, uint8_t len);
extern void RegisterWrite(uint8_t reg, uint8_t * value, uint8_t len);

#endif 
