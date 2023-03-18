#pragma once

class TemperatureController
{
	int maxTemp;
	int minTemp;
	int (*getTemperature)() = nullptr;

	bool cooling = false;
	bool heating = false;

public:

	explicit TemperatureController(int (*getTemperature)(), int minTemp = 22, int maxTemp = 25);
	virtual ~TemperatureController() = default;

	void setMaxTemp(int maxTemp);
	void setMinTemp(int MinTemp);

    int getMaxTemp() const;
    int getMinTemp() const;
    int getState() const;
    bool isCooling() const;
    bool isHeating() const;

    void control();
};
