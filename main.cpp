/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via the 'this' keyword and arrow (->) operator and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 Instructions:
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.

 2) Do the following for EVERY std::cout statement in main() that uses the UDT member variables and functions:
    a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
    b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
    c) call that member function AFTER your std::cout statement in main.
    NOTE: if your member functions being called in main() use std::cout statements, you don't need to create duplicates of these functions.  you only need to create member functions for the std::cout statements that exist in main().
        
 3) you should see 2 (almost) identical messages in the program output for each member function you add:
    one for the std::cout line, and one for the member function's output
 
 4) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo();
        ~MyFoo();
        
        void printDetailedMemberInfo();
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };

    MyFoo::MyFoo() { std::cout << "creating MyFoo" << std::endl; }
    MyFoo::~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
	// 2a) the member function whose function body is almost identical to the std::cout statement in main.
    //Remember to NAME FUNCTIONS WHAT THEY DO.
    void MyFoo::printDetailedMemberInfo() //function name contains a verb!!!
    { 
        // 2b) explicitly using 'this' inside this member function.
        std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
    }  
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.printDetailedMemberInfo();
        return 0;
    }
}

/*

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.
*/

#include <iostream>
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

        double clockIn(double timeIn);
        double clockOut(double timeOut);
        void makeCopies(int numCopies);
        float negotiateRaise(float raiseAmount);
        void firstDayExcitement();
    };

    void callClient(std::string clientName, Employee employee);
    void releasePayroll(Employee employeeOne, Employee employeeTwo);
    void callSecurity(Employee securityGuard);
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

double CorporateOffice::Employee::clockIn(double timeIn)
{
    std::cout << "Welcome, " << name <<  " it is " << timeIn << "AM" << std::endl;
    return timeIn;
}

double CorporateOffice::Employee::clockOut(double timeOut)
{
    //std::cout << "Goodbye, it's " << timeOut << "PM" << std::endl;
    return timeOut;
}

void CorporateOffice::Employee::makeCopies(int numCopies)
{
    std::cout << "Now printing " << numCopies << " copies for the " << department << " meeting." << std::endl;
}

void CorporateOffice::callClient(std::string clientName, Employee employee)
{
    std::cout << "Now " << employee.name << " is calling " << clientName << std::endl;
}

void CorporateOffice::releasePayroll(Employee employeeOne, Employee employeeTwo)
{
    employeeOne.salary += 4000.f;
    employeeTwo.salary += 4000.f;
}

void CorporateOffice::callSecurity(Employee securityGuard)
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
    return newSalary;
}

void CorporateOffice::Employee::firstDayExcitement()
{
    std::cout << "Welcome " << this->name << "! Please report to " << this->department << ". Boy, those " << this->salary << " dollars are gonna be a lot of money! " << std::endl;
}
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

    std::string contactInformationDiplay(std::string contactName);
    void openToRandomPage();
    void disintigrate();
    int tearOutPages();
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

std::string PhoneBook::contactInformationDiplay(std::string contactName)
{
    std::string phoneNumber = contactName + " 555-5555";
    return phoneNumber;
}

void PhoneBook::openToRandomPage()
{
    int min = 1;
    int max = numberOfPages;
    int randomNumber = rand() % (max - min + 1) + min;
    std::cout << "Opening page, out of " << numberOfPages << " pages, we open to "<< randomNumber << std::endl;
}

void PhoneBook::disintigrate()
{
    std::cout << "Uahghghgllll the " << telephoneCompany << " phone book is disintigrating" << std::endl;
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
    return numberOfPages;
}
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

        void slowCoolDown(int coolDownTime = 10);
        void slowHeatUp(int heatUpTime = 10);
        void changeTemperature(int newTemperature);
    };

    void produceHeat();
    void triggerCountdownTimer(float tippingMovement);
    int displayCurrentTemperature();
    void setPhonebookOnFire(PhoneBook phoneBookToBurn);
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

void ElectricHeater::HeatingElement::slowCoolDown(int coolDownTime)
{
    std::cout << "It's time to cool down, it will take " << layoutType << " coil " << coolDownTime << "seconds to cool down." << std::endl;
}

void ElectricHeater::HeatingElement::slowHeatUp(int heatUpTime)
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

