#include "Payload.h"


void PayloadSetID(uint8_t data)
{
	_payload[UnitID] = data;
}

void PayloadSetData1(uint8_t data)
{
	_payload[DATA1] = data;
}

void PayloadSetData2(uint8_t data)
{
	_payload[DATA2] = data;
}

void PayloadSetBatteryVoltage(uint8_t data)
{
	_payload[Battery] = data;
}


void PayloadReset()
{
	uint8_t i;
	for (i = 0; i < RADIO_PAYLOAD_LENGTH; i++)
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
	for (i = 0; i < RADIO_PAYLOAD_LENGTH; i++)
	{
		_payload[i] ^= _maskByte;
	}
}