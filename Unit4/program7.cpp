#include <fstream>  // File handling
#include <iostream> // Input/output
#include <limits>   // Input limits
#include <string>   // String

int main() {
    // Open file in append mode
    std::ofstream outputFile("students.txt", std::ios::app);

    // Check file
    if (!outputFile) {
        std::cerr << "Error: Could not open students.txt\n";
        return 1;
    }

    int rollNumber;
    std::string name;
    double marks;

    // Input roll number
    std::cout << "Enter roll number: ";
    std::cin >> rollNumber;

    // Input name
    std::cout << "Enter name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);

    // Input marks
    std::cout << "Enter marks: ";
    std::cin >> marks;

    // Save record to file
    outputFile << rollNumber << '|' << name << '|' << marks << '\n';

    // Success message
    std::cout << "Student record saved successfully.\n";

    return 0;  // End program
}