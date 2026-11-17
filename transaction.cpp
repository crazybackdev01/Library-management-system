#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// These functions are implemented in the other CPP files.
bool bookExists(string id);
bool memberExists(string id);
void updateBookCopies(string bookID, int change);

// Each issue record is stored as:
// memberID|bookID

void issueBook() {
    string memberID, bookID;

    cout << "Enter member ID: ";
    getline(cin, memberID);

    if (!memberExists(memberID)) {
        cout << "Member does not exist. Register the member first.\n";
        return;
    }

    cout << "Enter book ID: ";
    getline(cin, bookID);

    if (!bookExists(bookID)) {
        cout << "Book does not exist.\n";
        return;
    }

    // Check whether the requested book has an available copy.
    ifstream bookFile("books.txt");
    string line;
    int availableCopies = 0;

    while (getline(bookFile, line)) {
        stringstream ss(line);
        string id, title, author, total, available;

        getline(ss, id, '|');
        getline(ss, title, '|');
        getline(ss, author, '|');
        getline(ss, total, '|');
        getline(ss, available, '|');

        if (id == bookID) {
            availableCopies = stoi(available);
            break;
        }
    }
    bookFile.close();

    if (availableCopies <= 0) {
        cout << "Sorry, no copies of this book are currently available.\n";
        return;
    }

    ofstream issueFile("issued.txt", ios::app);
    issueFile << memberID << "|" << bookID << "\n";
    issueFile.close();

    updateBookCopies(bookID, -1);
    cout << "Book issued successfully.\n";
}

void returnBook() {
    string memberID, bookID;

    cout << "Enter member ID: ";
    getline(cin, memberID);
    cout << "Enter book ID to return: ";
    getline(cin, bookID);

    ifstream input("issued.txt");
    ofstream output("issued_temp.txt");

    string line;
    bool returned = false;

    while (getline(input, line)) {
        stringstream ss(line);
        string storedMemberID, storedBookID;

        getline(ss, storedMemberID, '|');
        getline(ss, storedBookID, '|');

        if (!returned && storedMemberID == memberID && storedBookID == bookID) {
            returned = true;
            continue; // Do not copy this issue record to the new file.
        }

        output << line << "\n";
    }

    input.close();
    output.close();

    remove("issued.txt");
    rename("issued_temp.txt", "issued.txt");

    if (returned) {
        updateBookCopies(bookID, 1);
        cout << "Book returned successfully.\n";
    } else {
        cout << "No matching issued-book record was found.\n";
    }
}

void displayIssuedBooks() {
    ifstream file("issued.txt");
    string line;
    bool found = false;

    cout << "\n--------- CURRENTLY ISSUED BOOKS ---------\n";
    cout << "Member ID\tBook ID\n";

    while (getline(file, line)) {
        stringstream ss(line);
        string memberID, bookID;

        getline(ss, memberID, '|');
        getline(ss, bookID, '|');

        cout << memberID << "\t\t" << bookID << "\n";
        found = true;
    }

    if (!found) {
        cout << "No books are currently issued.\n";
    }
}