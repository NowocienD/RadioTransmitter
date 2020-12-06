#include "Voltage.h"
#include "Config.h"

// presklaer ustaw tak zeby miec 50khz - 200khz.
// przy 1mHz wewnetrznym oscylatorze to 8 lub 16

#define ADC_reducePower DIDR0 = 0x3F; // DIDR0 – Digital Input Disable Register 0 //this bit should be written logic one to reduce power consumption in the digital input buffer

void VoltageMeasure_Init()
{		
		ADMUX = (1 << REFS0)	// AVCC with external capacitor(1) at AREF pin
		| (1 << MUX3)
		| (1 << MUX2)
		| (1 << MUX1)
		| (0 << MUX0);			// 1.1V (VBG)
		
		ADCSRA =
		(1<<ADPS2)|(1<<ADPS1)|	// Prescaler Select Bits
		(1<<ADIE);				// Interrupt Enable
}


void VoltageMeasure_Start()
{	
	ADCSRA |= 
	(1<<ADEN)|				// ADC Enable
	(1<<ADSC);				// Start conversion
}

uint8_t VoltageMeasure_Get()
{
	// calculate voltage
	float result = (1.1 * 1024)/((ADCH<<8) + ADCL);
	
	// recaltulate result to batery percentage
	uint8_t res = (result-MIN_BATTERY_VOLTAGE)/(MAX_BATTERY_VOLTAGE-MIN_BATTERY_VOLTAGE) * 100;
	return res; 
}

void VoltageMeasure_Stop()
{
	ADCSRA &= ~(1<<ADEN); // ADC Enable bit to 0 = disable
}


ISR(ADC_vect)
{
	USART_Transmit(VoltageMeasure_Get());
	VoltageMeasure_Stop();
}