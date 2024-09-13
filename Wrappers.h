#pragma once

#include "Apartment.h"
#include "CorporateOffice.h"
#include "ElectricHeater.h"
#include "FieldOffice.h"
#include "PhoneBook.h"

struct Apartment;
struct CorporateOffice;
struct ElectricHeater;
struct PhoneBook;

struct CorporateOfficeWrapper 
{
    CorporateOffice* corporateOfficePtr = nullptr;

    CorporateOfficeWrapper(CorporateOffice* ptrToCorporateOffice);
    ~CorporateOfficeWrapper();
};

struct PhoneBookWrapper
{
    PhoneBook* phoneBookPtr = nullptr;

    PhoneBookWrapper(PhoneBook* ptrToPhoneBook);
    ~PhoneBookWrapper();
};

struct ElectricHeaterWrapper
{
    ElectricHeater* electricHeaterPtr = nullptr;

    ElectricHeaterWrapper(ElectricHeater* ptrToElectricHeater);
    ~ElectricHeaterWrapper();
};

struct ApartmentWrapper
{
    Apartment* apartmentPtr = nullptr;

    ApartmentWrapper(Apartment* ptrToApartment);
    ~ApartmentWrapper();
};

struct FieldOfficeWrapper
{
    FieldOffice* fieldOfficePtr = nullptr;

    FieldOfficeWrapper(FieldOffice* ptrToFieldOffice);
    ~FieldOfficeWrapper();
};
