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
};

class Student : public Person        // Inherits Person
{
private:
    int rollNumber;                  // Roll number

public:
    Student(std::string studentName, int roll)
        : Person(std::move(studentName)), rollNumber(roll) {} // Constructor

    void display() const             // Display details
    {
        std::cout << "Name: " << name << '\n';        // Display name
        std::cout << "Roll Number: " << rollNumber << '\n'; // Display roll
    }
};

int main()                            // Main function
{
    Student student("Kiran", 24);    // Create Student object
    student.display();               // Display details

    return 0;                         // End program
}