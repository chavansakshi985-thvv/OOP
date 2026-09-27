#include <iostream>  // Input/output

class Base {
public:
    // Virtual destructor
    virtual ~Base() {
        std::cout << "Base destructor\n";
    }
};

class Derived : public Base {
public:
    // Derived destructor
    ~Derived() override {
        std::cout << "Derived destructor\n";
    }
};

int main() {
    // Base pointer points to Derived object
    Base* pointer = new Derived();

    // Delete object
    delete pointer;

    return 0;  // End program
}