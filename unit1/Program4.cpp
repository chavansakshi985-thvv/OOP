#include <iostream>                  // Includes iostream library for input and output

using namespace std;                 // Allows us to use cout without writing std::cout


int add(int, int);                   // Function declaration (prototype)
                                     // Tells the compiler that a function named add
                                     // exists and takes two integer values


int main()                            // Main function; program execution starts here
{
    int a = 10, b = 20;               // Declares two integer variables
                                     // a stores 10 and b stores 20

    cout << "Sum = " << add(a, b)     // Calls the add() function with a and b
         << endl;                     // Moves the cursor to the next line

    return 0;                         // Ends the main function successfully
}


int add(int x, int y)                 // Function definition
{
    return x + y;                     // Adds x and y and returns the result
}