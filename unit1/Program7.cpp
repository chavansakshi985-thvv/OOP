#include <iostream>                  // Includes iostream library for input and output

using namespace std;                 // Allows us to use cout without writing std::cout


class Student                          // Defines a class named Student
{
public:                               // Members below this are publicly accessible

    static int count;                 // Declares a static variable named count
                                      // Static means only ONE copy is shared
                                      // by all objects of the class

    Student()                          // Constructor of the Student class
    {
        count++;                       // Increases count by 1 whenever an object is created
    }
};


int Student::count = 0;               // Defines and initializes the static variable
                                      // count starts with value 0


int main()                              // Main function; program execution starts here
{
    Student s1, s2, s3;                // Creates three Student objects
                                       // s1 → count becomes 1
                                       // s2 → count becomes 2
                                       // s3 → count becomes 3

    cout << Student::count;            // Displays the value of count
                                       // :: is the scope resolution operator

    return 0;                          // Ends the program successfully
}