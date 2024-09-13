#include "FieldOffice.h"

FieldOffice::FieldOffice()
{
    ++katastrophe.numberOfEmployees;
    patrick.jobTitle = "Project Manager";
    std::cout << "A new employee has opened a field office, there are now " << katastrophe.numberOfEmployees << " employees." << std::endl;
}

FieldOffice::~FieldOffice()
{
    katastrophe.numberOfEmployees = 2;
    std::cout << "The field office has been closed, but there are still " << katastrophe.numberOfEmployees << " employees left." << std::endl;
}

void FieldOffice::meetWithOwner() const
{
    katastrophe.callClient("The Owner", patrick);
    std::cout << "The morning standup is over, the PM has called the owner." << std::endl;
}

void FieldOffice::wrapUpWorkDay() const
{
    patrick.clockOut(19.00);
    std::cout << "The day is over, Patrick the PM has clocked out." << std::endl;
}

void FieldOffice::defineFieldOfficeAddress(std::string newAddress)
{
    this->katastrophe.address = newAddress;
    std::cout << "The field office is located at " << newAddress << std::endl;
}