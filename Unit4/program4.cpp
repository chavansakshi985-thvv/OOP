#include <fstream>  // File handling
#include <iostream> // Input/output
#include <string>   // String

int main() {
    // Open source file for reading
    std::ifstream sourceFile("message.txt");

    // Open destination file for writing
    std::ofstream destinationFile("message_copy.txt");

    // Check source file
    if (!sourceFile) {
        std::cerr << "Error: Could not open source file.\n";
        return 1;
    }

    // Check destination file
    if (!destinationFile) {
        std::cerr << "Error: Could not create destination file.\n";
        return 1;
    }

    std::string line;  // Store each line

    // Copy file line by line
    while (std::getline(sourceFile, line)) {
        destinationFile << line << '\n';
    }

    // Display success message
    std::cout << "File copied successfully to message_copy.txt\n";

    return 0;  // End program
}