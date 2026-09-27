#include <fstream>  // File handling
#include <iostream> // Input/output
#include <string>   // String

int main() {
    // Open file for reading
    std::ifstream inputFile("message.txt");

    // Check file
    if (!inputFile) {
        std::cerr << "Error: Could not open message.txt\n";
        return 1;
    }

    std::string searchWord;

    // Get word from user
    std::cout << "Enter word to search: ";
    std::cin >> searchWord;

    std::string word;
    int count = 0;  // Match count

    // Read words from file
    while (inputFile >> word) {
        if (word == searchWord) {
            ++count;  // Increase count
        }
    }

    // Display result
    std::cout << "The word '" << searchWord
              << "' occurred " << count << " time(s).\n";

    return 0;  // End program
}