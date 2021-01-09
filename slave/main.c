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
#include "Sensor.h"
#include <avr/eeprom.h> 

#define DoSleep	do { cli();	SMCR = (1<<SM1) | (1<<SE);						sleep_bod_disable();sei(); sleep_cpu();	  SMCR = 0x00;						} while (0);

volatile uint8_t sleepPeriodCounter;
volatile uint8_t sleepTime;
volatile uint8_t doFlag;

volatile uint8_t unitID_1;
volatile uint8_t unitID_2;

int main(void)
{
	MCUSR = 0x00; //MCU Status Register // zresetowanie flag resetu.
	CLKPR =  (1<<CLKPCE) | (1<<CLKPS2); //prescaler 8
	
	ADC_reducePower;
	AC_reducePower;		
	ADC_off;
	AC_off;
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
	
	__EEGET(unitID_1, EEPROM_UNIT_ID_1);
	__EEGET(unitID_2, EEPROM_UNIT_ID_2);
	
	DDRB |= led_PIN;
	
	led_on;
	_delay_ms(50);
	led_off;
	
	#ifdef DEBUG_ON
	_delay_ms(500);
	led_on;
	_delay_ms(50);
	led_off;
	#endif
	
	RadioInit();
	WDT_Init();
	VoltageMeasure_Init();
	
	RadioConfig();
	sleepPeriodCounter = 0 ;
	
	sleepTime = 38 ;
	
	#ifdef DEBUG_ON
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
			SensorInit();
			_delay_ms(10);
			#ifdef DEBUG_ON
			led_on;
			#endif
			
			PayloadReset();

			PayloadSetID1(unitID_1);
			PayloadSetID2(unitID_2);
			PayloadSetBatteryVoltage(VoltageMeasure_Get());
			
			PayloadSetData1(SensorGet(0));
			PayloadSetDataID1(8);
			
			PayloadSetData2(SensorGet(1));
			PayloadSetDataID2(0);
			
			PayloadSetMaskByte(rand());
			PayloadMask();			
			RadioSendPayload(PayloadGet());
			
	
			SensorStop();
			
			#ifdef DEBUG_ON
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