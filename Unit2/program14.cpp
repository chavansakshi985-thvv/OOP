#include <iostream>                 // Input/output
#include <string>                   // String
#include <utility>                  // move()

class University                    // Outer class
{
public:
    class Department                // Nested class
    {
    private:
        std::string name;            // Department name

    public:
        explicit Department(std::string departmentName)
            : name(std::move(departmentName)) {} // Constructor

        void display() const         // Display department
        {
            std::cout << "Department: " << name << '\n';
        }
    };
};

int main()                            // Main function
{
    University::Department department(
        "Artificial Intelligence and Data Science"); // Create object

    department.display();             // Display department

    return 0;                         // End program
}