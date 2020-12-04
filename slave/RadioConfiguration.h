#ifndef RADIOCONFIGURATION_H_
#define RADIOCONFIGURATION_H_

#define CH         2
#define PAYLOAD    16
#define CONFIG1     ( (1<<MASK_RX_DR) | (1<<EN_CRC) | (0<<CRCO) | (1<<MASK_RX_DR))

#define addressLength 5

#define CE  PB1
#define CSN PB2

#define CSN_HIGH  PORTB |=  (1<<CSN);
#define CSN_LOW	  PORTB &= ~(1<<CSN);
#define CE_HIGH	  PORTB |=  (1<<CE);
#define CE_LOW    PORTB &= ~(1<<CE);

#define EN_AA_ENABLED 0x3f
#define EN_AA_DISABLED 0x00

#endif