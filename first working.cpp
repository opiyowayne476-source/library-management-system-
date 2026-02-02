// Book.cpp
#include "Book.h"
#include <iostream>
#include <iomanip>
uisng namespace std;

Book::Book(const string& t, const string& a, const string& i)
    : title(t), author(a), isbn(i), available(true), borrowedBy("") {}

string Book::getTitle()  const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN()   const { return isbn; }
bool Book::isAvailable()      const { return available; }
string Book::getBorrowedBy() const { return borrowedBy; }

bool Book::borrow(const string& user) {
    if (!available) return false;
    available = false;
    borrowedBy = user;
    return true;
}

void Book::returnBook() {
    available = true;
    borrowedBy = "";
}

void Book::display() const {
    cout << left << setw(30) << title
              << setw(25) << author
              << setw(18) << isbn
              << (available ? "Available" : "Borrowed by " + borrowedBy)
              << "\n";
}