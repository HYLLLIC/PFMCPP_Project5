/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================     
 If you completed Project 3:
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

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

        void clockIn(double timeIn);
        void clockOut(double timeOut);
        void makeCopies(int numCopies);
        float negotiateRaise(float raiseAmount);
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

void CorporateOffice::Employee::clockIn(double timeIn)
{
    std::cout << "Welcome, " << name <<  " it is " << timeIn << "AM" << std::endl;
}

void CorporateOffice::Employee::clockOut(double timeOut)
{
    std::cout << "Goodbye, it's " << timeOut << "PM" << std::endl;
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

    std::cout << "Welcome " << jackie.name << "! Please report to " << jackie.department << std::endl;

    std::cout << "Boy, those " << jackie.salary << " dollars are gonna be a lot of money! " << std::endl;

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

    FieldOffice shorelineFieldOffice;
    
    shorelineFieldOffice.morningStandUp();
    shorelineFieldOffice.shutDownForTheDay();
    
    //==============================
    std::cout << "good to go!" << std::endl;
}
