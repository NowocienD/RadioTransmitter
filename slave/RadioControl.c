#include "RadioControl.h"

uint8_t rxaddres0[5] = {0xff,0xff,0x00,0xff,0xff};
uint8_t txaddres[5] = {0xff,0xff,0x00,0xff,0xff};

void RadioSleep()
{
	SingleRegisterConfig(CONFIG_REG, RADIO_CONFIG | (0<<PWR_UP));
}

void RadioRecieveMode()
{
	SingleRegisterConfig(CONFIG_REG, RADIO_CONFIG | (1<<PWR_UP) | (1<<PRIM_RX));
}

void RadioTransmitMode()
{
	SingleRegisterConfig(CONFIG_REG, RADIO_CONFIG |  (1<<PWR_UP) | (0<<PRIM_RX));
}

void RadioSetRxAddress(uint8_t pipeNum, uint8_t * address)
{
	uint8_t pipeRegAdress = RX_ADDR_P0 + pipeNum;
	RegisterWrite(pipeRegAdress, address, RADIO_ADDRESS_LENGTH);
}

void RadioSetTxAddress(uint8_t * address)
{
	RegisterWrite(TX_ADDR, address, RADIO_ADDRESS_LENGTH);
}

void RadioInit()
{
	DDRB |= ((1<<CSN)|(1<<CE));
	CE_LOW;
	CSN_HIGH;
	
	//interrupt on PB0
	PCICR |= (1<<PCIE0);
	PCIFR |= (1<<PCIF0);
	PCMSK0 |= (1<<PCINT0);

	SpiInit();
}

void RadioConfig()
{
	SingleRegisterConfig(RF_CH,Radio_CHANNEL);
	SingleRegisterConfig(RX_PW_P0, RADIO_PAYLOAD_LENGTH);
	SingleRegisterConfig(EN_AA, EN_AA_ENABLED);
	SingleRegisterConfig(RF_SETUP, (RADIO_POWER | RADIO_DATARATE));
	
	RadioSetRxAddress(0, rxaddres0);
	//RadioSetRxAddress(1, rxaddres1);
	//RadioSetRxAddress(2, rxaddres2);
	//RadioSetRxAddress(3, rxaddres3);
	//RadioSetRxAddress(4, rxaddres4);
	//RadioSetRxAddress(5, rxaddres5);
	RadioSetTxAddress(txaddres);
	
	RadioSleep();
}

void RadioSendPayload(uint8_t * value)
{
	RadioTransmitMode();
	
	CSN_LOW;
	SpiTransfer( FLUSH_TX );
	CSN_HIGH;
	
	CSN_LOW;
	SpiTransfer( W_TX_PAYLOAD );
	SpiWrite(value, RADIO_PAYLOAD_LENGTH);
	CSN_HIGH;
	
	CE_HIGH;
	_delay_us(10);
}

ISR(PCINT0_vect)
{
	CE_LOW;
	RadioSleep();
	SingleRegisterConfig(STATUS,(1<<TX_DS)|(1<<MAX_RT)|(1<<RX_DR)); // clear flags
}