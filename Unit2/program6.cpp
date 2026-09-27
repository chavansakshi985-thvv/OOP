#include <iostream>                 // Input/output

class Academic                       // Academic class
{
protected:
    int academicMarks;               // Academic marks

public:
    explicit Academic(int marks)
        : academicMarks(marks) {}    // Constructor

    void showAcademic() const        // Display academic marks
    {
        std::cout << "Academic Marks: " << academicMarks << '\n';
    }
};

class Sports                          // Sports class
{
protected:
    int sportsMarks;                 // Sports marks

public:
    explicit Sports(int marks)
        : sportsMarks(marks) {}       // Constructor

    void showSports() const          // Display sports marks
    {
        std::cout << "Sports Marks: " << sportsMarks << '\n';
    }
};

class Student : public Academic, public Sports // Multiple inheritance
{
public:
    Student(int academic, int sports)
        : Academic(academic), Sports(sports) {} // Constructors

    void showTotal() const            // Display total
    {
        std::cout << "Total Marks: "
                  << academicMarks + sportsMarks << '\n';
    }
};

int main()                            // Main function
{
    Student student(80, 15);          // Create Student object

    student.showAcademic();           // Show academic marks
    student.showSports();             // Show sports marks
    student.showTotal();              // Show total marks

    return 0;                         // End program
}