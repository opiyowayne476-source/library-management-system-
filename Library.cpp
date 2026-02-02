// Library.cpp
#include "Library.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Library::addBook(const string& t, const string& a, const string& i) {
    // Simple duplicate ISBN check
    if (findBookByISBN(i)) {
          cout << "Book with ISBN " << i << " already exists.\n";
        return;
    }
    books.emplace_back(t, a, i);
          cout << "Book added successfully.\n";
}

bool Library::removeBook(const string& isbn) {
    auto it = find_if(books.begin(), books.end(),
        [&isbn](const Book& b) { return b.getISBN() == isbn; });
    if (it != books.end()) {
        books.erase(it);
        return true;
    }
    return false;
}

Book* Library::findBookByISBN(const string& isbn) {
    auto it = find_if(books.begin(), books.end(),
        [&isbn](const Book& b) { return b.getISBN() == isbn; });
    return (it != books.end()) ? &(*it) : nullptr;
}

void Library::searchBooksByTitle(const string& title) const {
    bool found = false;
    for (const auto& book : books) {
        if (book.getTitle().find(title) != string::npos) {
            book.display();
            found = true;
        }
    }
    if (!found) cout << "No books found with title containing \"" << title << "\"\n";
}

void Library::searchBooksByAuthor(const string& author) const {
    // similar to search by title
    bool found = false;
    for (const auto& book : books) {
        if (book.getAuthor().find(author) != string::string::npos) {
            book.display();
            found = true;
        }
    }
    if (!found) cout << "No books found by author \"" << author << "\"\n";
}

void Library::displayAllBooks() const {
    if (books.empty()) {
        cout << "Library is empty.\n";
        return;
    }
    cout << "\nLibrary Catalog:\n";
    cout << left<< setw(30) << "Title"
              << setw(25) << "Author"
              << setw(18) << "ISBN"
              << "Status\n";
    for (const auto& b : books) b.display();
}

bool Library::registerUser(const string& u, const string& p) {
    for (const auto& user : users) {
        if (user.getUsername() == u) return false;
    }
    users.emplace_back(u, p);
    return true;
}

bool Library::login(const string& u, const string& p) {
    for (auto& user : users) {
        if (user.getUsername() == u && user.checkPassword(p)) {
            currentUser = &user;
            return true;
        }
    }
    return false;
}

void Library::logout() {
    currentUser = nullptr;
}

User* Library::getCurrentUser() {
    return currentUser;
}

bool Library::borrowBook(const string& isbn) {
    if (!currentUser) return false;
    Book* book = findBookByISBN(isbn);
    if (!book || !book->isAvailable()) return false;

    if (book->borrow(currentUser->getUsername())) {
        currentUser->borrowBook(isbn);
        return true;
    }
    return false;
}

bool Library::returnBook(const string& isbn) {
    if (!currentUser) return false;
    Book* book = findBookByISBN(isbn);
    if (!book || book->isAvailable()) return false;

    if (book->getBorrowedBy() == currentUser->getUsername()) {
        book->returnBook();
        currentUser->returnBook(isbn);
        return true;
    }
    return false;
}
