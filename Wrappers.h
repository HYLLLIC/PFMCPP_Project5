#pragma once


struct CorporateOfficeWrapper 
{
    CorporateOffice* corporateOfficePtr = nullptr;
    CorporateOfficeWrapper(CorporateOffice* ptrToCorporateOffice) : corporateOfficePtr(ptrToCorporateOffice) 
    {
    }
    ~CorporateOfficeWrapper()
    {
    }
};

struct PhoneBookWrapper
{
    PhoneBook* phoneBookPtr = nullptr;
    PhoneBookWrapper(PhoneBook* ptrToPhoneBook) : phoneBookPtr(ptrToPhoneBook)
    {
    }
    ~PhoneBookWrapper()
    {
    }
};

struct ElectricHeaterWrapper
{
    ElectricHeater* electricHeaterPtr = nullptr;
    ElectricHeaterWrapper(ElectricHeater* ptrToElectricHeater) : electricHeaterPtr(ptrToElectricHeater)
    {
    }
    ~ElectricHeaterWrapper()
    {
    }
};

struct ApartmentWrapper
{
    Apartment* apartmentPtr = nullptr;
    ApartmentWrapper(Apartment* ptrToApartment) : apartmentPtr(ptrToApartment)
    {
    }
    ~ApartmentWrapper()
    {
    }
};

struct FieldOfficeWrapper
{
    FieldOffice* fieldOfficePtr = nullptr;
    FieldOfficeWrapper(FieldOffice* ptrToFieldOffice) : fieldOfficePtr(ptrToFieldOffice)
    {
    }
    ~FieldOfficeWrapper()
    {
    }
};