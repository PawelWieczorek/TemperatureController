#pragma once

#include "TemperatureMeter.h"

class TemperatureMeasurementDevice : public TemperatureMeter {

public:
    virtual ~TemperatureMeasurementDevice() {}
    virtual int measureTemperature(void) override;

};

