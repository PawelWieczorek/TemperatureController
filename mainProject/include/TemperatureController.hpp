#pragma once
#include <stdlib.h>

class TemperatureController
{
	int maxTemp;
	int minTemp;
	int (*getTemperature)() = NULL;

	bool cooling = false;
	bool heating = false;

public:

	TemperatureController(int (*getTemperature)(), int minTemp = 22, int maxTemp = 25);
	virtual ~TemperatureController() {};

	int getState();
	void control();

	void setMaxTemp(int maxTemp);
	void setMinTemp(int MinTemp);

};
