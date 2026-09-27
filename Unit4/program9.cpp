#include <cstdio>     // remove(), rename()
#include <fstream>    // File handling
#include <iostream>   // Input/output
#include <sstream>    // String stream
#include <string>     // String

int main() {

    // Open original and temporary files
    std::ifstream inputFile("students.txt");
    std::ofstream temporaryFile("students_temp.txt");

    // Check files
    if (!inputFile || !temporaryFile) {
        std::cerr << "Error: Could not open file(s).\n";
        return 1;
    }

    int targetRollNumber;
    double updatedMarks;

    // Take roll number
    std::cout << "Enter roll number to update: ";
    std::cin >> targetRollNumber;

    // Take new marks
    std::cout << "Enter updated marks: ";
    std::cin >> updatedMarks;

    std::string line;
    bool found = false;

    // Read file line by line
    while (std::getline(inputFile, line)) {

        // Split record
        std::stringstream record(line);

        std::string rollText;
        std::string name;
        std::string marksText;

        // Read fields
        if (std::getline(record, rollText, '|') &&
            std::getline(record, name, '|') &&
            std::getline(record, marksText)) {

            // Convert roll number
            int rollNumber = std::stoi(rollText);

            // Check roll number
            if (rollNumber == targetRollNumber) {

                // Write updated record
                temporaryFile << rollNumber << '|'
                              << name << '|'
                              << updatedMarks << '\n';

                found = true;

            } else {

                // Copy unchanged record
                temporaryFile << line << '\n';
            }
        }
    }

    // Close files
    inputFile.close();
    temporaryFile.close();

    // If record not found
    if (!found) {
        std::remove("students_temp.txt");
        std::cout << "Student record not found. No update performed.\n";
        return 0;
    }

    // Remove old file
    if (std::remove("students.txt") != 0) {
        std::cerr << "Error: Could not remove old students.txt\n";
        return 1;
    }

    // Rename temporary file
    if (std::rename("students_temp.txt", "students.txt") != 0) {
        std::cerr << "Error: Could not rename temporary file.\n";
        return 1;
    }

    std::cout << "Student marks updated successfully.\n";

    return 0;  // End program
}