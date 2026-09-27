#include <iostream>                 // Input/output
#include <string>                   // String
#include <utility>                  // move()

class Employee                       // Base class
{
protected:
    int employeeId;                  // Employee ID
    std::string name;                // Employee name

public:
    Employee(int id, std::string employeeName)
        : employeeId(id), name(std::move(employeeName)) {} // Constructor

    virtual double calculateSalary() const = 0; // Pure virtual function

    void displayBasicDetails() const            // Display details
    {
        std::cout << "Employee ID: " << employeeId << '\n';
        std::cout << "Name: " << name << '\n';
    }

    virtual ~Employee() = default;               // Virtual destructor
};

class PermanentEmployee : public Employee        // Permanent employee
{
private:
    double basicSalary;                           // Basic salary
    double allowance;                             // Allowance

public:
    PermanentEmployee(int id, std::string employeeName,
                      double basic, double extra)
        : Employee(id, std::move(employeeName)),
          basicSalary(basic), allowance(extra) {} // Constructor

    double calculateSalary() const override       // Calculate salary
    {
        return basicSalary + allowance;            // Salary + allowance
    }
};

class ContractEmployee : public Employee         // Contract employee
{
private:
    double hourlyRate;                             // Rate per hour
    int hoursWorked;                               // Hours worked

public:
    ContractEmployee(int id, std::string employeeName,
                     double rate, int hours)
        : Employee(id, std::move(employeeName)),
          hourlyRate(rate), hoursWorked(hours) {}  // Constructor

    double calculateSalary() const override       // Calculate salary
    {
        return hourlyRate * hoursWorked;           // Rate × hours
    }
};

void displayPaySlip(const Employee& employee)     // Display payslip
{
    employee.displayBasicDetails();                // Show details
    std::cout << "Salary: "
              << employee.calculateSalary()       // Calculate salary
              << "\n\n";
}

int main()                                            // Main function
{
    PermanentEmployee permanentEmployee(
        101, "Asha", 40000.0, 8000.0);              // Create permanent employee

    ContractEmployee contractEmployee(
        102, "Vikas", 500.0, 80);                   // Create contract employee

    displayPaySlip(permanentEmployee);              // Show permanent payslip
    displayPaySlip(contractEmployee);               // Show contract payslip

    return 0;                                       // End program
}