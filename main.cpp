/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp, which goes along with instruction 5): 
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
        Chances are extremely high that you implemented your 
        wrapper class functions in-class, because that is what 
        everyone does after watching the video where I implemented 
        them in-class.
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.

 7) When you add the #include statements for your refactored source files into main.cpp: 
        '#include "Wrappers.h"' should be the first file that you include after LeakedObjectDetector.h
 
 8) Go through every cpp file and header file. check all function implementations for the following:
        Can this function argument be declared as 'const'? 
        Can this function be declared as 'const'?
        You learned about 'const' function arguments and 'const' functions in Project 5 Part 3
        As a refresher:
            If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
            Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
            Additionally, you can mark class member functions as 'const'
            If you do this, you are promising that the member function will not modify any member variables.

        Mark every member function that is not modifying any member variables as 'const'
        Mark every function parameter that is not modified inside the function as 'const'
*/
#if false
//a function where the argument is passed by const-ref.
void Foo::someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 9) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */




#include <iostream>
#include "LeakedObjectDetector.h"
#include"Wrappers.h"
/*
 copied UDT 1:
 */
struct CorporateOffice
{
    int numberOfEmployees;
    int numberOfElevators;
    float averageSalary;
    float temperatureSetting;
    std::string address;

    CorporateOffice();
    ~CorporateOffice();

    struct Employee
    {
        std::string name;
        std::string jobTitle;
        std::string department;
        float salary;
        int timeAtCompany;

        Employee();
        ~Employee();

        double clockIn(double timeIn) const;
        double clockOut(double timeOut) const;
        void makeCopies(int numCopies) const;
        float negotiateRaise(float raiseAmount);
        void reportToFirstDay() const;
    };

    void callClient(std::string clientName, const Employee& employee) const;
    void releasePayroll(Employee& employeeOne, Employee& employeeTwo);
    void callSecurity(Employee& securityGuard);

    JUCE_LEAK_DETECTOR(CorporateOffice)
};

CorporateOffice::CorporateOffice() :
numberOfEmployees(100),
numberOfElevators(2),
averageSalary(70000.f),
temperatureSetting(70.f),
address("4321 Main St")
{
    std::cout << "The new corporate office is ready for business!" << std::endl;
}

CorporateOffice::~CorporateOffice()
{
    std::cout << "The corporate office is closed!" << std::endl;
}

CorporateOffice::Employee::Employee() :
name("John Doe"),
jobTitle("Staff"),
department("Administration"),
salary(50000.f),
timeAtCompany(1)
{
    std::cout << "Welcome to the family, " << name << " as the new Emplyee!" << std::endl;
}

CorporateOffice::Employee::~Employee()
{
    std::cout << "The employee has been fired." << std::endl;
}

double CorporateOffice::Employee::clockIn(double timeIn) const
{
    std::cout << "Welcome, " << name <<  " it is " << timeIn << "AM" << std::endl;
    return timeIn;
}

double CorporateOffice::Employee::clockOut(double timeOut) const
{
    //std::cout << "Goodbye, it's " << timeOut << "PM" << std::endl;
    return timeOut;
}

void CorporateOffice::Employee::makeCopies(int numCopies) const
{
    std::cout << "Now printing " << numCopies << " copies for the " << department << " meeting." << std::endl;
}

void CorporateOffice::callClient(std::string clientName, const Employee& employee) const
{
    std::cout << "Now " << employee.name << " is calling " << clientName << std::endl;
}

void CorporateOffice::releasePayroll(Employee& employeeOne, Employee& employeeTwo)
{
    employeeOne.salary += 4000.f;
    employeeTwo.salary += 4000.f;
}

void CorporateOffice::callSecurity(Employee& securityGuard)
{
    securityGuard.name = "THE BOSS, NOW";
}

float CorporateOffice::Employee::negotiateRaise(float raiseAmount)
{
    float newSalary(salary);
    while (newSalary < salary + raiseAmount)
    {
        newSalary+=(raiseAmount*.25f);
        std::cout << name << " says, how about: " << newSalary << std::endl;
    }
    std::cout << "Fine! Get out of my office!" << std::endl;
    salary = newSalary;
    return newSalary;
}

