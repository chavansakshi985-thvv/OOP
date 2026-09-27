#include <iostream>                 // Input/output
#include <string>                   // String
#include <utility>                  // move()

class Vehicle                        // Base class
{
protected:
    std::string registrationNumber;  // Registration number

public:
    explicit Vehicle(std::string registration)
        : registrationNumber(std::move(registration)) {} // Constructor

    void start() const               // Start vehicle
    {
        std::cout << "Vehicle " << registrationNumber
                  << " started\n";
    }
};

class Car : public Vehicle           // Car inherits Vehicle
{
public:
    explicit Car(std::string registration)
        : Vehicle(std::move(registration)) {} // Constructor

    void openBoot() const            // Open car boot
    {
        std::cout << "Car boot opened\n";
    }
};

class Bike : public Vehicle          // Bike inherits Vehicle
{
public:
    explicit Bike(std::string registration)
        : Vehicle(std::move(registration)) {} // Constructor

    void helmetReminder() const      // Helmet reminder
    {
        std::cout << "Please wear a helmet\n";
    }
};

int main()                           // Main function
{
    Car car("MH12AB1234");           // Create Car object
    Bike bike("MH12CD5678");         // Create Bike object

    car.start();                     // Start car
    car.openBoot();                  // Open boot

    bike.start();                    // Start bike
    bike.helmetReminder();           // Show reminder

    return 0;                        // End program
}