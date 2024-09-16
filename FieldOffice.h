#pragma once

#include "LeakedObjectDetector.h"
#include "CorporateOffice.h"
#include "ElectricHeater.h"

struct FieldOffice
{
    CorporateOffice katastrophe;
    CorporateOffice::Employee patrick;
    ElectricHeater rentalHeater;

    FieldOffice();
    ~FieldOffice();

    void meetWithOwner() const;
    void wrapUpWorkDay() const;
    void defineFieldOfficeAddress(std::string newAddress);

    JUCE_LEAK_DETECTOR(FieldOffice)
};
