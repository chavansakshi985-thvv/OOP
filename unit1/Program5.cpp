#include <iostream>                  // Includes iostream library for input and output
using namespace std;                 // Allows us to use cout without writing std::cout

class Student                         // Defines a class named Student
{
public:                              // public members can be accessed outside the class

    string name;                     // Declares a string variable to store student's name

    int age;                         // Declares an integer variable to store student's age

    void show()                       // Defines a function named show()
    {
        cout << name << " " << age   // Displays the student's name and age
             << endl;                 // Moves the cursor to the next line
    }
};

int main()                            // Main function; program execution starts here
{
    Student s1;                       // Creates an object s1 of the Student class

    s1.name = "Amit";                 // Assigns "Amit" to the name of object s1

    s1.age = 20;                      // Assigns 20 to the age of object s1

    s1.show();                        // Calls the show() function using object s1

    return 0;                         // Ends the program successfully
}