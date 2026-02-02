// Book.h
#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;
class Book {
private:
	string title;
	string author;
	string isbn;
	bool available;
    string borrowedBy; // username who borrowed it(empty if available)
public:
	Book(const string& t, const string& a,const string& i);	
	string getTitle()const;
	string getAuthor()const;
	string getISBN()const;
	bool isAvailable()const;
	string getBorrowedBy()const;
	
	bool borrow(const string& user)	;
	void returnBook();
	
	void display()const;
}; 
#endif