#include <iostream>  // Input/output

class Complex {
private:
    int real;       // Real part
    int imaginary;  // Imaginary part

public:
    // Constructor
    Complex(int realPart = 0, int imaginaryPart = 0)
        : real(realPart), imaginary(imaginaryPart) {}

    // Declare friend operator function
    friend Complex operator+(int value, const Complex& number);

    // Display complex number
    void display() const {
        std::cout << real;

        // Check imaginary sign
        if (imaginary >= 0) {
            std::cout << " + ";
        } else {
            std::cout << " - ";
        }

        std::cout << (imaginary >= 0 ? imaginary : -imaginary) << "i\n";
    }
};

// Define friend operator+
Complex operator+(int value, const Complex& number) {
    return Complex(value + number.real, number.imaginary);
}

int main() {
    Complex number(2, 3);       // Create object
    Complex result = 10 + number; // Add integer and object

    // Display result
    std::cout << "Result: ";
    result.display();

    return 0;  // End program
}