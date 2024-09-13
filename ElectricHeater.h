#pragma once

#include "LeakedObjectDetector.h"

struct ElectricHeater
{
    struct HeatingElement
    {
        HeatingElement();
        ~HeatingElement();

        int resistance = 10;
        int voltage = 120;
        float elementLength = 24.0f;
        std::string supportType = "Embedded";
        std::string layoutType = "Open Coil";

        void slowCoolDown(int coolDownTime = 10) const;
        void slowHeatUp(int heatUpTime = 10) const;
        void changeTemperature(int newTemperature);

        JUCE_LEAK_DETECTOR(HeatingElement)
    };

    float wattage = 1500.f;
    int numberOfSettings = 3;
    int temperatureSetting;
    char pivotMode = 'A';
    bool powerSavingMode = true;

    ElectricHeater();
    ~ElectricHeater();

    void produceHeat();
    void triggerCountdownTimer(float tippingMovement);
    int displayCurrentTemperature() const;
    void setPhonebookOnFire(PhoneBook& phoneBookToBurn);

    JUCE_LEAK_DETECTOR(ElectricHeater)
};