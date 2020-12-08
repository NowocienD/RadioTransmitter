#ifndef LOWPOWERCONFIG_H_
#define LOWPOWERCONFIG_H_

#define AC_reducePower DIDR1 = 0x03
#define ADC_reducePower DIDR0 = 0x3F // DIDR0 – Digital Input Disable Register 0 // DataSheet: this bit should be written logic one to reduce power consumption in the digital input buffer
#define	ADC_off ADCSRA &=~(1<<ADEN)
#define	AC_off ACSR |= (1<<ADC)

#define Timer0_off TCCR0B &= ~(1<<CS02) & ~(1<<CS01) & ~(1<<CS00)
#define Timer1_off TCCR1B &= ~(1<<CS12) & ~(1<<CS11) & ~(1<<CS10)
#define Timer2_off TCCR2B &= ~(1<<CS22) & ~(1<<CS21) & ~(1<<CS20)

#define PowerReducion_Enable PRR = ~(1<<PRSPI) & ~(1<<PRADC)

#endif