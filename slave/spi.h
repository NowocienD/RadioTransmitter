#ifndef _SPI_H_
#define _SPI_H_

#include <avr/io.h>

#define PORT_SPI    PORTB
#define DDR_SPI     DDRB

#define MISO_PIN     DDB4
#define MOSI_PIN     DDB3
#define SCK_PIN      DDB5

extern void SpiInit();
extern void SpiRead (uint8_t*, uint8_t);
extern void SpiWrite (uint8_t*, uint8_t);
extern uint8_t SpiTransfer (uint8_t);

#endif