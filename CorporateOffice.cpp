#include "CorporateOffice.h"

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
        newSalary += (raiseAmount * .25f);
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
