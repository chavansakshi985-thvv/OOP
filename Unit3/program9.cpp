#include <iostream>  // Input/output

class Animal {
public:
    // Virtual function
    virtual void sound() const {
        std::cout << "Animal makes a sound\n";
    }

    // Virtual destructor
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    // Override sound()
    void sound() const override {
        std::cout << "Dog barks\n";
    }
};

class Cat : public Animal {
public:
    // Override sound()
    void sound() const override {
        std::cout << "Cat meows\n";
    }
};

int main() {
    Dog dog;                    // Create Dog object
    Cat cat;                    // Create Cat object

    Animal* animal = &dog;      // Base pointer to Dog
    animal->sound();            // Calls Dog sound()

    animal = &cat;              // Base pointer to Cat
    animal->sound();            // Calls Cat sound()

    return 0;  // End program
}