int ElectricHeater::displayCurrentTemperature()
{
    std::cout << "Current temperature is " << temperatureSetting << std::endl;
    return temperatureSetting;
}

void ElectricHeater::setPhonebookOnFire(PhoneBook phoneBookToBurn)
{
    phoneBookToBurn.numberOfPages = 8;
    for (; phoneBookToBurn.numberOfPages > 0; --phoneBookToBurn.numberOfPages)
    {
        std::cout << "Burning page " << phoneBookToBurn.numberOfPages << std::endl;
    }
}
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

    void makeItCozy();
    void swatABug();
    void sleepPowerSavingMode();
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

void Apartment::makeItCozy()
{
    spaceHeater.temperatureSetting = 80;
    spaceHeater.produceHeat();
    rachel.jobTitle = "Bug in a rug";
    std::cout << "The apartment is toasty at " << spaceHeater.temperatureSetting << std::endl;
}

void Apartment::swatABug()
{
    rachel.department = "Pest Control";
    rachel.jobTitle = "Death, Destroyer of Bugs";
    trustyPhoneBook.disintigrate();
    std::cout << "The phone book was lost, but I have become " << rachel.jobTitle << std::endl;
}

void Apartment::sleepPowerSavingMode()
{
    std::cout << "Later that night, after logging off at " << this->rachel.clockOut(7.00) << " power saving mode was made " << std::boolalpha << (this->spaceHeater.powerSavingMode = true) << std::endl;
}
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

    void morningStandUp();
    void shutDownForTheDay();
    void newFieldOfficeAddress(std::string newAddress);
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

void FieldOffice::morningStandUp()
{
    katastrophe.callClient("The Owner", patrick);
    std::cout << "The morning standup is over, the PM has called the owner." << std::endl;
}

void FieldOffice::shutDownForTheDay()
{
    patrick.clockOut(19.00);
    std::cout << "The day is over, Patrick the PM has clocked out." << std::endl;
}

void FieldOffice::newFieldOfficeAddress(std::string newAddress)
{
    this->katastrophe.address = newAddress;
    std::cout << "The field office is located at " << newAddress << std::endl;
}
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
    CorporateOffice orphanCrushingMachineInc;

    CorporateOffice::Employee jackie;

    jackie.name = "Jackie";
    jackie.clockIn(9.0);
    jackie.clockOut(17.0);
    jackie.makeCopies(20);
    jackie.negotiateRaise(5000);

    orphanCrushingMachineInc.callClient("HYLLLIC", jackie);
    orphanCrushingMachineInc.releasePayroll(jackie, jackie);
    orphanCrushingMachineInc.callSecurity(jackie);

    std::cout << "Welcome " << jackie.name << "! Please report to " << jackie.department << ". Boy, those " << jackie.salary << " dollars are gonna be a lot of money! " << std::endl;

    jackie.firstDayExcitement();

    PhoneBook olYellowPages;

    olYellowPages.contactInformationDiplay("HYLLLIC INC");
    olYellowPages.openToRandomPage();
    olYellowPages.disintigrate();
    olYellowPages.tearOutPages();

    ElectricHeater heater;

    heater.produceHeat();
    heater.triggerCountdownTimer(0.5f);
    heater.displayCurrentTemperature();
    heater.setPhonebookOnFire(olYellowPages);

    ElectricHeater::HeatingElement newCoil;

    newCoil.slowCoolDown(10);
    newCoil.slowHeatUp(10);
    newCoil.changeTemperature(80);

    Apartment hollywoodApartment;
    
    hollywoodApartment.makeItCozy();
    hollywoodApartment.swatABug();
    
    std::cout << "Later that night, after logging off at " << hollywoodApartment.rachel.clockOut(7.00) << " power saving mode was made " << std::boolalpha << (hollywoodApartment.spaceHeater.powerSavingMode = true) << std::endl;

    hollywoodApartment.sleepPowerSavingMode();

    FieldOffice shorelineFieldOffice;
    
    shorelineFieldOffice.morningStandUp();
    shorelineFieldOffice.shutDownForTheDay();

    std::cout << "The field office is located at " << (shorelineFieldOffice.katastrophe.address = "123 Middle of Nowhere") << std::endl;

    shorelineFieldOffice.newFieldOfficeAddress("123 Middle of Nowhere");
    
    //==============================
    std::cout << "good to go!" << std::endl;
}
