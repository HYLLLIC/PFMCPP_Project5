#pragma once

#include "LeakedObjectDetector.h"
#include "PhoneBook.h"
#include "ElectricHeater.h"
#include "CorporateOffice.h"

struct Apartment
{
    ElectricHeater spaceHeater;
    PhoneBook trustyPhoneBook;
    CorporateOffice::Employee rachel;

    Apartment();
    ~Apartment();

    void makeApartmentCozy();
    void swatABugAndRant();
    void logOffAndShutDown();

    JUCE_LEAK_DETECTOR(Apartment)
};