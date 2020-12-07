#ifndef LOWPOWERCONFIG_H_
#define LOWPOWERCONFIG_H_

#define ADC_reducePower DIDR0 = 0x3F; // DIDR0 – Digital Input Disable Register 0 // DataSheet: this bit should be written logic one to reduce power consumption in the digital input buffer
#define	ADC_off ADCSRA &=~(1<<ADEN);
#define	AC_off ACSR |= (1<<ADC);

#endif