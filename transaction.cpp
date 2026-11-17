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

