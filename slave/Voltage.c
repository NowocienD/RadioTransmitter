#include "Voltage.h"

#define DoAdcSleep do {	SMCR = (1<<SM0) | (1<<SE);	sleep_cpu();	SMCR = 0x00;	} while (0);

void VoltageMeasure_Init()
{
	ADMUX = (1 << REFS0)	// AVCC with external capacitor(1) at AREF pin
	| (1 << MUX3)
	| (1 << MUX2)
	| (1 << MUX1)
	| (0 << MUX0);			// 1.1V (VBG)
	
	ADCSRA =
	(1<<ADPS2)|				// Prescaler Select Bits // min prescaler f.cpu/64 #TODO zmieniæ na /2 po zmniejszeniu taktowania uC
	(1<<ADPS1)|
	(0<<ADPS0)|
	(1<<ADIE);				// Interrupt Enable
}

void VoltageMeasure_Start()
{
	ADCSRA |=
	(1<<ADEN)|	// ADC Enable
	(0<<ADSC);	// Start conversion //Not nessesary. After entering ADC noise reduction sleep mode ADS automaticaly starts coversion
	
	sei(); // #TODO prawdopodonnie do usuniêcia/ trzeba jakos rozwiazac prblem wylaczenie przerwan wewnatrz przerwan
	DoAdcSleep;
}

uint8_t VoltageMeasure_Get()
{
	// make sure ADCL is readed first
	uint8_t ADC_LOW = ADCL;
	
	// calculate voltage
	float result = (1.1 * 1024)/((ADCH<<8) + ADC_LOW);
		
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
	sleep_disable();
	//voltage = VoltageMeasure_Get();
	//USART_Transmit(voltage);
	VoltageMeasure_Stop();
}