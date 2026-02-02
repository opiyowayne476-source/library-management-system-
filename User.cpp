// User.cpp
#include "User.h"
#include <iostream>
using namespace std;

User::User(const string& u, const string& p)
    : username(u), password(p) {}

     string User::getUsername() const { return username; }

bool User::checkPassword(const string& p) const {
    return password == p;
}

bool User::borrowBook(const string& isbn) {
    // You can add max borrow limit here (e.g. 5 books)
    borrowedBooks.push_back(isbn);
    return true;
}

bool User::returnBook(const string& isbn) {
    for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
        if (*it == isbn) {
            borrowedBooks.erase(it);
            return true;
        }
    }
    return false;
}

const vector<string>& User::getBorrowedBooks() const {
    return borrowedBooks;
}

void User::displayBorrowed() const {
    if (borrowedBooks.empty()) {
        cout << "No books borrowed.\n";
        return;
    }
        cout << "Borrowed books (ISBNs): ";
    for (const auto& isbn : borrowedBooks) {
        cout << isbn << " ";
    }
        cout << "\n";
}
