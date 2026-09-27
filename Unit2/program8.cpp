#include <iostream>                 // Input/output

class Base                            // Base class
{
public:
    Base()                            // Base constructor
    {
        std::cout << "Base constructor\n";
    }

    ~Base()                           // Base destructor
    {
        std::cout << "Base destructor\n";
    }
};

class Derived : public Base           // Derived class
{
public:
    Derived()                         // Derived constructor
    {
        std::cout << "Derived constructor\n";
    }

    ~Derived()                        // Derived destructor
    {
        std::cout << "Derived destructor\n";
    }
};

int main()                            // Main function
{
    Derived object;                   // Create Derived object

    return 0;                         // End program
}