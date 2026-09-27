#include <iostream>                 // Input/output
#include <string>                   // String
#include <utility>                  // move()

class Vehicle                        // Base class
{
protected:
    std::string registrationNumber;  // Registration number
    double ratePerDay;               // Daily rent

public:
    Vehicle(std::string registration, double rate)
        : registrationNumber(std::move(registration)), ratePerDay(rate) {} // Constructor

    virtual double calculateRent(int days) const // Calculate rent
    {
        return ratePerDay * days;      // Basic rent
    }

    virtual void display() const       // Display details
    {
        std::cout << "Registration: " << registrationNumber << '\n';
        std::cout << "Rate per day: " << ratePerDay << '\n';
    }

    virtual ~Vehicle() = default;      // Virtual destructor
};

class Car : public Vehicle             // Car inherits Vehicle
{
private:
    int numberOfDoors;                  // Number of doors

public:
    Car(std::string registration, double rate, int doors)
        : Vehicle(std::move(registration), rate), numberOfDoors(doors) {} // Constructor

    void display() const override       // Override display()
    {
        Vehicle::display();             // Call base display()
        std::cout << "Doors: " << numberOfDoors << '\n';
    }
};

class Bike : public Vehicle            // Bike inherits Vehicle
{
private:
    int engineCapacity;                 // Engine capacity

public:
    Bike(std::string registration, double rate, int capacity)
        : Vehicle(std::move(registration), rate), engineCapacity(capacity) {} // Constructor

    double calculateRent(int days) const override // Override rent
    {
        return ratePerDay * days * 0.9;  // 10% discount
    }

    void display() const override       // Override display()
    {
        Vehicle::display();             // Call base display()
        std::cout << "Engine Capacity: "
                  << engineCapacity << " cc\n";
    }
};

int main()                              // Main function
{
    Car car("MH12AB1234", 2000.0, 5);  // Create Car
    Bike bike("MH12CD5678", 800.0, 150); // Create Bike

    std::cout << "Car Details\n";       // Car heading
    car.display();                      // Display car details
    std::cout << "Rent for 3 days: "
              << car.calculateRent(3) << "\n\n"; // Car rent

    std::cout << "Bike Details\n";      // Bike heading
    bike.display();                     // Display bike details
    std::cout << "Rent for 3 days: "
              << bike.calculateRent(3) << '\n'; // Bike rent

    return 0;                           // End program
}