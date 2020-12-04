#include "Voltage.h"

// works only on port C !!!


// presklaer ustaw tak zeby m,ice 50khz - 200khz.
// przy 1mHz wewnetrznym oscylatorze to 8 lub 16

void VoltageMeasure_Init()
{
	ADCSRA = (1<<ADEN)|			// ADC Enable
	(1<<ADPS2)|(1<<ADPS1)|		// Prescaler Select Bits
	(0<<ADIE);					// Interrupt Enable
	

	ADMUX = (1 << REFS0)		// AVCC with external capacitor(1) at AREF pin
	| (1 << MUX3)
	| (1 << MUX2)
	| (1 << MUX1)
	| (0 << MUX0);				// 1.1V (VBG)
	
	//25 cykli adc * cpu_freq / proscaler ~= 0,4 ms	
}


void VoltageMeasure_Start()
{	
	ADCSRA |= (1<<ADSC);
}

uint8_t VoltageMeasure_Get()
{
	
	uint8_t low = ADCL;
	uint8_t high = ADCH;
		
	float result = (1.3 *1024)/((high* 0x100) + low);
	
	uint8_t res = (int)(result *10);
	return res;	
}

void VoltageMeasure_Stop()
{
	ADCSRA = (0<<ADEN); // ADC Enable
}

