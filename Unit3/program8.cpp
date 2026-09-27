#include <iostream>  // Input/output

class Base {
public:
    // Base class function
    void display() const {
        std::cout << "Base display function\n";
    }
};

class Derived : public Base {
public:
    // Redefine display function
    void display() const {
        std::cout << "Derived display function\n";
    }
};

int main() {
    Derived derivedObject;          // Create derived object
    Base* basePointer = &derivedObject;  // Base pointer

    // Calls Base version
    basePointer->display();

    return 0;  // End program
}