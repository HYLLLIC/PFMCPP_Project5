#pragma once

#include "LeakedObjectDetector.h"

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
