#include <iostream>  // Input/output

// Add two integers
int add(int first, int second) {
    return first + second;
}

// Add two doubles
double add(double first, double second) {
    return first + second;
}

// Add three integers
int add(int first, int second, int third) {
    return first + second + third;
}

int main() {
    // Call function with two integers
    std::cout << "Sum of two integers: " << add(10, 20) << '\n';

    // Call function with two doubles
    std::cout << "Sum of two doubles: " << add(2.5, 3.7) << '\n';

    // Call function with three integers
    std::cout << "Sum of three integers: " << add(10, 20, 30) << '\n';

    return 0;  // End program
}