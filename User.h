// User.h
#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
using namespace std;

class User {
private:
    string username;
    string password;     // plain text — ok for learning assignment
    vector<string> borrowedBooks;  // list of ISBNs

public:
    User(const string& u, const string& p);

    string getUsername() const;
    bool checkPassword(const string& p) const;

    bool borrowBook(const string& isbn);
    bool returnBook(const string& isbn);
    const vector<string>& getBorrowedBooks() const;

    void displayBorrowed() const;
};

#endif
