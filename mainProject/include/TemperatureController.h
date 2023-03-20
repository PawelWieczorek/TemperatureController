#pragma once

#include <string>
#include "TemperatureMeter.h"

class TemperatureController
{
	int maxTemp;
	int minTemp;
	TemperatureMeter* meter = nullptr;

	bool cooling = false;
	bool heating = false;

public:

	explicit TemperatureController(TemperatureMeter* meter, int minTemp = 22, int maxTemp = 25);
	virtual ~TemperatureController() = default;

	void setMaxTemp(int maxTemp);
	void setMinTemp(int MinTemp);

    int getMaxTemp() const;
    int getMinTemp() const;
    std::string getState() const;
    bool isCooling() const;
    bool isHeating() const;

    void control();
};
