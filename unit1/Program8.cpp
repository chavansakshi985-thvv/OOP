#include <iostream>                  // Includes iostream library for input and output

using namespace std;                 // Allows us to use cout without writing std::cout


class Test                            // Defines a class named Test
{
private:                              // Members below this can be accessed only inside the class

    int value;                        // Declares a private integer variable named value


public:                               // Members below this can be accessed from outside the class

    Test(int v)                       // Constructor with one integer parameter
    {
        value = v;                    // Assigns the value of v to the private variable value
    }

    inline int getValue()             // Defines an inline function that returns an integer
    {
        return value;                 // Returns the value stored in the private variable
    }

    friend void show(Test t);         // Declares show() as a friend function
                                      // Friend function can access private members of the class
};


void show(Test t)                     // Defines the friend function show()
{
    cout << t.value;                  // Accesses and displays private variable value
                                      // This is allowed because show() is a friend function
}


int main()                            // Main function; program execution starts here
{
    Test obj(50);                     // Creates object obj and passes 50 to the constructor
                                      // value becomes 50

    cout << obj.getValue() << endl;   // Calls getValue() and displays 50
                                      // endl moves the cursor to the next line

    show(obj);                        // Calls the friend function show() with object obj

    return 0;                         // Ends the program successfully
}