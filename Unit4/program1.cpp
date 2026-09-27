#include <fstream>  // File handling
#include <iostream> // Input/output

int main() {
    // Create and open file
    std::ofstream outputFile("message.txt");

    // Check if file opened
    if (!outputFile) {
        std::cerr << "Error: Could not create message.txt\n";
        return 1;
    }

    // Write data to file
    outputFile << "Welcome to C++ File Handling\n";
    outputFile << "This is the first line written to a file.\n";
    outputFile << "Files store data permanently.\n";

    // Close file
    outputFile.close();

    // Display success message
    std::cout << "Data written successfully to message.txt\n";

    return 0;  // End program
}