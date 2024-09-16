#pragma once

#include "LeakedObjectDetector.h"

struct PhoneBook
{
    int numberOfPages;
    float bookWeight;
    std::string telephoneCompany;
    float bookAge;
    float glueStrength;

    PhoneBook();
    ~PhoneBook();

    std::string contactInformationDiplay(std::string contactName) const;
    void openToRandomPage() const;
    void disintigrate();
    int tearOutPages();

    JUCE_LEAK_DETECTOR(PhoneBook)
};
