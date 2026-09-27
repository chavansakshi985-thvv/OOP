#include <fstream>  // File handling
#include <iostream> // Input/output

int main() {
    // Open file in append mode
    std::ofstream outputFile("message.txt", std::ios::app);

    // Check if file opened
    if (!outputFile) {
        std::cerr << "Error: Could not open message.txt for appending\n";
        return 1;
    }

    // Add data at the end
    outputFile << "This line was added using append mode.\n";

    // Close file
    outputFile.close();

    // Display success message
    std::cout << "New line appended successfully.\n";

    return 0;  // End program
}