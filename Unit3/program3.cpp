#include <iostream>  // Input/output

class Number {
private:
    int value;  // Stores number

public:
    // Constructor
    explicit Number(int givenValue) : value(givenValue) {}

    // Overload unary minus (-)
    Number operator-() const {
        return Number(-value);
    }

    // Display value
    void display() const {
        std::cout << value << '\n';
    }
};

int main() {
    Number first(25);       // Create object
    Number second = -first; // Apply unary minus

    // Display original value
    std::cout << "Original value: ";
    first.display();

    // Display negated value
    std::cout << "Negated value: ";
    second.display();

    return 0;  // End program
}