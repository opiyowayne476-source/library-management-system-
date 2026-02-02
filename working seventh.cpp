// Example simple tests (you can expand with a framework like Catch2 or just manual)
#include"Library.h"
#include <iostream>
using namespace std;
void testLibrary() {
    Library lib;
    lib.addBook("Test Book", "Test Author", "12345");
    if (lib.getBookCount() != 1) cout << "Add book failed\n";

    if (lib.borrowBook("99999")) cout << "Borrow non-existing should fail\n";
    cout << "Manual tests passed (check output).\n";
}

int main() {
    testLibrary();
    // Add more: register → login → borrow → return → check availability
}