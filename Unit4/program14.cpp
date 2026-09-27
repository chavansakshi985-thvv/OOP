#include <cctype>     // Character functions
#include <fstream>    // File handling
#include <iostream>   // Input/output
#include <string>     // String

// Check if character is vowel
bool isVowel(char ch) {
    ch = static_cast<char>(
        std::tolower(static_cast<unsigned char>(ch))
    );

    return ch == 'a' || ch == 'e' || ch == 'i' ||
           ch == 'o' || ch == 'u';
}

int main() {

    std::string fileName;

    // Take file name
    std::cout << "Enter file name: ";
    std::getline(std::cin, fileName);

    // Open file
    std::ifstream inputFile(fileName);

    // Check file
    if (!inputFile) {
        std::cerr << "Error: Could not open " << fileName << '\n';
        return 1;
    }

    // Counters
    std::size_t lines = 0;
    std::size_t words = 0;
    std::size_t characters = 0;
    std::size_t vowels = 0;
    std::size_t digits = 0;
    std::size_t spaces = 0;

    bool insideWord = false;

    char ch;

    // Read character by character
    while (inputFile.get(ch)) {

        ++characters;

        // Count lines
        if (ch == '\n') {
            ++lines;
        }

        // Count spaces and words
        if (std::isspace(static_cast<unsigned char>(ch))) {

            if (ch == ' ') {
                ++spaces;
            }

            insideWord = false;

        } else if (!insideWord) {

            ++words;
            insideWord = true;
        }

        // Count vowels
        if (std::isalpha(static_cast<unsigned char>(ch)) &&
            isVowel(ch)) {
            ++vowels;
        }

        // Count digits
        if (std::isdigit(static_cast<unsigned char>(ch))) {
            ++digits;
        }
    }

    // Count last line if needed
    if (characters > 0) {

        inputFile.clear();
        inputFile.seekg(-1, std::ios::end);

        char lastCharacter;
        inputFile.get(lastCharacter);

        if (lastCharacter != '\n') {
            ++lines;
        }
    }

    // Display statistics
    std::cout << "\nFile Statistics\n";
    std::cout << "Lines: " << lines << '\n';
    std::cout << "Words: " << words << '\n';
    std::cout << "Characters: " << characters << '\n';
    std::cout << "Vowels: " << vowels << '\n';
    std::cout << "Digits: " << digits << '\n';
    std::cout << "Spaces: " << spaces << '\n';

    return 0;  // End program
}