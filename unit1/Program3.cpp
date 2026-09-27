#include <iostream>                  // Includes iostream library for input and output

using namespace std;                 // Allows us to use cout without writing std::cout

int main()                            // Main function; program execution starts here
{
    int marks[5] = {78, 82, 91, 67, 88};
    // int = integer data type
    // marks[5] = array named marks that can store 5 integers
    // {78, 82, 91, 67, 88} = values stored in the array

    for (int i = 0; i < 5; i++)
    // for loop is used to repeat a block of code
    // int i = 0      → starts the counter from 0
    // i < 5          → loop continues while i is less than 5
    // i++            → increases i by 1 after every loop

    {
        cout << marks[i] << " ";
        // cout          → displays output on the screen
        // marks[i]      → accesses the current array element
        // " "           → prints a space after each mark
    }

    return 0;                          // Ends the program successfully
}