void CorporateOffice::Employee::reportToFirstDay() const
{
    std::cout << "Welcome " << this->name << "! Please report to " << this->department << ". Boy, those " << this->salary << " dollars are gonna be a lot of money! " << std::endl;
}

struct CorporateOfficeWrapper 
{
    CorporateOffice* corporateOfficePtr = nullptr;
    CorporateOfficeWrapper(CorporateOffice* ptrToCorporateOffice) : corporateOfficePtr(ptrToCorporateOffice) 
    {
        std::cout << "Wrapping Corporate Office" << std::endl;
    }
    ~CorporateOfficeWrapper()
    {
        delete corporateOfficePtr;
        std::cout << "Unwrapping Corporate Office" << std::endl;
    }
};
/*
 copied UDT 2:
 */
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

struct PhoneBookWrapper
{
    PhoneBook* phoneBookPtr = nullptr;
    PhoneBookWrapper(PhoneBook* ptrToPhoneBook) : phoneBookPtr(ptrToPhoneBook)
    {
       std::cout << "Wrapping Phonebook" << std::endl; 
    }
    ~PhoneBookWrapper()
    {
        delete phoneBookPtr;
        std::cout << "Unwrapping Phonebook" << std::endl;
    }
};
/*
 copied UDT 3:
 */
struct ElectricHeater
{
    float wattage = 1500.f;
    int numberOfSettings = 3;
    int temperatureSetting;
    char pivotMode = 'A';
    bool powerSavingMode = true;

    ElectricHeater();
    ~ElectricHeater();

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
    };

    void produceHeat();
    void triggerCountdownTimer(float tippingMovement);
    int displayCurrentTemperature() const;
    void setPhonebookOnFire(PhoneBook& phoneBookToBurn);

    JUCE_LEAK_DETECTOR(ElectricHeater)
};

ElectricHeater::ElectricHeater() :
temperatureSetting(72)
{
    std::cout << "Firing up new heater!" << std::endl;
}

ElectricHeater::~ElectricHeater()
{
    std::cout << "The electric heater has been turned off." << std::endl;
}

ElectricHeater::HeatingElement::HeatingElement()
{
    std::cout << "New heating element added!" << std::endl;
}

ElectricHeater::HeatingElement::~HeatingElement()
{
    std::cout << "The heating element has been removed." << std::endl;
}

void ElectricHeater::HeatingElement::slowCoolDown(int coolDownTime) const
{
    std::cout << "It's time to cool down, it will take " << layoutType << " coil " << coolDownTime << "seconds to cool down." << std::endl;
}

void ElectricHeater::HeatingElement::slowHeatUp(int heatUpTime) const
{
    std::cout << "It's time to heat up, it will take " << heatUpTime << "seconds" << std::endl;
}

void ElectricHeater::HeatingElement::changeTemperature(int newTemperature)
{
    voltage = 0;
    std::cout << "Haha gotcha, you wanted " << newTemperature << std::endl;
}

void ElectricHeater::produceHeat()
{
    powerSavingMode = false;
    std::cout << "Now producing heat, temperature setting is " << temperatureSetting << std::endl;
}

void ElectricHeater::triggerCountdownTimer(float tippingMovement)
{
    if (tippingMovement > 0.5f)
    {
        powerSavingMode = true;
    }
}

int ElectricHeater::displayCurrentTemperature() const
{
    std::cout << "Current temperature is " << temperatureSetting << std::endl;
    return temperatureSetting;
}

void ElectricHeater::setPhonebookOnFire(PhoneBook& phoneBookToBurn)
{
    phoneBookToBurn.numberOfPages = 8;
    for (; phoneBookToBurn.numberOfPages > 0; --phoneBookToBurn.numberOfPages)
    {
        std::cout << "Burning page " << phoneBookToBurn.numberOfPages << std::endl;
    }
}

struct ElectricHeaterWrapper
{
    ElectricHeater* electricHeaterPtr = nullptr;
    ElectricHeaterWrapper(ElectricHeater* ptrToElectricHeater) : electricHeaterPtr(ptrToElectricHeater)
    {
        std::cout << "Wrapping Electric Heater" << std::endl;
    }
    ~ElectricHeaterWrapper()
    {
        delete electricHeaterPtr;
        std::cout << "Unwrapping Electric Heater" << std::endl;
    }
};
/*
 new UDT 4:
 with 2 member functions
 */
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

