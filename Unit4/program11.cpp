#include <cstring>    // String functions
#include <fstream>    // File handling
#include <iostream>   // Input/output

// Student record structure
struct StudentRecord {
    int rollNumber;
    char name[30];
    float marks;
};

int main() {

    StudentRecord student{};

    // Store student data
    student.rollNumber = 101;
    std::strncpy(student.name, "Amit Patil", sizeof(student.name) - 1);
    student.marks = 85.5F;

    {
        // Open binary file for writing
        std::ofstream outputFile("students.dat", std::ios::binary);

        // Check file
        if (!outputFile) {
            std::cerr << "Error: Could not create students.dat\n";
            return 1;
        }

        // Write record to file
        outputFile.write(
            reinterpret_cast<const char*>(&student),
            sizeof(student)
        );
    }

    StudentRecord readStudent{};

    {
        // Open binary file for reading
        std::ifstream inputFile("students.dat", std::ios::binary);

        // Check file
        if (!inputFile) {
            std::cerr << "Error: Could not open students.dat\n";
            return 1;
        }

        // Read record from file
        inputFile.read(
            reinterpret_cast<char*>(&readStudent),
            sizeof(readStudent)
        );

        // Check reading
        if (!inputFile) {
            std::cerr << "Error: Could not read record from students.dat\n";
            return 1;
        }
    }

    // Display record
    std::cout << "Roll Number: " << readStudent.rollNumber << '\n';
    std::cout << "Name: " << readStudent.name << '\n';
    std::cout << "Marks: " << readStudent.marks << '\n';

    return 0;  // End program
}