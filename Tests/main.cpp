#include <iostream>
#include "TemperatureController.h"
#include "TemperatureMeasurementDevice.h"

int main()
{
    TemperatureMeasurementDevice* tmd = new TemperatureMeasurementDevice();
    TemperatureController controller(tmd);
    std::cout << controller.getState() << "\n";

    controller.control();

    std::cout << controller.getState() << "\n";


    std::cout << "Test functionality";
    return 0;
}