struct ApartmentWrapper
{
    Apartment* apartmentPtr = nullptr;
    ApartmentWrapper(Apartment* ptrToApartment) : apartmentPtr(ptrToApartment)
    {
        std::cout << "Wrapping Apartment" << std::endl;
    }
    ~ApartmentWrapper()
    {
        delete apartmentPtr;
        std::cout << "Unwrapping Apartment" << std::endl;
    }
};
/*
 new UDT 5:
 with 2 member functions
 */
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

struct FieldOfficeWrapper
{
    FieldOffice* fieldOfficePtr = nullptr;
    FieldOfficeWrapper(FieldOffice* ptrToFieldOffice) : fieldOfficePtr(ptrToFieldOffice)
    {
        std::cout << "Wrapping Field Office" << std::endl;
    }
    ~FieldOfficeWrapper()
    {
        delete fieldOfficePtr;
        std::cout << "Unwrapping Field Office" << std::endl;
    }
};
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    CorporateOfficeWrapper orphanCrushingMachineInc( new CorporateOffice() );

    CorporateOffice::Employee jackie;

    jackie.name = "Jackie";
    jackie.clockIn(9.0);
    jackie.clockOut(17.0);
    jackie.makeCopies(20);
    jackie.negotiateRaise(5000);

    orphanCrushingMachineInc.corporateOfficePtr->callClient("HYLLLIC", jackie);
    orphanCrushingMachineInc.corporateOfficePtr->releasePayroll(jackie, jackie);
    orphanCrushingMachineInc.corporateOfficePtr->callSecurity(jackie);

    std::cout << "Welcome " << jackie.name << "! Please report to " << jackie.department << ". Boy, those " << jackie.salary << " dollars are gonna be a lot of money! " << std::endl;

    jackie.reportToFirstDay();

    PhoneBookWrapper olYellowPages( new PhoneBook() );

    olYellowPages.phoneBookPtr->contactInformationDiplay("HYLLLIC INC");
    olYellowPages.phoneBookPtr->openToRandomPage();
    olYellowPages.phoneBookPtr->disintigrate();
    olYellowPages.phoneBookPtr->tearOutPages();

    ElectricHeaterWrapper heater( new ElectricHeater() );

    heater.electricHeaterPtr->produceHeat();
    heater.electricHeaterPtr->triggerCountdownTimer(0.5f);
    heater.electricHeaterPtr->displayCurrentTemperature();
    heater.electricHeaterPtr->setPhonebookOnFire(*olYellowPages.phoneBookPtr);

    ElectricHeater::HeatingElement newCoil;

    newCoil.slowCoolDown(10);
    newCoil.slowHeatUp(10);
    newCoil.changeTemperature(80);

    ApartmentWrapper hollywoodApartment( new Apartment() );
    
    hollywoodApartment.apartmentPtr->makeApartmentCozy();
    hollywoodApartment.apartmentPtr->swatABugAndRant();
    
    std::cout << "Later that night, after logging off at " << hollywoodApartment.apartmentPtr->rachel.clockOut(7.00) << " power saving mode was made " << std::boolalpha << (hollywoodApartment.apartmentPtr->spaceHeater.powerSavingMode = true) << std::endl;

    hollywoodApartment.apartmentPtr->logOffAndShutDown();

    FieldOfficeWrapper shorelineFieldOffice( new FieldOffice() );
    
    shorelineFieldOffice.fieldOfficePtr->meetWithOwner();
    shorelineFieldOffice.fieldOfficePtr->wrapUpWorkDay();

    std::cout << "The field office is located at " << (shorelineFieldOffice.fieldOfficePtr->katastrophe.address = "123 Middle of Nowhere") << std::endl;

    shorelineFieldOffice.fieldOfficePtr->defineFieldOfficeAddress("123 Middle of Nowhere");
    
    //==============================
    std::cout << "good to go!" << std::endl;
}
