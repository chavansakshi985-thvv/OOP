#include <iostream>                 // Input/output
#include <string>                   // String
#include <utility>                  // move()

class Person                         // Base class
{
protected:
    std::string name;                // Person name

public:
    explicit Person(std::string personName)
        : name(std::move(personName)) {} // Constructor

    void showPerson() const          // Display person
    {
        std::cout << "Name: " << name << '\n';
    }
};

class Employee : public Person       // Inherits Person
{
protected:
    int employeeId;                  // Employee ID

public:
    Employee(std::string employeeName, int id)
        : Person(std::move(employeeName)), employeeId(id) {} // Constructor

    void showEmployee() const        // Display employee
    {
        std::cout << "Employee ID: " << employeeId << '\n';
    }
};

class Manager : public Employee      // Inherits Employee
{
private:
    int teamSize;                    // Team size

public:
    Manager(std::string managerName, int id, int size)
        : Employee(std::move(managerName), id), teamSize(size) {} // Constructor

    void showManager() const         // Display manager details
    {
        showPerson();                // Call Person function
        showEmployee();              // Call Employee function
        std::cout << "Team Size: " << teamSize << '\n'; // Display team size
    }
};

int main()                            // Main function
{
    Manager manager("Ravi", 501, 8);  // Create Manager object
    manager.showManager();            // Display details

    return 0;                         // End program
}