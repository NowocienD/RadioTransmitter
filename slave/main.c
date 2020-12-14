#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include "Config.h"
#include "Pin config.h"
#include "Voltage.h"
#include "UART.h"
#include "RadioControl.h"
#include "WatchDogTimer.h"
#include "LowPowerConfig.h"
#include "Payload.h"
#include <stdlib.h>

#define DoSleep	do { cli();	SMCR = (1<<SM1) | (1<<SE);						sleep_bod_disable();sei(); sleep_cpu();	  SMCR = 0x00;						} while (0);

volatile uint8_t sleepPeriodCounter;
volatile uint8_t sleepTime;
volatile uint8_t doFlag;

int main(void)
{
	MCUSR = 0x00; //MCU Status Register // zresetowanie flag resetu.
	CLKPR =  (1<<CLKPCE) | (1<<CLKPS2); //prescaler 8
	
	ADC_reducePower;
	AC_reducePower;
	Timer0_off;
	Timer1_off;
	Timer2_off;
	PowerReducion_Enable;
	
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
	_delay_ms(50);
	led_off;
	_delay_ms(500);
	led_on;
	_delay_ms(50);
	led_off;
	
	WDT_Init();
	RadioInit();
	//USART_Init(MYUBRR);
	VoltageMeasure_Init();
	
	RadioConfig();
	sleepPeriodCounter = 0 ;
	
	sleepTime = 38 ;
	
	#ifdef DEBUG
	sleepTime /= 5 ;
	#endif
	
	sei();
	doFlag = 0;
	
	while (1)
	{
		ADC_off;
		AC_off;
		DoSleep;
		if (doFlag == 1)
		{
			doFlag = 0 ;
			VoltageMeasure_Start();
			#ifdef DEBUG
			led_on;
			#endif
			PayloadReset();
			PayloadSetMaskByte(rand());
			
			if (BUTTON_HIGH)
			PayloadSetByte(0, 1);
			else
			PayloadSetByte(0, 0);			
			PayloadSetByte(1, VoltageMeasure_Get());
			PayloadMask();
			RadioSendPayload(PayloadGet());
			
			#ifdef DEBUG
			led_off;
			#endif
		}
	}
}

ISR(WDT_vect)
{
	WDTCSR = (1<<WDIE);	// interrupt enable // bardzo niebezpieczna linia. #TODO do konsultacji z promotorem
	SMCR = 0x00;		// exit sleep
	
	if (sleepPeriodCounter >= sleepTime)
	{
		sleepPeriodCounter = 0 ;
		doFlag = 1;
	}
	sleepPeriodCounter++;
}