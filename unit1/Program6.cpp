#include <iostream>                  // Includes iostream library for input and output

using namespace std;                 // Allows us to use cout without writing std::cout

class Demo                           // Defines a class named Demo
{
public:                              // Members below this are publicly accessible

    Demo()                            // Constructor; called automatically when object is created
    {
        cout << "Constructor called "; // Displays "Constructor called"
    }

    ~Demo()                           // Destructor; called automatically when object is destroyed
    {
        cout << "Destructor called";  // Displays "Destructor called"
    }
};

int main()                            // Main function; program execution starts here
{
    Demo d;                           // Creates object d
                                       // Constructor is automatically called here

    return 0;                         // Ends main function
                                       // Object d is destroyed here
                                       // Destructor is automatically called
}