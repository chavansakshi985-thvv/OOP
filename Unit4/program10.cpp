#include <fstream>    // File handling
#include <iostream>   // Input/output
#include <string>     // String

int main() {

    // Open file for reading and writing
    std::fstream file("navigation.txt",
                      std::ios::in | std::ios::out | std::ios::trunc);

    // Check file
    if (!file) {
        std::cerr << "Error: Could not open navigation.txt\n";
        return 1;
    }

    // Write data
    file << "ABCDE";

    // Show output position
    std::cout << "Output position after writing: "
              << file.tellp() << '\n';

    file.flush();

    // Move input pointer to beginning
    file.seekg(0, std::ios::beg);

    char firstCharacter;

    // Read first character
    file.get(firstCharacter);

    std::cout << "First character: " << firstCharacter << '\n';

    // Show input position
    std::cout << "Input position after reading one character: "
              << file.tellg() << '\n';

    // Move to position 2
    file.seekg(2, std::ios::beg);

    char thirdCharacter;

    // Read character at position 2
    file.get(thirdCharacter);

    std::cout << "Character at position 2: "
              << thirdCharacter << '\n';

    // Move output pointer to position 5
    file.seekp(5, std::ios::beg);

    // Write F
    file << "F";

    // Close file
    file.close();

    std::cout << "Navigation completed. Check navigation.txt\n";

    return 0;  // End program
}