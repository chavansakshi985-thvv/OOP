#include <iostream>  // Input/output

class Counter {
private:
    int value;  // Stores counter value

public:
    // Constructor
    explicit Counter(int initialValue = 0) : value(initialValue) {}

    // Overload prefix ++
    Counter& operator++() {
        ++value;
        return *this;
    }

    // Overload postfix ++
    Counter operator++(int) {
        Counter old = *this;  // Store old value
        ++value;              // Increment value
        return old;           // Return old value
    }

    // Display value
    void display() const {
        std::cout << value << '\n';
    }
};

int main() {
    Counter counter(5);  // Create object

    // Prefix increment
    std::cout << "After prefix increment: ";
    ++counter;
    counter.display();

    // Postfix increment
    std::cout << "Value returned by postfix increment: ";
    Counter oldValue = counter++;
    oldValue.display();

    // Display updated value
    std::cout << "Counter after postfix increment: ";
    counter.display();

    return 0;  // End program
}