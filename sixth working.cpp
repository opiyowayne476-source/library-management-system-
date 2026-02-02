#include "Library.h"
#include <iostream>
#include <string>

int main() {
    Library lib;

    // Some sample data
    lib.addBook("Antomy and Physciology", " Organic Matter","576-0321563123");
    lib.addBook("Atomic Habits", "Loice C. Loius", "978-0132890884");
    lib.registerUser("student1", "pass123");

    std::string input;
    while (true) {
        std::cout << "\n=== Library System ===\n";
        if (lib.getCurrentUser()) {
            std::cout << "Logged in as: " << lib.getCurrentUser()->getUsername() << "\n";
            std::cout << "1. Display all books\n2. Search by title\n3. Search by author\n";
            std::cout << "4. Borrow book (ISBN)\n5. Return book (ISBN)\n6. Show my borrowed books\n7. Logout\n0. Exit\n";
        } else {
            std::cout << "1. Login\n2. Register\n3. Display all books (guest)\n0. Exit\n";
        }
        std::cout << "Choice: ";
        std::getline(std::cin, input);

        if (input == "0") break;

        if (!lib.getCurrentUser()) {
            if (input == "1") {
                std::string u, p;
                std::cout << "Username: "; std::getline(std::cin, u);
                std::cout << "Password: "; std::getline(std::cin, p);
                if (lib.login(u, p)) std::cout << "Login successful!\n";
                else std::cout << "Login failed.\n";
            }
            else if (input == "2") {
                std::string u, p;
                std::cout << "New username: "; std::getline(std::cin, u);
                std::cout << "Password: "; std::getline(std::cin, p);
                if (lib.registerUser(u, p)) std::cout << "Registered!\n";
                else std::cout << "Username taken.\n";
            }
            else if (input == "3") lib.displayAllBooks();
        } else {
            // Logged-in menu
            if (input == "1") lib.displayAllBooks();
            else if (input == "2") {
                std::string t; std::cout << "Title keyword: "; std::getline(std::cin, t);
                lib.searchBooksByTitle(t);
            }
            else if (input == "3") {
                std::string a; std::cout << "Author keyword: "; std::getline(std::cin, a);
                lib.searchBooksByAuthor(a);
            }
            else if (input == "4") {
                std::string isbn; std::cout << "ISBN: "; std::getline(std::cin, isbn);
                if (lib.borrowBook(isbn)) std::cout << "Book borrowed!\n";
                else std::cout << "Cannot borrow.\n";
            }
            else if (input == "5") {
                std::string isbn; std::cout << "ISBN: "; std::getline(std::cin, isbn);
                if (lib.returnBook(isbn)) std::cout << "Book returned!\n";
                else std::cout << "Cannot return.\n";
            }
            else if (input == "6") lib.getCurrentUser()->displayBorrowed();
            else if (input == "7") { lib.logout(); std::cout << "Logged out.\n"; }
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}