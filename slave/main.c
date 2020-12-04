/*
* Author : Dominik Nowocien
*/


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Pin config.h"
#include "Voltage.h"
#include "UART.h"


int main(void)
{
	
	//ustawenie wszystkich pinow jako wejscia
	DDRB = 0x00;
	DDRC = 0x00;
	DDRD = 0x00;
	//wlaczenie pullup na wszystkich pinach
	PORTB = 0xFF;
	PORTC = 0xFF;
	PORTD = 0xFF;
	
	Switch1_disble_PullUP;
	Switch2_disble_PullUP;	

	VoltageMeasure_Init();
	USART_Init(MYUBRR);

	while (1)
	{
		VoltageMeasure_Start();
		_delay_ms(500);
		USART_Transmit(VoltageMeasure_Get());
		_delay_ms(500) ;
	}
}

