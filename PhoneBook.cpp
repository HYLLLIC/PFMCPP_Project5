#include "PhoneBook.h"

PhoneBook::PhoneBook() :
numberOfPages(1000),
bookWeight(2.2f),
telephoneCompany("Yellowpages"),
bookAge(3.1f),
glueStrength(1.7f)
{
    std::cout << "Delivering new Phonebook!" << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << "The Phonebook has been thrown away." << std::endl;
}

std::string PhoneBook::contactInformationDiplay(std::string contactName) const
{
    std::string phoneNumber = contactName + " 555-5555";
    return phoneNumber;
}

void PhoneBook::openToRandomPage() const
{
    int min = 1;
    int max = numberOfPages;
    int randomNumber = rand() % (max - min + 1) + min;
    std::cout << "Opening page, out of " << numberOfPages << " pages, we open to "<< randomNumber << std::endl;
}

void PhoneBook::disintigrate()
{
    std::cout << "Uahghghgllll the " << telephoneCompany << " phone book is disintigrating" << std::endl;
    numberOfPages = 0;
}

int PhoneBook::tearOutPages()
{
    int pagesTorn = 0;
    while (pagesTorn < numberOfPages)
    {
        int pagesToTear = (numberOfPages - pagesTorn) / 2 + 25;
        if (pagesTorn + pagesToTear > numberOfPages) 
        {
            pagesTorn = numberOfPages; 
        }
        {
            pagesTorn += pagesToTear;
            std::cout << "Tearing out " << pagesToTear << " pages." << std::endl;
        }
    }
    numberOfPages -= pagesTorn;
    return numberOfPages;
}