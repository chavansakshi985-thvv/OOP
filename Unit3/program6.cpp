#include <iostream>  // Input/output

class Distance {
private:
    int meters;  // Stores distance

public:
    // Constructor
    explicit Distance(int value) : meters(value) {}

    // Overload > operator
    bool operator>(const Distance& other) const {
        return meters > other.meters;
    }

    // Display distance
    void display() const {
        std::cout << meters << " meters\n";
    }
};

int main() {
    Distance first(120);   // First distance
    Distance second(90);   // Second distance

    // Display distances
    std::cout << "First distance: ";
    first.display();

    std::cout << "Second distance: ";
    second.display();

    // Compare distances
    if (first > second) {
        std::cout << "First distance is greater\n";
    } else {
        std::cout << "Second distance is greater or equal\n";
    }

    return 0;  // End program
}