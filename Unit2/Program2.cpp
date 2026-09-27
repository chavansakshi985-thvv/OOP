#include <iostream>              // Input/output
#include <string>               // String
#include <utility>              // move()

class Employee                   // Base class
{
protected:
    std::string name;             // Employee name

public:
    explicit Employee(std::string employeeName)
        : name(std::move(employeeName)) {} // Constructor
};

class Developer : public Employee // Derived class
{
private:
    std::string language;          // Programming language

public:
    Developer(std::string employeeName, std::string programmingLanguage)
        : Employee(std::move(employeeName)), language(std::move(programmingLanguage)) {} // Constructor

    void display() const           // Display details
    {
        std::cout << "Developer: " << name << '\n';     // Display name
        std::cout << "Language: " << language << '\n';  // Display language
    }
};

int main()                         // Main function
{
    Developer developer("Neha", "C++"); // Create object

    developer.display();            // Display details

    return 0;                       // End program
}