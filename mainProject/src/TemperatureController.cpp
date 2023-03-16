#include "TemperatureController.hpp"
#include <stdexcept>

int TemperatureController::getState()
{
	if(this->cooling && this-> heating)
	{
		throw new std::invalid_argument("Cannot heat and cool in the same moment!");
	}

	return this->heating ? 1 : this->cooling ? -1 : 0;
}

TemperatureController::TemperatureController(int (*getTemperature)(), int minTemp, int maxTemp)
{
	if (!getTemperature)
	{
		throw new std::invalid_argument("Temperature measure handler cannot be NULL!");
	}

	if (minTemp > maxTemp)
	{
		throw new std::invalid_argument("Minimum temperature must be lesser or equal maximum temperature!");
	}

	this->getTemperature = getTemperature;
	this->minTemp = minTemp;
	this->maxTemp = maxTemp;
}

void TemperatureController::setMaxTemp(int maxTemp)
{
	if (maxTemp < this->minTemp)
	{
		throw new std::invalid_argument("Maximum temperature must be greater or equal minimum temperature!");
	}

	this->maxTemp = maxTemp;
}

void TemperatureController::setMinTemp(int minTemp)
{
	if (minTemp < this->maxTemp)
	{
		throw new std::invalid_argument("Minimum temperature must be lesser or equal maximum temperature!");
	}

	this->minTemp = minTemp;
}
