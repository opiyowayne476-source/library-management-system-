// Library.h
#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "User.h"
#include <vector>
#include <string>
using namespace std
class Library {
private:
    vector<Book> books;
    vector<User> users;
    User* currentUser = nullptr;   // simple session

public:
    // Book operations
    void addBook(const string& title, const string& author, const string& isbn);
    bool removeBook(const string& isbn);
    Book* findBookByISBN(const string& isbn);
    void searchBooksByTitle(const string& title) const;
    void searchBooksByAuthor(const string& author) const;
    void displayAllBooks() const;

    // User operations
    bool registerUser(const string& username, const string& password);
    bool login(const string& username, const string& password);
    void logout();
    User* getCurrentUser();

    // Borrowing / Returning
    bool borrowBook(const std::string& isbn);
    bool returnBook(const std::string& isbn);

    // For testing
    size_t getBookCount() const { return books.size(); }
    size_t getUserCount() const { return users.size(); }
};

#endif
