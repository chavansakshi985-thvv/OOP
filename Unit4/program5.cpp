#include <cctype>   // Character functions
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

    // Counters
    std::size_t lineCount = 0;
    std::size_t wordCount = 0;
    std::size_t characterCount = 0;
    bool insideWord = false;

    char ch;

    // Read file character by character
    while (inputFile.get(ch)) {
        ++characterCount;

        // Count lines
        if (ch == '\n') {
            ++lineCount;
        }

        // Check spaces
        if (std::isspace(static_cast<unsigned char>(ch))) {
            insideWord = false;
        } else if (!insideWord) {
            ++wordCount;
            insideWord = true;
        }
    }

    // Count last line if no newline
    if (characterCount > 0) {
        inputFile.clear();
        inputFile.seekg(-1, std::ios::end);

        char lastCharacter;
        inputFile.get(lastCharacter);

        if (lastCharacter != '\n') {
            ++lineCount;
        }
    }

    // Display counts
    std::cout << "Lines: " << lineCount << '\n';
    std::cout << "Words: " << wordCount << '\n';
    std::cout << "Characters: " << characterCount << '\n';

    return 0;  // End program
}