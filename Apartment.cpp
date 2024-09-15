#include "Apartment.h"

Apartment::Apartment()
{
    rachel.negotiateRaise(5000.f);
    std::cout << "Rachel can move in now that she makes $" << rachel.salary << std::endl;
}

Apartment::~Apartment()
{
    spaceHeater.setPhonebookOnFire(trustyPhoneBook);
    std::cout << "Oh no! After the fire, Rachel must move out!" << std::endl;
}

void Apartment::makeApartmentCozy()
{
    spaceHeater.temperatureSetting = 80;
    spaceHeater.produceHeat();
    rachel.jobTitle = "Bug in a rug";
    std::cout << "The apartment is toasty at " << spaceHeater.temperatureSetting << std::endl;
}

void Apartment::swatABugAndRant()
{
    rachel.department = "Pest Control";
    rachel.jobTitle = "Death, Destroyer of Bugs";
    trustyPhoneBook.disintigrate();
    std::cout << "The phone book was lost, but I have become " << rachel.jobTitle << std::endl;
}

void Apartment::logOffAndShutDown()
{
    std::cout << "Later that night, after logging off at " << this->rachel.clockOut(7.00) << " power saving mode was made " << std::boolalpha << (this->spaceHeater.powerSavingMode = true) << std::endl;
}
