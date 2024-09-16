#include "Wrappers.h"
#include "Apartment.h"
#include "FieldOffice.h"

CorporateOfficeWrapper::CorporateOfficeWrapper(CorporateOffice* ptrToCorporateOffice) : corporateOfficePtr(ptrToCorporateOffice) 
{
    std::cout << "Wrapping Corporate Office" << std::endl;
}
CorporateOfficeWrapper::~CorporateOfficeWrapper()
{
    delete corporateOfficePtr;
    std::cout << "Unwrapping Corporate Office" << std::endl;
}

PhoneBookWrapper::PhoneBookWrapper(PhoneBook* ptrToPhoneBook) : phoneBookPtr(ptrToPhoneBook)
{
   std::cout << "Wrapping Phonebook" << std::endl; 
}
PhoneBookWrapper::~PhoneBookWrapper()
{
    delete phoneBookPtr;
    std::cout << "Unwrapping Phonebook" << std::endl;
}

ElectricHeaterWrapper::ElectricHeaterWrapper(ElectricHeater* ptrToElectricHeater) : electricHeaterPtr(ptrToElectricHeater)
{
    std::cout << "Wrapping Electric Heater" << std::endl;
}
ElectricHeaterWrapper::~ElectricHeaterWrapper()
{
    delete electricHeaterPtr;
    std::cout << "Unwrapping Electric Heater" << std::endl;
}

ApartmentWrapper::ApartmentWrapper(Apartment* ptrToApartment) : apartmentPtr(ptrToApartment)
{
    std::cout << "Wrapping Apartment" << std::endl;
}
ApartmentWrapper::~ApartmentWrapper()
{
    delete apartmentPtr;
    std::cout << "Unwrapping Apartment" << std::endl;
}

FieldOfficeWrapper::FieldOfficeWrapper(FieldOffice* ptrToFieldOffice) : fieldOfficePtr(ptrToFieldOffice)
{
    std::cout << "Wrapping Field Office" << std::endl;
}
FieldOfficeWrapper::~FieldOfficeWrapper()
{
    delete fieldOfficePtr;
    std::cout << "Unwrapping Field Office" << std::endl;
}
