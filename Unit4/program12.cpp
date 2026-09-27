#include <cstring>    // String functions
#include <fstream>    // File handling
#include <iostream>   // Input/output

// Student record structure
struct StudentRecord {
    int rollNumber;
    char name[30];
    float marks;
};

// Add record to binary file
void addRecord(std::ofstream& file, int rollNumber,
               const char* name, float marks) {

    StudentRecord student{};

    // Store student data
    student.rollNumber = rollNumber;
    std::strncpy(student.name, name, sizeof(student.name) - 1);
    student.marks = marks;

    // Write record
    file.write(
        reinterpret_cast<const char*>(&student),
        sizeof(student)
    );
}

int main() {

    {
        // Create binary file
        std::ofstream outputFile(
            "records.dat",
            std::ios::binary | std::ios::trunc
        );

        // Check file
        if (!outputFile) {
            std::cerr << "Error: Could not create records.dat\n";
            return 1;
        }

        // Add student records
        addRecord(outputFile, 101, "Amit", 85.5F);
        addRecord(outputFile, 102, "Neha", 91.0F);
        addRecord(outputFile, 103, "Ravi", 78.0F);
    }

    // Open file for reading
    std::ifstream inputFile("records.dat", std::ios::binary);

    // Check file
    if (!inputFile) {
        std::cerr << "Error: Could not open records.dat\n";
        return 1;
    }

    int recordNumber;

    // Take record number
    std::cout << "Enter record number to read (1 to 3): ";
    std::cin >> recordNumber;

    // Validate record number
    if (recordNumber < 1 || recordNumber > 3) {
        std::cerr << "Invalid record number.\n";
        return 1;
    }

    // Calculate record position
    const std::streamoff offset =
        static_cast<std::streamoff>(recordNumber - 1) *
        static_cast<std::streamoff>(sizeof(StudentRecord));

    // Move to selected record
    inputFile.seekg(offset, std::ios::beg);

    StudentRecord selectedStudent{};

    // Read selected record
    inputFile.read(
        reinterpret_cast<char*>(&selectedStudent),
        sizeof(selectedStudent)
    );

    // Check reading
    if (!inputFile) {
        std::cerr << "Error: Could not read selected record.\n";
        return 1;
    }

    // Display record
    std::cout << "Roll Number: " << selectedStudent.rollNumber << '\n';
    std::cout << "Name: " << selectedStudent.name << '\n';
    std::cout << "Marks: " << selectedStudent.marks << '\n';

    return 0;  // End program
}