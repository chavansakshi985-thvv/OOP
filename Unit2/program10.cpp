#include <iostream>                 // Input/output

class Vehicle                        // Base class
{
public:
    virtual void move() const        // Virtual function
    {
        std::cout << "Vehicle is moving\n";
    }

    virtual ~Vehicle() = default;    // Virtual destructor
};

class Car : public Vehicle            // Car inherits Vehicle
{
public:
    void move() const override       // Override move()
    {
        std::cout << "Car moves on roads\n";
    }
};

class Boat : public Vehicle           // Boat inherits Vehicle
{
public:
    void move() const override       // Override move()
    {
        std::cout << "Boat moves on water\n";
    }
};

int main()                            // Main function
{
    Car car;                          // Create Car object
    Boat boat;                        // Create Boat object

    car.move();                       // Call Car move()
    boat.move();                      // Call Boat move()

    return 0;                         // End program
}