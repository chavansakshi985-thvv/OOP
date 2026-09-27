#include <iostream>                 // Input/output
#include <string>                   // String
#include <utility>                  // move()

class Person                         // Base class
{
protected:
    std::string name;                // Name

public:
    explicit Person(std::string personName)
        : name(std::move(personName)) {} // Constructor

    void displayName() const         // Display name
    {
        std::cout << "Name: " << name << '\n';
    }
};

class Student : virtual public Person // Virtual inheritance
{
public:
    Student() : Person("Unknown") {}  // Constructor
};

class Employee : virtual public Person // Virtual inheritance
{
public:
    Employee() : Person("Unknown") {}  // Constructor
};

class TeachingAssistant : public Student, public Employee // Multiple inheritance
{
public:
    explicit TeachingAssistant(std::string assistantName)
        : Person(std::move(assistantName)), Student(), Employee() {} // Constructor
};

int main()                            // Main function
{
    TeachingAssistant assistant("Riya"); // Create object
    assistant.displayName();             // Display name

    return 0;                         // End program
}