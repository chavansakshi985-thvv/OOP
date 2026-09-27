#include <fstream>  // File handling
#include <iostream> // Input/output
#include <string>   // String

int main() {
    // Open file for reading
    std::ifstream inputFile("message.txt");

    // Check if file opened
    if (!inputFile) {
        std::cerr << "Error: Could not open message.txt\n";
        return 1;
    }

    std::string line;  // Store each line

    // Display file content
    std::cout << "File Content:\n";

    while (std::getline(inputFile, line)) {
        std::cout << line << '\n';
    }

    // Close file
    inputFile.close();

    return 0;  // End program
}