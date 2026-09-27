#include <fstream>    // File handling
#include <iostream>   // Input/output
#include <sstream>    // String stream
#include <string>     // String

int main() {

    // Open students.txt for reading
    std::ifstream inputFile("students.txt");

    // Check file
    if (!inputFile) {
        std::cerr << "Error: Could not open students.txt\n";
        return 1;
    }

    int targetRollNumber;

    // Take roll number
    std::cout << "Enter roll number to search: ";
    std::cin >> targetRollNumber;

    std::string line;
    bool found = false;

    // Read file line by line
    while (std::getline(inputFile, line)) {

        // Split each record
        std::stringstream record(line);

        std::string rollText;
        std::string name;
        std::string marksText;

        // Read data separated by |
        if (std::getline(record, rollText, '|') &&
            std::getline(record, name, '|') &&
            std::getline(record, marksText)) {

            // Convert text to numbers
            int rollNumber = std::stoi(rollText);
            double marks = std::stod(marksText);

            // Check roll number
            if (rollNumber == targetRollNumber) {

                std::cout << "Record Found\n";
                std::cout << "Roll Number: " << rollNumber << '\n';
                std::cout << "Name: " << name << '\n';
                std::cout << "Marks: " << marks << '\n';

                found = true;
                break;  // Stop searching
            }
        }
    }

    // If record not found
    if (!found) {
        std::cout << "Student record not found.\n";
    }

    return 0;  // End program
}