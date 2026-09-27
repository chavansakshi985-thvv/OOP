#include <iostream>  // Input/output

class Shape {
public:
    // Pure virtual function
    virtual double area() const = 0;

    // Virtual destructor
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
    double length;  // Length
    double width;   // Width

public:
    // Constructor
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {}

    // Implement area()
    double area() const override {
        return length * width;
    }
};

int main() {
    Rectangle rectangle(8.0, 4.0);  // Create object

    // Display area
    std::cout << "Rectangle Area: " << rectangle.area() << '\n';

    return 0;  // End program
}