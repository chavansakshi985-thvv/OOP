#include <iostream>  // Input/output

class Complex {
private:
    int real;       // Real part
    int imaginary;  // Imaginary part

public:
    // Constructor
    Complex(int realPart = 0, int imaginaryPart = 0)
        : real(realPart), imaginary(imaginaryPart) {}

    // Overload + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real,
                       imaginary + other.imaginary);
    }

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

int main() {
    Complex first(2, 3);       // First number
    Complex second(4, 5);      // Second number
    Complex sum = first + second;  // Add objects

    // Display first number
    std::cout << "First complex number: ";
    first.display();

    // Display second number
    std::cout << "Second complex number: ";
    second.display();

    // Display sum
    std::cout << "Sum: ";
    sum.display();

    return 0;  // End program
}