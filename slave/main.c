#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Pin config.h"
#include "Voltage.h"
#include "UART.h"
#include "RadioControl.h"
#include <avr/sleep.h>
#include <avr/wdt.h>
#include "WatchDogTimer.h"
#include "LowPowerConfig.h"

uint8_t bufferA[16] = {0x44, 0x55, 0x50, 0x41,0xA5,0xA6,0xA7,0xA8,0xA9,0xB0,0xB1,0xB2,0xB3,0xB4,0xB5,0xB6};

#define DoSleep do {	SMCR = (1<<SM1) | (1<<SE);	sleep_cpu();	SMCR = 0x00;	} while (0);

volatile uint8_t sleepPeriodCounter;
volatile uint8_t sleepTime;


int main(void)
{
	MCUSR = 0x00; //MCU Status Register // zresetowanie flag resetu.
	ADC_reducePower;
	
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
	
	DDRB |= led_PIN;
	led_on;
	_delay_ms(1);
	led_off;
	_delay_ms(100);
	led_on;
	_delay_ms(1);
	led_off;
	
	WDT_Init();
	RadioInit();
	USART_Init(MYUBRR);
	VoltageMeasure_Init();
	
	RadioConfig();
	sleepPeriodCounter = 0 ;
	sleepTime = 38 ;
	
	sei();
	while (1)
	{
		ADC_off;
		AC_off;
		sleep_bod_disable();
		DoSleep;
	}
}



ISR(WDT_vect)
{
	WDTCSR = (1<<WDIE);	// interrupt enable // bardzo niebezpieczna linia. #TODO do konsultacji z promotorem
	SMCR = 0x00;		// exit sleep
	
	sleepPeriodCounter++;
	if (sleepPeriodCounter > sleepTime)
	{
		sleepPeriodCounter = 0 ;
		VoltageMeasure_Start();
		RadioSendPayload(bufferA);
	}
}