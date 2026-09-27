#include <iostream>  // Input/output

class Shape {
public:
    // Virtual function
    virtual double area() const {
        return 0.0;
    }

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

    // Override area()
    double area() const override {
        return length * width;
    }
};

class Circle : public Shape {
private:
    double radius;  // Radius

public:
    // Constructor
    explicit Circle(double givenRadius) : radius(givenRadius) {}

    // Override area()
    double area() const override {
        constexpr double PI = 3.141592653589793;
        return PI * radius * radius;
    }
};

// Display area using base reference
void printArea(const Shape& shape) {
    std::cout << "Area: " << shape.area() << '\n';
}

int main() {
    Rectangle rectangle(5.0, 3.0);  // Rectangle object
    Circle circle(2.0);             // Circle object

    printArea(rectangle);           // Rectangle area
    printArea(circle);              // Circle area

    return 0;  // End program
}