#include <iostream>  // Input/output
#include <memory>    // Smart pointers
#include <vector>    // Vector

class Shape {
public:
    // Pure virtual functions
    virtual double area() const = 0;
    virtual void displayName() const = 0;

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

    // Calculate area
    double area() const override {
        return length * width;
    }

    // Display name
    void displayName() const override {
        std::cout << "Rectangle";
    }
};

class Circle : public Shape {
private:
    double radius;  // Radius

public:
    // Constructor
    explicit Circle(double givenRadius) : radius(givenRadius) {}

    // Calculate area
    double area() const override {
        constexpr double PI = 3.141592653589793;
        return PI * radius * radius;
    }

    // Display name
    void displayName() const override {
        std::cout << "Circle";
    }
};

int main() {
    // Store different shapes
    std::vector<std::unique_ptr<Shape>> shapes;

    shapes.push_back(std::make_unique<Rectangle>(5.0, 3.0));
    shapes.push_back(std::make_unique<Circle>(2.0));

    // Display each shape
    for (const auto& shape : shapes) {
        shape->displayName();
        std::cout << " Area: " << shape->area() << '\n';
    }

    return 0;  // End program
}