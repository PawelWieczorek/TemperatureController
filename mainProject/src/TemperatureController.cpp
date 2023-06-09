#include "TemperatureController.h"
#include <stdexcept>

//Constructor

TemperatureController::TemperatureController(TemperatureMeter* meter, int minTemp, int maxTemp)
{
	if (!meter)
	{
		throw new std::invalid_argument("Temperature measure handler cannot be NULL!");
	}

	if (minTemp > maxTemp)
	{
		throw new std::invalid_argument("Minimum temperature must be less than or equal maximum temperature!");
	}

	this->meter = meter;
	this->minTemp = minTemp;
	this->maxTemp = maxTemp;
}

//Setters

void TemperatureController::setMaxTemp(int maxTemp)
{
	if (maxTemp < this->minTemp)
	{
		throw new std::invalid_argument("Maximum temperature must be greater than or equal minimum temperature!");
	}

	this->maxTemp = maxTemp;
}

void TemperatureController::setMinTemp(int minTemp)
{
	if (minTemp < this->maxTemp)
	{
		throw new std::invalid_argument("Minimum temperature must be less than or equal maximum temperature!");
	}

	this->minTemp = minTemp;
}

//Getters

std::string TemperatureController::getState() const
{
    if(this->cooling && this-> heating)
    {
        throw new std::invalid_argument("Cannot heat and cool in the same moment!");
    }

    return this->heating ? "Heating" : this->cooling ? "Cooling" : "Idle";
}

int TemperatureController::getMaxTemp() const {
    return this->maxTemp;
}

int TemperatureController::getMinTemp() const {
    return this->minTemp;
}

bool TemperatureController::isCooling() const {
    return this->cooling;
}

bool TemperatureController::isHeating() const {
    return this->heating;
}

//Logic

void TemperatureController::control()
{
    int temp = this->meter->measureTemperature();

    if (temp > this->maxTemp && !this->cooling)
    {
        this->cooling = true;
        this->heating = false;
    }

    if (temp < this->minTemp && !this->heating)
    {
        this->heating = true;
        this->cooling = false;
    }
}
