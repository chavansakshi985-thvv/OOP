#include <iostream>              // Includes iostream library for input and output

using namespace std;             // Allows us to use cout without writing std::cout

int main()                         // Main function; program execution starts here
{
    int marks = 45;                // int = integer data type; marks stores the value 45

    if (marks >= 40)               // Checks whether marks are greater than or equal to 40
    {
        cout << "Pass";            // If condition is true, displays "Pass"
    }
    else                            // Runs when the if condition is false
    {
        cout << "Fail";            // Displays "Fail"
    }

    return 0;                      // Ends the program successfully
}