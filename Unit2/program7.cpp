#include <iostream>                 // Input/output

class Academic                       // Academic class
{
public:
    void display() const             // Display academic info
    {
        std::cout << "Academic information\n";
    }
};

class Sports                          // Sports class
{
public:
    void display() const             // Display sports info
    {
        std::cout << "Sports information\n";
    }
};

class Student : public Academic, public Sports // Multiple inheritance
{
public:
    void displayAll() const          // Display both
    {
        Academic::display();         // Call Academic display
        Sports::display();           // Call Sports display
    }
};

int main()                            // Main function
{
    Student student;                 // Create Student object

    student.Academic::display();     // Call Academic function
    student.Sports::display();       // Call Sports function
    student.displayAll();            // Call both functions

    return 0;                        // End program
}