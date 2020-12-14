#include "Payload.h"


void PayloadReset()
{
	uint8_t i;
	for (i = 0; i < RADIO_PAYLOAD_LENGTH-1; i++)
	{
		_payload[i] = 0x00;
	}
}

void PayloadSetMaskByte(uint8_t maskByte)
{
	_maskByte = maskByte;
}
void PayloadSetByte(uint8_t byte, uint8_t data)
{
	_payload[byte] = data;
}

uint8_t* PayloadGet()
{
	return _payload;
}

void PayloadMask()
{
	uint8_t i;
	for (i = 0; i < RADIO_PAYLOAD_LENGTH-1; i++)
	{
		_payload[i] ^= _maskByte;
	}
	_payload[RADIO_PAYLOAD_LENGTH] = _maskByte;
	
}