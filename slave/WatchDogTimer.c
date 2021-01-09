#include "WatchDogTimer.h"

void WDT_Init()
{
	WDTCSR = (1<<WDCE) | (1<<WDE); // WTD ENABLE and allow changes in WDTCSR
	
	#ifndef DEBUG_ON
	WDTCSR =
	(1<<WDIE)|	// interrupt enable
	(1<<WDE)|	// enable WDT
	(1<<WDP3)|	// set prescaler to 1024
	(0<<WDP2)|	// interrupts will occur once in 8s
	(0<<WDP1)|
	(1<<WDP0);
	#else
	WDTCSR =
	(1<<WDIE)|	// interrupt enable
	(1<<WDE)|	// enable WDT
	
	(0<<WDP3)|	//mniej. pol sekunbdy
	(1<<WDP2)|	// interrupts will occur once in 8s
	(0<<WDP1)|
	(0<<WDP0);
	#endif
}