#include "ElectricHeater.h"
#include "PhoneBook.h"

ElectricHeater::ElectricHeater() :
temperatureSetting(72)
{
    std::cout << "Firing up new heater!" << std::endl;
}

ElectricHeater::~ElectricHeater()
{
    std::cout << "The electric heater has been turned off." << std::endl;
}

ElectricHeater::HeatingElement::HeatingElement()
{
    std::cout << "New heating element added!" << std::endl;
}

ElectricHeater::HeatingElement::~HeatingElement()
{
    std::cout << "The heating element has been removed." << std::endl;
}

void ElectricHeater::HeatingElement::slowCoolDown(int coolDownTime) const
{
    std::cout << "It's time to cool down, it will take " << layoutType << " coil " << coolDownTime << "seconds to cool down." << std::endl;
}

void ElectricHeater::HeatingElement::slowHeatUp(int heatUpTime) const
{
    std::cout << "It's time to heat up, it will take " << heatUpTime << "seconds" << std::endl;
}

void ElectricHeater::HeatingElement::changeTemperature(int newTemperature)
{
    voltage = 0;
    std::cout << "Haha gotcha, you wanted " << newTemperature << std::endl;
}

void ElectricHeater::produceHeat()
{
    powerSavingMode = false;
    std::cout << "Now producing heat, temperature setting is " << temperatureSetting << std::endl;
}

void ElectricHeater::triggerCountdownTimer(float tippingMovement)
{
    if (tippingMovement > 0.5f)
    {
        powerSavingMode = true;
    }
}

int ElectricHeater::displayCurrentTemperature() const
{
    std::cout << "Current temperature is " << temperatureSetting << std::endl;
    return temperatureSetting;
}

void ElectricHeater::setPhonebookOnFire(PhoneBook& phoneBookToBurn)
{
    phoneBookToBurn.numberOfPages = 8;
    for (; phoneBookToBurn.numberOfPages > 0; --phoneBookToBurn.numberOfPages)
    {
        std::cout << "Burning page " << phoneBookToBurn.numberOfPages << std::endl;
    }
}
