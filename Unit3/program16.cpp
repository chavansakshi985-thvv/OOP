#include <iostream>  // Input/output
#include <string>    // String
#include <utility>   // std::move

class Employee {
protected:
    int employeeId;       // Employee ID
    std::string name;     // Employee name

public:
    // Constructor
    Employee(int id, std::string employeeName)
        : employeeId(id), name(std::move(employeeName)) {}

    // Pure virtual function
    virtual double calculateSalary() const = 0;

    // Display basic details
    void displayBasicDetails() const {
        std::cout << "Employee ID: " << employeeId << '\n';
        std::cout << "Name: " << name << '\n';
    }

    // Virtual destructor
    virtual ~Employee() = default;
};

class PermanentEmployee : public Employee {
private:
    double basicSalary;  // Basic salary
    double allowance;    // Allowance

public:
    // Constructor
    PermanentEmployee(int id, std::string employeeName,
                      double basic, double extra)
        : Employee(id, std::move(employeeName)),
          basicSalary(basic), allowance(extra) {}

    // Calculate salary
    double calculateSalary() const override {
        return basicSalary + allowance;
    }
};

class ContractEmployee : public Employee {
private:
    double hourlyRate;  // Rate per hour
    int hoursWorked;    // Hours worked

public:
    // Constructor
    ContractEmployee(int id, std::string employeeName,
                     double rate, int hours)
        : Employee(id, std::move(employeeName)),
          hourlyRate(rate), hoursWorked(hours) {}

    // Calculate salary
    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
};

// Display employee pay slip
void printPaySlip(const Employee& employee) {
    employee.displayBasicDetails();
    std::cout << "Salary: Rs. "
              << employee.calculateSalary() << "\n\n";
}

int main() {
    // Create employees
    PermanentEmployee permanentEmployee(101, "Asha", 40000.0, 8000.0);
    ContractEmployee contractEmployee(102, "Vikas", 500.0, 80);

    // Display pay slips
    printPaySlip(permanentEmployee);
    printPaySlip(contractEmployee);

    return 0;  // End program
}