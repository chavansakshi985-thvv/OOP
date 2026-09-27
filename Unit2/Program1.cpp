#include <iostream>              // Input/output
#include <string>               // String
#include <utility>              // move()

class Person                     // Base class
{
protected:
    std::string name;             // Name

public:
    explicit Person(std::string personName)
        : name(std::move(personName)) {}   // Constructor

    void displayName() const      // Display name
    {
        std::cout << "Name: " << name << '\n';
    }
};

class Student : public Person     // Derived class
{
private:
    int rollNumber;               // Roll number

public:
    Student(std::string studentName, int roll)
        : Person(std::move(studentName)), rollNumber(roll) {} // Constructor

    void displayStudent() const   // Display student details
    {
        displayName();            // Call base function
        std::cout << "Roll Number: " << rollNumber << '\n';
    }
};

int main()                       // Main function
{
    Student student("Amit", 101); // Create object

    student.displayStudent();     // Display details

    return 0;                     // End program
}