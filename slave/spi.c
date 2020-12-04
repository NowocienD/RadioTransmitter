#include "spi.h"

void SpiInit()
{
	// Set as input
	DDR_SPI &= ~(1<<DD_MISO);
	// Set as outputs
	DDR_SPI |= ((1<<DD_MOSI)|(1<<DD_SCK));
	
	SPCR = ((0<<SPIE)|      // SPI Interupt Enable
	(1<<SPE)|				// SPI Enable	
	(0<<DORD)|              // Data Order (MSB first)
	(1<<MSTR)|              // Master/Slave select
	(0<<CPOL)|              // Clock Polarity (SCK is low when idle) #TODO Power Consumption potential improvement
	(0<<CPHA)|	            // Clock Phase 	
	(0<<SPR1)|(0<<SPR0));   // SPI Clock Rate f.osc/4	
	
	SPSR = (1<<SPI2X);      // Double SPI Speed
							//final clock speed is f.osc/2
}

void SpiRead (uint8_t* data, uint8_t length)
{
	uint8_t i;
	for (i = 0; i < length; i++) {
		SPDR = data[i];
		while(!(SPSR & (1<<SPIF)));
		data[i] = SPDR;
	}
}

void SpiWrite (uint8_t* data, uint8_t length)
{
	uint8_t i;
	for (i = 0; i < length; i++) {
		SPDR = data[i];
		while(!(SPSR & (1<<SPIF)));
	}
}

uint8_t SpiTransfer (uint8_t data)
{
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}
