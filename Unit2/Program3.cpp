#include <iostream>                 // Input/output

class Base                            // Base class
{
public:
    void show() const                // Public function
    {
        std::cout << "Base public function\n"; // Display message
    }
};

class PublicDerived : public Base    // Public inheritance
{
};

class PrivateDerived : private Base  // Private inheritance
{
public:
    void callBaseShow() const        // Function to call base function
    {
        show();                      // Call Base show()
    }
};

int main()                            // Main function
{
    PublicDerived publicObject;       // Create object
    publicObject.show();              // Access public function

    PrivateDerived privateObject;     // Create object
    privateObject.callBaseShow();     // Call through derived function

    // privateObject.show();          // Error: show() is private

    return 0;                         // End program
}