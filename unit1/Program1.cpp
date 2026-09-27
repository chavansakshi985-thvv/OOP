#include <iostream>          // Includes the iostream library for input and output

using namespace std;         // Allows us to use cout and endl without writing std::

int main()                   // Main function: program execution starts here
{
    int roll = 101;          // int = integer data type; roll stores the value 101

    char grade = 'A';        // char = character data type; grade stores the character 'A'

    float fee = 12500.50;    // float = decimal data type; fee stores 12500.50

    cout << "Roll No: "      // cout = displays output on the screen
         << roll             // Displays the value stored in roll
         << endl;            // endl = moves the cursor to the next line

    cout << "Grade: "        // Displays the text "Grade: "
         << grade             // Displays the value stored in grade
         << endl;            // Moves to the next line

    cout << "Fee: "          // Displays the text "Fee: "
         << fee              // Displays the value stored in fee
         << endl;             // Moves to the next line

    return 0;                // Ends the program successfully
}