#include <fstream>    // File handling
#include <iostream>   // Input/output
#include <limits>     // numeric_limits
#include <sstream>    // String stream
#include <string>     // String

// Book class
class Book {

private:
    int bookId;
    std::string title;
    std::string author;
    bool issued;

public:

    // Constructor
    Book(int id, std::string bookTitle, std::string bookAuthor,
         bool issueStatus = false)
        : bookId(id),
          title(std::move(bookTitle)),
          author(std::move(bookAuthor)),
          issued(issueStatus) {}

    // Return book ID
    int getBookId() const {
        return bookId;
    }

    // Convert object to file record
    std::string toFileRecord() const {
        return std::to_string(bookId) + "|" +
               title + "|" +
               author + "|" +
               (issued ? "1" : "0");
    }

    // Display book details
    void display() const {
        std::cout << "Book ID: " << bookId << '\n';
        std::cout << "Title: " << title << '\n';
        std::cout << "Author: " << author << '\n';
        std::cout << "Status: "
                  << (issued ? "Issued" : "Available") << '\n';
    }
};

// Add a book
void addBook() {

    int id;
    std::string title;
    std::string author;

    // Take book ID
    std::cout << "Enter book ID: ";
    std::cin >> id;

    // Clear input buffer
    std::cin.ignore(
        std::numeric_limits<std::streamsize>::max(), '\n'
    );

    // Take title
    std::cout << "Enter title: ";
    std::getline(std::cin, title);

    // Take author
    std::cout << "Enter author: ";
    std::getline(std::cin, author);

    // Create book object
    Book book(id, title, author);

    // Open file in append mode
    std::ofstream outputFile(
        "library_books.txt", std::ios::app
    );

    // Check file
    if (!outputFile) {
        std::cerr << "Error: Could not open library_books.txt\n";
        return;
    }

    // Save book record
    outputFile << book.toFileRecord() << '\n';

    std::cout << "Book added successfully.\n";
}

// Display all books
void displayBooks() {

    // Open file
    std::ifstream inputFile("library_books.txt");

    // Check file
    if (!inputFile) {
        std::cout << "No library record file found.\n";
        return;
    }

    std::string line;

    // Read records
    while (std::getline(inputFile, line)) {

        // Split record
        std::stringstream record(line);

        std::string idText;
        std::string title;
        std::string author;
        std::string issuedText;

        // Read fields
        if (std::getline(record, idText, '|') &&
            std::getline(record, title, '|') &&
            std::getline(record, author, '|') &&
            std::getline(record, issuedText)) {

            // Create book object
            Book book(
                std::stoi(idText),
                title,
                author,
                issuedText == "1"
            );

            // Display book
            book.display();

            std::cout << "-------------------------\n";
        }
    }
}

int main() {

    int choice;

    // Menu loop
    do {

        std::cout << "\nLibrary Record System\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Display Books\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        // Perform selected operation
        switch (choice) {

            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 0:
                std::cout << "Exiting program.\n";
                break;

            default:
                std::cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;  // End program
}