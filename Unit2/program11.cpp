#include <iostream>                 // Input/output

class Shape                          // Base class
{
public:
    virtual double area() const = 0; // Pure virtual function

    virtual ~Shape() = default;      // Virtual destructor
};

class Rectangle : public Shape       // Rectangle inherits Shape
{
private:
    double length;                   // Length
    double width;                    // Width

public:
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {} // Constructor

    double area() const override     // Override area()
    {
        return length * width;       // Calculate area
    }
};

class Circle : public Shape          // Circle inherits Shape
{
private:
    double radius;                   // Radius

public:
    explicit Circle(double givenRadius)
        : radius(givenRadius) {}     // Constructor

    double area() const override     // Override area()
    {
        return 3.141592653589793 * radius * radius; // Circle area
    }
};

int main()                            // Main function
{
    Rectangle rectangle(5.0, 3.0);   // Create Rectangle object
    Circle circle(2.0);               // Create Circle object

    std::cout << "Rectangle Area: "
              << rectangle.area() << '\n'; // Display rectangle area

    std::cout << "Circle Area: "
              << circle.area() << '\n';     // Display circle area

    return 0;                         // End program
}