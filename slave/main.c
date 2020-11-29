/*
* Author : Dominik Nowocien
*/


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Pin config.h"


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

	while (1)
	{
		
	}
}

