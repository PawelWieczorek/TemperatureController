#pragma once

class TemperatureMeter
{
public:
    virtual ~TemperatureMeter() {};
    virtual int measureTemperature(void) = 0;

};
