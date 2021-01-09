#include "Sensor.h"


void SensorInit()
{
	Switch1_enable_PullUP;
	Switch2_enable_PullUP;
}

void SensorStop()
{
	Switch1_disble_PullUP;
	Switch2_disble_PullUP;
}

uint8_t SensorGet(uint8_t sensorNum)
{
	if (sensorNum == 0)
	{
		if (!Switch1_HIGH)
		return 0x00;
		else
		return 0x01;
	}
	else 	if (sensorNum == 1)
	{
		if (!Switch2_HIGH)
		return 0x00;
		else
		return 0x01;
	}
	else
	{
		return 0x00;
	}
	
}

void SensorSetInterrupt()
{
	
	
}