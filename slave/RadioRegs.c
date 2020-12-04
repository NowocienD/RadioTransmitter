#include "RadioRegs.h"

void SingleRegisterConfig(uint8_t reg, uint8_t value)
{
	CSN_LOW;
	SpiTransfer(W_REGISTER | (REGISTER_MASK & reg));
	SpiTransfer(value);
	CSN_HIGH;
}

void RegisterRead(uint8_t reg, uint8_t * value, uint8_t len)
{
	CSN_LOW;
	SpiTransfer(R_REGISTER | (REGISTER_MASK & reg));
	SpiRead(value, len);
	CSN_HIGH;
}

void RegisterWrite(uint8_t reg, uint8_t * value, uint8_t len)
{
	CSN_LOW;
	SpiTransfer(W_REGISTER | (REGISTER_MASK & reg));
	SpiWrite(value, len);
	CSN_HIGH;
}