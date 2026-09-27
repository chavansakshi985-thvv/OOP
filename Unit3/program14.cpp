#include <iostream>  // Input/output

class Base {
public:
    // Virtual function
    virtual void display() const {
        std::cout << "Base object\n";
    }

    // Virtual destructor
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    // Override display()
    void display() const override {
        std::cout << "Derived object\n";
    }
};

// Pass object by value
void displayByValue(Base object) {
    object.display();
}

// Pass object by reference
void displayByReference(const Base& object) {
    object.display();
}

int main() {
    Derived derived;  // Create Derived object

    // Pass by value
    std::cout << "Passing by value: ";
    displayByValue(derived);

    // Pass by reference
    std::cout << "Passing by reference: ";
    displayByReference(derived);

    return 0;  // End program
}