#ifndef _SPI_H_
#define _SPI_H_

#include <avr/io.h>

#define PORT_SPI    PORTB
#define DDR_SPI     DDRB

#define DD_MISO     DDB4
#define DD_MOSI     DDB3
#define DD_SCK      DDB5

extern void SpiInit();
extern void SpiRead (uint8_t*, uint8_t);
extern void SpiWrite (uint8_t*, uint8_t);
extern uint8_t SpiTransfer (uint8_t);

#endif